import { useState } from 'react'

function Square() {
  const a = 10;
  function callOnClick() {
  }

  return <button className="square" onClick={callOnClick}></button> ;
}

function Form({size, setWidth, setHeight, onSubmit}){
  function handleSubmit(){
    setWidth(parseInt(document.getElementsByName("width")[0].value));
    setHeight(parseInt(document.getElementsByName("height")[0].value));
    onSubmit();
  }
  return (
    <form>
      <input type="number" placeholder='Width' name="width"/> <br></br>
      <input type="number"placeholder='Height' name="height"/> <br></br>
      <input type='button' value="submit" onClick={() =>handleSubmit()}/>
    </form>
  );
}

export default function Board() {
  const [width, setWidth] = useState(3); // [state, setState
  const [height, setHeight] = useState(3); // [state, setState
  const [square, setSquare] = useState(Array(width*height).fill(null));
  let size = {width: width, height: height};

  function onSubmit(){
    console.log(width, height);
  }
  return (
    <>
      <Form  size={size} setHeight={setHeight} setWidth={setWidth} onSubmit={onSubmit} name={"1"}/>
      {[...Array(height)].map((_, i) => ( /* This is like for loop*/
          <div className="board-row">
            {[...Array(width)].map((_, j) => (
              <Square key={i*width+j}  />
            ))}
          </div>
        ))
      }
    </>
  );
}
