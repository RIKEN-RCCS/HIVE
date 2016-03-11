import ModuleEntry from './ModuleEntry.jsx';

import React from 'react';
import ReactDOM from "react-dom";
import Core from './Core';
import Hive from './HIVE';
import Node from "./UI/Node";
import Panel from "./UI/Panel";
import Menu from "./UI/Menu";
import MenuTop from "./UI/Menu/MenuTop.jsx";
import TimeSlider from "./UI/TimeSlider";
import Splitter from "./UI/Splitter";
import HoverNodeCreate from "./UI/Menu/HoverNodeCreate.jsx";
import Constants from "./Core/Constants.jsx"
import ConsoleOutput from "./UI/ConsoleOutput";


export default class HiveApp extends React.Component {
    constructor (props) {
        super(props);

        this.store = new Core.Store();
        this.action = new Core.Action(this.store.getDispatchToken());
        this.listVisiblity = false;

		this.nodeStore = new Node.Store(this.action.dispatcher, this.store);
		this.nodeAction = new Node.Action(this.action.dispatcher, this.nodeStore.getDispatchToken());

        this.state = {
            layoutType: 'all',
            consoleOutputVisible: false,
            listVisible: false,
            listPos: [window.innerWidth / 2, window.innerHeight / 2 - 150]
        };

        this.onDragOver = this.onDragOver.bind(this);
        this.onDrop = this.onDrop.bind(this);
        this.onClick = this.onClick.bind(this);
        this.onDblClick = this.onDblClick.bind(this);
        this.onKeyDown = this.onKeyDown.bind(this);
        this.componentDidMount = this.componentDidMount.bind(this);
        this.allClearNode = this.allClearNode.bind(this);
        this.loadFile = this.loadFile.bind(this);
        this.setFocusTarget = this.setFocusTarget.bind(this);
        this.hoverHidden = this.hoverHidden.bind(this);
        this.hoverGenerator = this.hoverGenerator.bind(this);
        this.setHoverPosition = this.setHoverPosition.bind(this);

        this.store.on(Constants.LAYOUT_CHANGED, (val) => {
            console.log('LAYOUT_CHANGED', val);

            this.setState({"layoutType": val});
        });
        this.store.on(Constants.CONSOLEOUTPUT_SHOW, (val) => {
            console.log('CONSOLEOUTPUT_SHOW', val);
            this.setState({"consoleOutputVisible": val});
        });
    }

    componentDidMount(){
        let e = ReactDOM.findDOMNode(this.refs.droptarget);
        e.addEventListener('dragover', this.onDragOver, false);
        e.addEventListener('drop', this.onDrop, false);
        e = ReactDOM.findDOMNode(this.refs.hoverTarget);
        e.addEventListener('click', this.onClick, false);
        e.addEventListener('dblclick', this.onDblClick, false);
        window.addEventListener('keydown', this.onKeyDown, false);
    }

    onDragOver(eve){
        eve.stopPropagation();
        eve.preventDefault();
    }

    onDrop(eve){
        eve.stopPropagation();
        eve.preventDefault();
        if(eve.dataTransfer.files && eve.dataTransfer.files.length > 0){
            this.loadFile(eve.dataTransfer.files[0]);
        }
        return false;
    }

    // キーダウンイベントのターゲットは Window
    onKeyDown(eve){
        switch(eve.keyCode){
            case 27:
                this.hoverHidden();
                break;
            case 32:
                eve.preventDefault();
                this.setState({
                    listVisible: true
                });
                setTimeout((()=>{
                    this.setHoverPosition();
                    var e = ReactDOM.findDOMNode(this.focusTarget.refs.suggest.input);
                    e.focus();
                }).bind(this), 50);
                break;
            default:
                break;
        }
    }

    onClick(eve) {
        if (eve.button === 0) {
            if (this.listVisiblity) {
                this.listVisiblity = false;
                this.setState({
                    listVisible: this.listVisiblity
                });
            }
        }
    }

    onDblClick(eve){
        if (eve.button === 0) {
            // let x = eve.currentTarget.scrollLeft + eve.clientX - eve.currentTarget.getBoundingClientRect().left;
            // let y = eve.currentTarget.scrollTop + eve.clientY - eve.currentTarget.getBoundingClientRect().top;
            let x = eve.pageX;
            let y = eve.pageY;
            this.listVisiblity = !this.listVisiblity;
            this.setState({
                listVisible: this.listVisiblity,
                listPos: [x, y]
            });
            if(this.listVisiblity){
                setTimeout((()=>{
                    var e = ReactDOM.findDOMNode(this.focusTarget.refs.suggest.input);
                    e.focus();
                }).bind(this), 50);
            }
        }
    }

    allClearNode(){
		this.action.clearAll();
    }

