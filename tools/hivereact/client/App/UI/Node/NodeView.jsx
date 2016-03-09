import React from "react";
import ReactDOM from "react-dom";
import Core from '../../Core';
import Node from './Node.jsx';
import Store from './Store.jsx';
import NodePlugView from "./NodePlugView.jsx";

/**
 * ノード(プラグ除く）を全て内包するビュー.
 */
export default class NodeView extends React.Component {
	constructor(props) {
		super(props);
		this.state = {
			nodes : this.props.store.getNodes(),
			zoom : this.props.nodeStore.getZoom(),
			globalOutHover : false,
			globalInHover : false
		};

		this.props.store.on(Core.Constants.NODE_COUNT_CHANGED, (err, data) => {
			this.setState({
				nodes : [].concat(this.props.store.getNodes())
			});
		});

		this.props.nodeStore.on(Store.ZOOM_CHANGED, (err, zoom) => {
			this.setState({
				zoom : zoom
			});
		});

		this.isLeftDown = false;
		this.isRightDown = false;
		this.isMiddleDown = false;
        this.focusTarget = null;

        this.componentDidMount = this.componentDidMount.bind(this);
		this.onNodeAdded = this.onNodeAdded.bind(this);
		this.width = 4000;
		this.height = 4000;

		this.onKeyDown = this.onKeyDown.bind(this);
		this.onKeyUp = this.onKeyUp.bind(this);

		this.copied = null;
		this.onCopy = this.onCopy.bind(this);
		this.onPaste = this.onPaste.bind(this);
		this.onDelete = this.onDelete.bind(this);

		this.connectToGlobalOut = this.connectToGlobalOut.bind(this);
		this.connectToGlobalIn = this.connectToGlobalIn.bind(this);
	}

	styles(id) {
		return {
			button : {
				position : "fixed",
				width : "100px",
				height : "20px",
				left : "300px",
				top : String(50 + id * 20) + "px",
				backgroundColor : "blue",
				color : "white"
			}
		};
	}

    // TO BE DELETED
	addButtonClick(id) {
		return () => {
			let offset = 1700;
			let ncount = Math.floor(Math.random() * 100000) + this.props.store.getNodes().length;
			if (id === 0) {
				let camera = this.props.store.nodeSystem.CreateNodeInstance('CreateCamera');
				let renderview = this.props.store.nodeSystem.CreateNodeInstance('RenderView');
				camera.varname = "testcamera_" + String(ncount);
				camera.node = {
					pos : [offset + 100, offset + 200]
				};
				renderview.varname = "testrenderview_" + String(ncount);
				renderview.node = {
					pos : [offset + 350, offset + 200]
				};

				this.props.action.addNode(camera);
				this.props.action.addNode(renderview);
				this.props.action.addPlug({
					output : {
						nodeVarname : camera.varname,
						name : camera.output[0].name
					},
					input : {
						nodeVarname : renderview.varname,
						name : renderview.input[9].name
					}
				});
			}
			if (id === 1) {
				let model = this.props.store.nodeSystem.CreateNodeInstance('PolygonObject');
				let teapot = this.props.store.nodeSystem.CreateNodeInstance('TeapotGenerator');
				let renderview = this.props.store.nodeSystem.CreateNodeInstance('RenderView');
				teapot.varname = "testteapot_" + String(ncount);
				teapot.node = {
					pos : [offset + 100, offset + 200]
				};
				model.varname = "testpolygonmodel_" + String(ncount);
				model.node = {
					pos : [offset + 350, offset + 200]
				};
				renderview.varname = "testrenderview_" + String(ncount);
				renderview.node = {
					pos : [offset + 550, offset + 400]
				};

				this.props.action.addNode(teapot);
				this.props.action.addNode(model);
				this.props.action.addNode(renderview);
				this.props.action.addPlug({
					output : {
						nodeVarname : teapot.varname,
						name : teapot.output[0].name
					},
					input : {
						nodeVarname : model.varname,
						name : model.input[0].name
					}
				});
				this.props.action.addPlug({
					output : {
						nodeVarname : model.varname,
						name : model.output[0].name
					},
					input : {
						nodeVarname : renderview.varname,
						name : renderview.input[10].array[0].name
					}
				});
			}
		};
	}

