[@bs.val] external eval: string => string = "eval";

[@react.component]
let make = () => {
  let (expression, setExpression) = React.useState(() => "");

  let addToExpression = c => {
    setExpression(expression => expression ++ c);
  };

  let resetExpression = () => setExpression(_currentExpression => "");

  let evaluateExpression = () => {
    // let evalJs = [%bs.raw
    //   {| function(expression) { return eval(expression.replace(/x/g, "*")); } |}
    // ];
    // valid expression regex (to be tested :D) /\d+([x-/+]\d+)*/
    setExpression(expression =>
      eval(expression |> String.map(c => c == 'x' ? '*' : c))
    );
  };

  <div className="calculator">
    <div className="calculator__display"> expression->React.string </div>
    <div className="calculator__buttons">
      <div className="buttons-container">
        <div className="digit" onClick={_ => addToExpression("7")}>
          "7"->React.string
        </div>
        <div className="digit" onClick={_ => addToExpression("8")}>
          "8"->React.string
        </div>
        <div className="digit" onClick={_ => addToExpression("9")}>
          "9"->React.string
        </div>
        <div className="operator" onClick={_ => addToExpression("/")}>
          "/"->React.string
        </div>
      </div>
      <div className="buttons-container">
        <div className="digit" onClick={_ => addToExpression("4")}>
          "4"->React.string
        </div>
        <div className="digit" onClick={_ => addToExpression("5")}>
          "5"->React.string
        </div>
        <div className="digit" onClick={_ => addToExpression("6")}>
          "6"->React.string
        </div>
        <div className="operator" onClick={_ => addToExpression("x")}>
          "x"->React.string
        </div>
      </div>
      <div className="buttons-container">
        <div className="digit" onClick={_ => addToExpression("1")}>
          "1"->React.string
        </div>
        <div className="digit" onClick={_ => addToExpression("2")}>
          "2"->React.string
        </div>
        <div className="digit" onClick={_ => addToExpression("3")}>
          "3"->React.string
        </div>
        <div className="operator" onClick={_ => addToExpression("-")}>
          "-"->React.string
        </div>
      </div>
      <div className="buttons-container">
        <div className="digit" onClick={_ => addToExpression("0")}>
          "0"->React.string
        </div>
        <div className="digit" onClick={_ => resetExpression()}>
          "AC"->React.string
        </div>
        <div className="digit" onClick={_ => evaluateExpression()}>
          "="->React.string
        </div>
        <div className="operator" onClick={_ => addToExpression("+")}>
          "+"->React.string
        </div>
      </div>
    </div>
  </div>;
};
