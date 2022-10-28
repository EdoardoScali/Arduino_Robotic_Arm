
/*
  REALISED BY EDOARDO SCALI
  
  to understand servos and joysticks positions watch the arm photos 
 */


#include <Servo.h>

Servo servo1; //when the arm is vertically extended this is the bottom servomotor and so on
Servo servo2; 
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6; //when the arm is vertically extended this is the top servomotor, so the servomotor which opens and closes the claw


int x1_axis_degree = 100; //x1_axis is relative to servo1
int y1_axis_degree = 100; //y1_axis is relative to servo2
int x2_axis_degree = 100; //x2_axis is relative to servo3
int y2_axis_degree = 100; //y2_axis is relative to servo4
int x3_axis_degree = 100; //x3_axis is relative to servo5
int y3_axis_degree = 100; //y3_axis is relative to servo6



int joystick_x1 = A0; //joystick1 is the first on the opposite of the batteries, and so on -- x1 is the x axis of the 1th joystick, and so on
int joystick_y1 = A1; //y1 is the y axis of the 1th joystick, and so on
int joystick_x2 = A2; //joystick2 is in the middle 
int joystick_y2 = A3;
int joystick_x3 = A4; //joystick3 is near the batteries 
int joystick_y3 = A5;





void setup() {
  Serial.begin(9600);
  
  servo1.attach(2); //servo 1 is connected to digital pin 2, and so on
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  servo5.attach(6);
  servo6.attach(7);
}

void loop() {
  int joystick_x_value1 = analogRead(joystick_x1);
  int joystick_y_value1 = analogRead(joystick_y1);
  int joystick_x_value2 = analogRead(joystick_x2);
  int joystick_y_value2 = analogRead(joystick_y2);
  int joystick_x_value3 = analogRead(joystick_x3);
  int joystick_y_value3 = analogRead(joystick_y3);

  if(joystick_x_value1 < 340) x1_axis_degree -=3; //if the joystick_x_value1 is minor or ugual than 340 decrease 3 degrees
  else if(joystick_x_value1 > 680) x1_axis_degree +=3; //else increase 3 degrees

  if(joystick_y_value1 < 340) y1_axis_degree -=3;
  else if(joystick_y_value1 > 680) y1_axis_degree +=3;

  if(joystick_x_value2 < 340) x2_axis_degree +=3;
  else if(joystick_x_value2 > 680) x2_axis_degree -=3;

  if(joystick_y_value2 < 340) y2_axis_degree +=3;
  else if(joystick_y_value2 > 680) y2_axis_degree -=3;

  if(joystick_x_value3 < 340) x3_axis_degree -=3;
  else if(joystick_x_value3 > 680) x3_axis_degree +=3;

  if(joystick_y_value3 < 340) y3_axis_degree +=3;
  else if(joystick_y_value3 > 680) y3_axis_degree -=3;

  x1_axis_degree = min(179, max(20, x1_axis_degree)); //min and max degrees of servos, they depend on the assembly, please don't use mine, it's easy to search them with the serial monitor 
  y1_axis_degree = min(120, max(20, y1_axis_degree));
  x2_axis_degree = min(179, max(0, x2_axis_degree));
  y2_axis_degree = min(179, max(0, y2_axis_degree));
  x3_axis_degree = min(179, max(0, x3_axis_degree));
  y3_axis_degree = min(117, max(60, y3_axis_degree));


 

  Serial.print("x1_axis_degree : ");
  Serial.print(x1_axis_degree);
  Serial.print(", y1_axis_degree : ");
  Serial.print(y1_axis_degree);
  Serial.print(", x2_axis_degree 4 : ");
  Serial.print(x2_axis_degree);
  Serial.print(", y2_axis_degree : ");
  Serial.println(y2_axis_degree);
  Serial.print(", x3_axis_degree : ");
  Serial.println(x3_axis_degree);
  Serial.print(", y3_axis_degree : ");
  Serial.println(y3_axis_degree);
  
  servo1.write(x1_axis_degree); //set the servos degrees
  servo2.write(y1_axis_degree);
  servo3.write(x2_axis_degree);
  servo4.write(y2_axis_degree);
  servo5.write(x3_axis_degree);
  servo6.write(y3_axis_degree);
}