    // TO BE DELETED
	/// 追加ボタン(仮)
	addButton(id) {
		const styles = this.styles.bind(this)(id);
		return (<div style={styles.button}
					onClick={this.addButtonClick.bind(this)(id)}
				>
					Add Node
				</div>);
	}

	onMouseDown(ev) {
		if (ev.button === 0) {
			this.isLeftDown = true;
			this.pos = {
				x : ev.clientX - ev.currentTarget.getBoundingClientRect().left,
				y : ev.clientY - ev.currentTarget.getBoundingClientRect().top
			};
		} else if (ev.button === 1) {
			this.isMiddleDown = true;
			this.pos = {
				x : ev.clientX - ev.currentTarget.getBoundingClientRect().left,
				y : ev.clientY - ev.currentTarget.getBoundingClientRect().top
			};
		} else if (ev.button === 2) {
			this.isRightDown = true;
			this.pos = {
				x : ev.clientX - ev.currentTarget.getBoundingClientRect().left,
				y : ev.clientY - ev.currentTarget.getBoundingClientRect().top
			};
        }
	}

	onMouseMove(ev) {
		this.rect = ev.currentTarget.getBoundingClientRect();
		const px = ev.clientX - this.rect.left;
		const py = ev.clientY - this.rect.top;
		if (this.isMiddleDown || (this.isLeftDown && this.isRightDown)) {
            const dx = (px - this.pos.x);
            const dy = (py - this.pos.y);
			if (this.refs.viewport) {
				this.refs.viewport.scrollLeft = this.refs.viewport.scrollLeft - dx;
				this.refs.viewport.scrollTop = this.refs.viewport.scrollTop - dy;
			}
		} else if (this.isRightDown) {
            const dx = (px - this.pos.x);
            const dy = (py - this.pos.y);
            const mv = (dx + dy) * 0.005;
			let zoom = this.props.nodeStore.getZoom();
            zoom = zoom + mv;
            if (zoom <= 0.1) {
                zoom = 0.1;
            } else if (zoom >= 2.0) {
                zoom = 2.0;
            }
            this.props.nodeAction.changeZoom(zoom);
		}

		this.pos = {
			x : px,
			y : py
		};
	}

	onWheel(ev) {
		ev.preventDefault();
	}

	connectToGlobalIn(ev) {
		let globalIn = {
			data : {
				name : "GlobalInput",
				varname : "GlobalInput",
				type : "all"
			},
			isInput : true
		};
		this.props.nodeAction.selectPlugHole(globalIn);
	}

	connectToGlobalOut(ev) {
		let globalOut = {
			data : {
				name : "GlobalOutput",
				varname : "GlobalOutput",
				type : "all"
			},
			isInput : false
		};
		this.props.nodeAction.selectPlugHole(globalOut);
	}

	onMouseUp(ev) {
		const rect = this.refs.bound.getBoundingClientRect();
		if (ev.clientX < (rect.left + 20)) {
			this.connectToGlobalOut();
		}
		if (ev.clientX > (rect.right - 20)) {
			this.connectToGlobalIn();
		}

		if (ev.button == 2 && this.isRightDown) {
			this.isRightDown = false;
		}
		if (ev.button == 1 && this.isMiddleDown) {
			this.isMiddleDown = false;
		}
		if (ev.button == 0 && this.isLeftDown) {
			this.isLeftDown = false;
		}
	}

	onNodeAdded(err, data) {
		if (!err) {
			let initialpos = this.props.store.getInitialNodePosition();
			if (data.node.pos[0] === initialpos[0] && data.node.pos[1] === initialpos[1]) {
				let rect = this.refs.viewport.getBoundingClientRect();
				let width = rect.right - rect.left;
				let height = rect.bottom - rect.top;
				let n = JSON.parse(JSON.stringify(data.node));
				n.pos = [this.refs.viewport.scrollLeft + width / 2 - 200, this.refs.viewport.scrollTop + height / 2 - 200];
				if (n.pos[0] <= 0) { n.pos[0] = 200; }
				if (n.pos[1] <= 0) { n.pos[1] = 200; }
				if (n.pos[0] >= 4000) { n.pos[0] = 3800; }
				if (n.pos[1] >= 4000) { n.pos[1] = 3800; }
				setTimeout(() => {
					this.props.action.changeNode({
						varname : data.varname,
						node : n
					});
				}, 0);
			}
		}
	}

