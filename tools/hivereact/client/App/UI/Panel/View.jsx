import React from "react"
import ReactDOM from "react-dom"
import Container from "./Container.jsx"
import Core from '../../Core'

export default class View extends React.Component {
    constructor(props) {
        super(props);

        this.store = props.store;
        this.action = props.action;
        this.state = {
            nodes: [].concat(this.store.getNodes()),
            position: {x: 0, y: 0}
        };

        this.styles = this.styles.bind(this);
        this.generator = this.generator.bind(this);

        this.props.store.on(Core.Store.NODE_CHANGED, function(err, data){
            this.setState({nodes: [].concat(this.store.getNodes())});
        }.bind(this));
        this.props.store.on(Core.Store.NODE_COUNT_CHANGED, function(err, data){
            this.setState({nodes: [].concat(this.store.getNodes())});
        }.bind(this));
    }

    styles() {
        return {
            container: {
                backgroundColor: "#333",
                margin : "0px",
                padding : "0px",
                minWidth : "300px",
                minHeight: "200px",
                overflow: "hidden",
                boxShadow : "0px 0px 3px 0px white inset"
            }
        }
    }

    generator(node, key) {
        var styles = this.styles();
        var res = React.createFactory(node.uiComponent.data)({node: node, store: this.store, action: this.action, key: key});
        return (
            <Container
                store={this.store}
                action={this.action}
                node={node}
                key={key}
                pos={this.pos}
            />
        );
    }

    render() {
        var styles = this.styles();
        var a = (
            <div style={styles.container}>
                {this.state.nodes.map((value, key)=>{
                    return this.generator(value, key);
                })}
            </div>
        );
        return a;
    }
}
