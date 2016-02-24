import React from "react"
import ReactDOM from "react-dom"
import Core from '../../Core'
import Node from './Node.jsx'
import Store from './Store.jsx'

/**
 * ノード(プラグ除く）を全て内包するビュー.
 */
export default class NodeView extends React.Component {
	constructor(props) {
		super(props);
		this.nodeList = this.props.store.getNodes();

		this.state = {
			nodes : this.props.store.getNodes()
		};
		this.props.store.on(Core.Store.NODE_COUNT_CHANGED, (err, data) => {
			this.setState({
				nodes : [].concat(this.props.store.getNodes())
			});
		});
		//this.moveNode = this.moveNode.bind(this);
	}

	styles() {
		return {
			button : {
				position : "absolute",
				width : "100px",
				height : "20px",
				left : "0px",
				top : "0px",
				backgroundColor : "blue",
				color : "white"
			}
		}
	}

	/*
	/// 選択中のすべてのノードを動かす.
	moveNode(err, data) {
		let selectedNodes = [];
		for (let i = 0, size = this.props.store.getNodes().length; i < size; i = i + 1) {
			let node = this.props.store.getNodes()[i];
			if (node.select) {
				// マウスダウン時のoffsetLeft/offsetTopに足し込む.
				let offset = this.props.nodeStore.getNodeOffset(node.varname);
				if (offset) {
					node.pos = [offset.offsetLeft + data.x, offset.offsetTop + data.y];
					selectedNodes.push(node);
				}
			}
		}
		console.log("changeNodes", selectedNodes);
		this.props.action.changeNodes(selectedNodes);
	}

	componentDidMount() {
		this.props.nodeStore.on(Store.NODE_MOVED, this.moveNode);
	}

	componentWillUnmount() {
		this.props.nodeStore.removeListener(Store.NODE_MOVED, this.moveNode);
	}
	*/

	addButtonClick() {
        let nodes = this.props.store.getNodes();
		let node = this.props.nodeSystem.CreateNodeInstance('CreateCamera');

		// create unique varname
		for (let i = 0; true; i = i + 1) {
			let foundSameName = false;
			let name = node.varname + "_" + String(i);
			for (let i = 0; i < this.state.nodes.length; i = i + 1) {
				if (this.state.nodes[i].varname === name) {
					foundSameName = true;
					break;
				}
			}
			if (!foundSameName) {
				node.varname = name;
				break;
			}
		}
		node.pos = [ 200, 200 ];

        // insert position
        let x, y;
        x = node.panel.pos[0];
        y = node.panel.pos[1];
        for(let i in nodes){
            let panel = nodes[i].panel;
            while(true){
                let f = true;
                if(Math.abs(x - panel.pos[0]) < 50){x += 50; f = false;}
                if(Math.abs(y - panel.pos[1]) < 50){y += 50; f = false;}
                if(f){break;}
            }
        }
        node.panel.pos = [x, y];

		this.props.action.addNode(node);

		// create plug test
		console.log("this.state.nodes.length", this.state.nodes.length );
		if (this.props.store.getNodes().length > 1) {
			this.props.action.addPlug({ output : {
				nodeVarname : this.state.nodes[0].varname,
				name : this.state.nodes[0].output[0].name
			}, input : {
				nodeVarname : node.varname,
				name : node.input[2].name
			}});
		}

		console.log("Add Node:", node.varname);

	}

	/// 追加ボタン(仮)
	addButton() {
		const styles = this.styles.bind(this)();
		return (<div style={styles.button}
					onClick={this.addButtonClick.bind(this)}
				>
					Add Node
				</div>);
		}

	render() {
		const styles = this.styles.bind(this)();
		let nodeList = (this.state.nodes.map( (nodeData, key) => {
			return (<Node node={nodeData}
			 			store={this.props.store}
						action={this.props.action}
						nodeStore={this.props.nodeStore}
						nodeAction={this.props.nodeAction}
			 			nodeSystem={this.props.nodeSystem}
						key={nodeData.varname + key}
					></Node>);
		} ));
		return (
				<div>
					{nodeList}
					{this.addButton.bind(this)()}
				</div>
				);
	}
}
