import React from "react"
import ReactDOM from "react-dom"
import Core from '../../../Core'

/**
 * ノードプロパティアイテム(TextInput)ビュー.
 */
export default class ItemTextInput extends React.Component {
	constructor(props) {
		super(props);
	}

	styles() {
		return {
			view : {
				width : "250px",
				backgroundColor : "#aeaeae",
				color : "black",
				display : "table-row"
			},
			key : {
				backgroundColor : "#ccc",
				width : "85px",
				display: "table-cell"
			},
			value : {
				width : "158px",
				display: "table-cell"
			}
		}
	}

	componentDidMount() {
		let input = ReactDOM.findDOMNode(this.refs.text);
		input.value = this.props.initialParam.value;
	}

	onKeyUp(ev) {
		console.log(ev.target.value);
		this.props.changeFunc(this.props.initialParam.name, ev.target.value);
	}

	render () {
		const styles = this.styles.bind(this)();
		return (<div style={styles.view}>
					<div style={styles.key}>
						{this.props.initialParam.name}
					</div>
					<input style={styles.value}
						type="text"
						ref="text"
						onKeyUp={this.onKeyUp.bind(this)}
					></input>
				</div>);
	}
}