    loadFile(file){
        this.allClearNode();
        var reader = new FileReader();
        reader.onload = function(){
            let data = (JSON.parse(reader.result));
            if(data.nodes && data.nodes.length > 0){
                for(let i in data.nodes){
                    this.action.importNode(data.nodes[i]);
                }
            }else{
                console.log('import failed: nodes.length === 0');
            }
            if(data.plugs && data.plugs.length > 0){
                for(let i in data.plugs){
                    this.action.addPlug(data.plugs[i]);
                }
            }else{
                console.log('import failed: plugs.length === 0');
            }
        }.bind(this);
        reader.readAsText(file);
    }

    menu() {
        return this.state.isInitialized ? (<Menu.View store={this.store} action={this.action} />) : (<div />);
    }

    // ========================================================================
    // この関数をフォーカスしたい子要素に渡して呼んでもらう
    setFocusTarget(element){
        this.focusTarget = element;
    }

    hoverHidden(){
        this.listVisiblity = false;
        this.setState({listVisible: false});
    }

    setHoverPosition(){
        let el, pos, x, y, w, h;
        el = ReactDOM.findDOMNode(this.refs.hoverTarget);
        pos = el.getBoundingClientRect();
        w = el.clientWidth;
        h = el.clientHeight;
        x = w / 2 + pos.left - 100;
        y = h / 2 + pos.top - 150;
        this.setState({listPos: [x, y]});
    }

    hoverGenerator(){
        if (this.state.listVisible){
            return (
                <HoverNodeCreate
                    store={this.store}
                    action={this.action}
                    visibility={this.state.listVisible}
                    position={this.state.listPos}
                    focusFunction={this.setFocusTarget.bind(this)}
                    hiddenFunction={this.hoverHidden}
                    ref="creator"
                />
            );
        }
    }
    // ========================================================================

    render() {
        let layoutMode = 2;
        if (this.state.layoutType === "all") { layoutMode = 2 }
        else if (this.state.layoutType === "node") { layoutMode = 1 }
        else if (this.state.layoutType === "panel") { layoutMode = 0 }

        switch(layoutMode){
            case 2:
                return (
                    <div ref="droptarget">
                        <Splitter split="horizontal" secondPaneSize="150" lockSecondPane={true} dontmove={false} overflow2='hidden'>
                            <Splitter split="vertical" defaultSize="275" dontmove={true}>
                                <Menu.View store={this.store} action={this.action} layoutType={layoutMode} />
                                <Splitter split="vertical" minSize="50">
                                    <div ref="hoverTarget" style={{position:"absolute",width:"100%",height:"100%"}}>
                                        <Node.View store={this.store} action={this.action} nodeStore={this.nodeStore} nodeAction={this.nodeAction}  />
                                    </div>
                                    <div>
                                        <Panel.View store={this.store} action={this.action} />
                                    </div>
                                </Splitter>
                            </Splitter>
                            <TimeSlider.View store={this.store} action={this.action} />
                        </Splitter>
                        {this.hoverGenerator()}
                        <MenuTop store={this.store} action={this.action} consoleShow={this.state.consoleOutputVisible}/>
                        <ConsoleOutput store={this.store} show={this.state.consoleOutputVisible}/>
                    </div>
                );
                break;
            case 1:
                return (
                    <div ref="droptarget">
                        <Splitter split="horizontal" secondPaneSize="150" lockSecondPane={true} dontmove={false} overflow2='hidden'>
                            <Splitter split="vertical" defaultSize="275" dontmove={true}>
                                <Menu.View store={this.store} action={this.action} layoutType={layoutMode} />
                                <div ref="hoverTarget" style={{position:"absolute",width:"100%",height:"100%"}}>
                                    <Node.View store={this.store} action={this.action} nodeStore={this.nodeStore} nodeAction={this.nodeAction} />
                                </div>
                            </Splitter>
                            <TimeSlider.View store={this.store} action={this.action} />
                        </Splitter>
                        {this.hoverGenerator()}
                        <MenuTop store={this.store} action={this.action} consoleShow={this.state.consoleOutputVisible}/>
                        <ConsoleOutput store={this.store} show={this.state.consoleOutputVisible}/>
                    </div>
                );
                break;
            case 0:
            default:
                return (
                    <div ref="droptarget">
                        <Splitter split="horizontal" secondPaneSize="150" lockSecondPane={true} dontmove={false} overflow2='hidden'>
                            <Panel.View store={this.store} action={this.action} />
                            <TimeSlider.View store={this.store} action={this.action} />
                        </Splitter>
                        {this.hoverGenerator()}
                        <MenuTop store={this.store} action={this.action} consoleShow={this.state.consoleOutputVisible}/>
                        <ConsoleOutput store={this.store} show={this.state.consoleOutputVisible}/>
                    </div>
                );
                break;
        }
    }
}
