import cx from 'classnames';
import { Component } from 'react';

export default class TodoList extends Component {
   constructor(props) {
        super(props);
        this.state = {
            todo: [],
            inputText: "",
        };
     }
    setInputText(e) {
        this.setState({ inputText: e.target.value });
    }
    setTodo() {
        this.setState({
            todo: [...this.state.todo, { text: this.state.inputText, isDone: false }],
        });
    }
    setDone(index, text) {
        this.state.todo.splice(index, 1);
        this.setState({
            todo: [...this.state.todo, { text: this.state.inputText, isDone: true }],
        });
    }
    render() {
        return (
          <>
            <div>
              <h2>Todo List</h2>
              <input type="text" onChange={(e) => this.setInputText(e)} />
              <button onClick={() => this.setTodo()}>add</button>
              <h3>{this.state.todo.map((val) => {
                return val.isDone===false
              }).length} remaining out of {this.state.todo.length} tasks</h3>
              <ul>
                {this.state.todo.map((val, index) => (
                  <li
                    className={val.isDone ? "is-done" : ""}
                    key={index}
                    onClick={() => this.setDone(index, val.text)}
    
                  >
                    {val.text}
                  </li>
                ))}
              </ul>
            </div>
            <style>
              {`
                .is-done {
                    text-decoration: line-through;
                }
            `}
            </style>
          </>
        );
    }
}
