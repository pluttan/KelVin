let fl = 0;
let pole1_flag = false;
let pole2_flag = false;
let txt1="";
let txt2="";
let x_pole1=230;
let y_pole1=1;
let x_pole2=380;
let y_pole2=20;
let value=0;

function setup(){
    createCanvas(750, 110);
}
function draw(){
    background(200);
  drawpole1();
  drawpole2();
    fl++;
    print_txt();
}
function keyPressed() {
    key_pole1();
    key_pole2();
}
function mouseClicked() {
    hover_mouse1();
    hover_mouse2();
}

//--------------------------------------------------//

function drawpole1(){
    textSize(20);
    text("Введите длину ленты:", 10, y_pole1+18);
    fill(255);
    rect(x_pole1, y_pole1, 100, 20, 28);
    fill(0);
    if (txt1.length>7) {
        txt1=txt1.substring(0, 7);
    }
    if (pole1_flag){
        drawcur1(); 
    }
    text(txt1, x_pole1+10, y_pole1+17);
}
function drawcur1(){
    if (fl>20)line(x_pole1+10+txt1.length*11, y_pole1, x_pole1+10+txt1.length*11, y_pole1+20);
    if (fl>40)fl=0;
}
function key_pole1(){
    if (pole1_flag){
        if(int(key)===1){txt1=txt1+"1";};
        if(int(key)===2){txt1=txt1+"2";};
        if(int(key)===3){txt1=txt1+"3";};
        if(int(key)===4){txt1=txt1+"4";};
        if(int(key)===5){txt1=txt1+"5";};
        if(int(key)===6){txt1=txt1+"6";};
        if(int(key)===7){txt1=txt1+"7";};
        if(int(key)===8){txt1=txt1+"8";};
        if(int(key)===9){txt1=txt1+"9";};
        if(int(key)===0){if(txt1.length>0){txt1=txt1+"0";};};
        if(key==="Backspace"){if(txt1.length>0){txt1=txt1.substring(0,txt1.length-1);};};
    }
}
function hover_mouse1(){
    if (mouseX>x_pole1){
      if (mouseX<x_pole1+100){
          if (mouseY>y_pole1) {
              if (mouseY<y_pole1+20) {pole1_flag=true;}
              else {pole1_flag=false;}
          }
          else {pole1_flag=false;}
      }
      else {pole1_flag=false;}
  }
  else {pole1_flag=false;}
}
function drawpole2(){
    textSize(20);
    fill(255);
    rect(x_pole2, y_pole2, 100, 20, 28);
    fill(0);
    text("Введите кол-во светодиодов на метр:", 10, y_pole2+18);
    if (txt2.length>7) {
        txt2=txt2.substring(0, 7);
    }
    if (pole2_flag){
        drawcur2(); 
    }
    text(txt2, x_pole2+10, y_pole2+17);
}
function drawcur2(){
    if (fl>20)line(x_pole2+10+txt2.length*11, y_pole2, x_pole2+10+txt2.length*11, y_pole2+20);
    if (fl>40)fl=0;
}
function key_pole2(){
    if (pole2_flag===true){
        if(int(key)===1){txt2=txt2+"1";};
        if(int(key)===2){txt2=txt2+"2";};
        if(int(key)===3){txt2=txt2+"3";};
        if(int(key)===4){txt2=txt2+"4";};
        if(int(key)===5){txt2=txt2+"5";};
        if(int(key)===6){txt2=txt2+"6";};
        if(int(key)===7){txt2=txt2+"7";};
        if(int(key)===8){txt2=txt2+"8";};
        if(int(key)===9){txt2=txt2+"9";};
        if(int(key)===0){if(txt2.length>0){txt2=txt2+"0";};};
        if(key==="Backspace"){if(txt2.length>0){txt2=txt2.substring(0,txt2.length-1);};};
        print(int(key));
    }
}
function hover_mouse2(){
    if (mouseX>x_pole2){
      if (mouseX<x_pole2+100){
          if (mouseY>y_pole2) {
              if (mouseY<y_pole2+20) {pole2_flag=true;}
              else {pole2_flag=false;}
          }
          else {pole2_flag=false;}
      }
      else {pole2_flag=false;}
  }
  else {pole2_flag=false;}
}
function print_txt(){
    fill(0);
    if (int(txt1)>0){
        if (int(txt2)>0){
            text("Минимальное значение необходимой силы тока(А): "+str(int(int(txt1)*int(txt2)*0.036)), 10, y_pole1+60);
            text("Минимальное значение необходимой мощности(Вт): "+str(int(int(txt1)*int(txt2)*0.036*5)), 10, y_pole1+80);
            fill(255,0,0);
            if (int(txt1)>5)text("Для каждого отрезка длиной в 5м необходимо провести отдельный провод", 10, y_pole1+100);
            fill(0);
        }
    }
}
