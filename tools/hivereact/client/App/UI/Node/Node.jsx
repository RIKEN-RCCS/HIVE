import React from "react"
import ReactDOM from "react-dom"
import NodeInOut from "./NodeInOut.jsx"

/**
 * ノード.
 */
export default class Node extends React.Component {
	constructor(props) {
		super(props);
		this.isLeftDown = false;
		this.mousePos = { x : 0, y : 0};
		this.state = {
			pos : this.props.node.pos
		};
		this.componentDidMount = this.componentDidMount.bind(this);
		this.componentWillUnmount = this.componentWillUnmount.bind(this);
		this.onMouseMove = this.onMouseMove.bind(this);
		this.onMouseUp = this.onMouseUp.bind(this);
		this.onMouseDown = this.onMouseDown.bind(this);
		this.styles = this.styles.bind(this);
	}

	styles() {
		return {
			node : {
				position : "absolute",
				left : String(this.state.pos[0]),
				top : String(this.state.pos[1]),
				width : "200px",
				height : String((Math.max(this.props.node.input.length, this.props.node.output.length) + 1) * 18 + 10),
				backgroundColor : "rgb(66, 69, 66)",
				color : "white",
				padding : "5px"
			},
			title : {
				color : "rgb(239, 136, 21)",
				fontSize : "16px"
			}
		}
	}

	componentDidMount() {
		window.addEventListener('mousemove', this.onMouseMove);
		window.addEventListener('mouseup', this.onMouseUp);
	}

	componentWillUnmount() {
		window.removeEventListener('mousemove', this.onMouseMove);
		window.removeEventListener('mouseup', this.onMouseUp);
	}

	onMouseDown(ev) {
		if (ev.button === 0) {
			this.isLeftDown = true;
			this.mousePos = { x : ev.clientX, y : ev.clientY };
			this.offsetLeft = ev.currentTarget.offsetLeft;
			this.offsetTop = ev.currentTarget.offsetTop;
		}
	}

	onMouseUp(ev) {
		this.isLeftDown = false;
	}

	onMouseMove(ev) {
		if (this.isLeftDown) {
			// マウスダウン位置からの差分移動量.
			let mv = { x : ev.clientX - this.mousePos.x, y : ev.clientY - this.mousePos.y };
			// マウスダウン時のoffsetLeft/offsetTopに足し込む.
			this.setState({ pos : [this.offsetLeft + mv.x, this.offsetTop + mv.y] })
		}
	}

	/// タイトル.
	titleElem() {
		const styles = this.styles();
		return <div style={styles.title}>{this.props.node.name}</div>
	}

	/// 入力端子.
	inputElem() {
		let inputs = this.props.node.input.map( (inputData, key) => {
			return (<NodeInOut isInput={true} data={inputData} key={key} index={key} />)
		});
		return (<div>{inputs}</div>);
	}

	/// 出力端子.
	outputElem() {
		let outputs = this.props.node.output.map( (outputData, key) => {
			return (<NodeInOut isInput={false} data={outputData} key={key} index={key} />)
		});
		return (<div>{outputs}</div>);
	}

	render () {
		const styles = this.styles();
		return (<div style={styles.node}
					ref="node"
					onMouseDown={this.onMouseDown.bind(this)}
				>
					{this.titleElem.bind(this)()}
					{this.inputElem.bind(this)()}
					{this.outputElem.bind(this)()}
				</div>);
	}
}