    componentDidMount(){
		window.addEventListener('mouseup', this.onMouseUp.bind(this));
		let rect = this.refs.viewport.getBoundingClientRect();
		this.width = rect.right - rect.left;
		this.height = rect.bottom - rect.top;

		this.refs.viewport.scrollTop = 1700;
		this.refs.viewport.scrollLeft = 1700;

		this.props.store.on(Core.Constants.NODE_ADDED, this.onNodeAdded);
		this.props.store.on(Core.Constants.PASTE_CALLED, this.onPaste);
		this.props.store.on(Core.Constants.COPY_CALLED, this.onCopy);
		this.props.store.on(Core.Constants.DELETE_CALLED, this.onDelete);
		window.addEventListener('keydown', this.onKeyDown);
		window.addEventListener('keyup', this.onKeyUp);
    }

    componentWillUnmount(){
		window.removeEventListener('mouseup', this.onMouseUp.bind(this));
		this.props.store.off(Core.Constants.NODE_ADDED, this.onNodeAdded);
		this.props.store.off(Core.Constants.PASTE_CALLED, this.onPaste);
		this.props.store.off(Core.Constants.COPY_CALLED, this.onCopy);
		this.props.store.off(Core.Constants.DELETE_CALLED, this.onDelete);
		window.removeEventListener('keydown', this.onKeyDown);
		window.removeEventListener('keyup', this.onKeyUp);
    }

	onKeyDown(ev) {
		if (ev.target && ev.target.tagName.toLowerCase() === "input") { return; }
		let rect = this.refs.bound.getBoundingClientRect();
		this.isCtrlDown = ev.ctrlKey;
		if (this.isCtrlDown && ev.keyCode === 67) { // "c"
			this.onCopy(null);
		}
		if (this.isCtrlDown && ev.keyCode === 86) { // "v"
			this.onPaste(null);
		}
		if (ev.keyCode === 46) { // delete
			this.onDelete(null);
		}
	}

	// メニューまたはショートカットで削除が呼ばれた
	onDelete(err) {
		if (!err) {
			let nodeList = this.props.store.getSelectedNodeList();
			setTimeout( () => {
				this.props.action.deleteNodes(nodeList);
			}, 0);
		}
	}

	// メニューまたはショートカットでコピーが呼ばれた
	onCopy(err) {
		if (!err) {
			let nodeList = this.props.store.getSelectedNodeList();
			this.copied = JSON.stringify(nodeList);
		}
	}

	// メニューまたはショートカットでペーストが呼ばれた
	onPaste(err) {
		let copyNodes = null;
		if (this.copied) {
			copyNodes = JSON.parse(this.copied);
			let diffPos = [0, 0];

			// ノードをペースト
			for (let i = 0; i < copyNodes.length; i = i + 1) {
				let node = copyNodes[i];
				if (i === 0) {
					diffPos[0] = this.refs.viewport.scrollLeft + this.pos.x - node.node.pos[0];
					diffPos[1] = this.refs.viewport.scrollTop + this.pos.y - node.node.pos[1];
				}
				copyNodes[i].node.pos[0] += diffPos[0];
				copyNodes[i].node.pos[1] += diffPos[1];
			}
			setTimeout(() => {
				this.props.action.pasteNodes(copyNodes);
			}, 0);
			this.copied = null;
		}
		console.log("pasteNode");
	}

	onKeyUp(ev) {
		this.isCtrlDown = ev.ctrlKey;
	}

	origin() {
		if (this.refs.viewport) {
			let rect = this.refs.viewport.getBoundingClientRect();
			let x = this.refs.viewport.scrollLeft + (rect.right - rect.left) / 2.0;
			let y = this.refs.viewport.scrollTop + (rect.bottom - rect.top) / 2.0;
			return String(x) + "px " + String(y) + "px";
		} else {
			return "0px 0px";
		}
	}

	nodeList() {
		let isSimple = false;//this.state.zoom <= 0.6;
		let nodeList = (this.state.nodes.map( (nodeData, key) => {
			return (<Node nodeVarname={nodeData.varname}
						store={this.props.store}
						action={this.props.action}
						nodeStore={this.props.nodeStore}
						nodeAction={this.props.nodeAction}
						key={nodeData.varname + key}
						id={nodeData.varname + key}
						isSimple={isSimple}
					></Node>);
		} ));
		return nodeList;
	}

	onGlobalInMouseUp(ev) {

	}

	onGlobalOutEnter(ev) {
		if (ev.button === 1 || ev.button === 2) { return; }
		this.setState({ globalOutHover : true });
		ev.target.style.cursor = "pointer";
	}

	onGlobalOutLeave(ev) {
		this.setState({ globalOutHover : false });
		ev.target.style.cursor = "default";
	}

	onGlobalInEnter(ev) {
		if (ev.button === 1 || ev.button === 2) { return; }

		let inRect = this.refs.globalIn.getBoundingClientRect();
		console.log(inRect, ev.clientX, ev.clientY);

		this.setState({ globalInHover : true });
		ev.target.style.cursor = "pointer";
	}

	onGlobalInLeave(ev) {
		this.setState({ globalInHover : false });
		ev.target.style.cursor = "default";
	}

	onNaviEnter(ev) {
		ev.target.style.fontWeight = "bold";
		ev.target.style.cursor = "pointer";
	}

	onNaviLeave(ev) {
		ev.target.style.fontWeight = "normal";
		ev.target.style.cursor = "default";
	}

	onNaviClick(varname) {
		return (ev) => {
			console.log("onNaviClick")
			this.props.action.digGroup(varname);
		}
	}

	/// ノードの階層ナビゲータ
	navigator() {
		let path = this.props.store.getNodePath();
		if (path.length === 0) { return; }
		let naviPath = [this.props.store.data.varname].concat(path);
		let navi = naviPath.map( (varname, index) => {
			let name = varname;
			if (index > 0) {
				name = this.props.store.findNode(this.props.store.data, varname).name;
			}
			return (<div style={{
						float : "left",
						top : "0px",
						left : "0px",
						height : "25px",
					}}
						key={varname + "_" + String(index)}
						onMouseEnter={this.onNaviEnter.bind(this)}
						onMouseLeave={this.onNaviLeave.bind(this)}
						onClick={this.onNaviClick.bind(this)(varname)}
					>
						{name} /
					</div>)
		});
		return navi;
	}

	render() {
		const styles = this.styles.bind(this)();
		return (
				<div
					ref="bound"
					onMouseDown={this.onMouseDown.bind(this)}
					onMouseMove={this.onMouseMove.bind(this)}
				>
					<div ref="globalIn"
						 style={{
							position : "absolute",
							width : "20px",
							height : "100%",
							left : "0px",
							top  : "50%",
							transform : "translateY(-50%)",
							backgroundColor : this.state.globalInHover ? "rgba(255, 255, 255, 0.2)" : "rgba(255, 255, 255, 0.1)"
						}}
					/>
					<div ref="globalOut"
						 style={{
							position : "absolute",
							width : "20px",
							height : "100%",
							right : "0px",
							top  : "50%",
							transform : "translateY(-50%)",
							backgroundColor : this.state.globalOutHover ? "rgba(255, 255, 255, 0.2)" : "rgba(255, 255, 255, 0.1)"
						}}
					/>
					<div
						style={{
							position : "absolute",
							width:"100%",
							height:"100%",
							overflow:"auto"
						}}
						ref="viewport"
						onWheel={this.onWheel.bind(this)}
					>
						<div
							style={{
								position : "absolute",
								width:"4000px",
								height:"4000px",
								//zoom: String(this.state.zoom)
								transform : "scale(" + this.state.zoom + ")",
								transformOrigin : this.origin.bind(this)(),
								border : "10px solid",
								borderColor : "gray"
							}}
							ref="view"
						>
							{this.nodeList.bind(this)()}
							<NodePlugView
								style={{zIndex:"1"}}
								store={this.props.store}
								action={this.props.action}
								nodeStore={this.props.nodeStore}
								nodeAction={this.props.nodeAction}
							/>
						</div>
					</div>
					<div ref="navigator"
						style={{
						   position : "absolute",
						   	marginLeft : "30px",
						   	width : "100%",
							heigth : "20px",
							top : "0px",
							left : "0px",
							color : "white"
						}}
					>
						{this.navigator.bind(this)()}
					</div>
				</div>
				);
	}
}

//{this.addButton.bind(this)(0)}
//{this.addButton.bind(this)(1)}
