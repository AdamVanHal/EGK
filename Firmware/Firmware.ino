/*
   Keyboard firmware
   basic firmware to control a usb keyboard
   Started Feb 11 2018
   Adam Van Hal

   Feature List:
   Todo:
   Matrix scanning
   Keypress reporting
   Layers
   Serial Comms
   Serial Interfacing
   Serial Pass through
   Additional IO reporting
   Serial Reprogramming
   Mouse Controls
*/
#include "matrixScan.hpp"

const int rows = 10;
const int cols = 10;
int rowPins[rows] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //read pins
int colPins[cols] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; //driven pins, normally 1, 0 to scan
matrixScan matrix1 = matrixScan(cols,rows,colPins,rowPins);

int keyMatrix1[rows][cols] = {//associates the keys in board with the scan matrix
  {KEY_1, KEY_2, KEY_3, KEY_1, KEY_2, KEY_3, KEY_1, KEY_2, KEY_3, KEY_3},
  {KEY_4, KEY_5, KEY_6, KEY_4, KEY_5, KEY_6, KEY_4, KEY_5, KEY_6, KEY_6},
  {KEY_7, KEY_8, KEY_9, KEY_7, KEY_8, KEY_9, KEY_7, KEY_8, KEY_9, KEY_9},
  {KEY_1, KEY_2, KEY_3, KEY_1, KEY_2, KEY_3, KEY_1, KEY_2, KEY_3, KEY_3},
  {KEY_4, KEY_5, KEY_6, KEY_4, KEY_5, KEY_6, KEY_4, KEY_5, KEY_6, KEY_6},
  {KEY_7, KEY_8, KEY_9, KEY_7, KEY_8, KEY_9, KEY_7, KEY_8, KEY_9, KEY_9},
  {KEY_1, KEY_2, KEY_3, KEY_1, KEY_2, KEY_3, KEY_1, KEY_2, KEY_3, KEY_3},
  {KEY_4, KEY_5, KEY_6, KEY_4, KEY_5, KEY_6, KEY_4, KEY_5, KEY_6, KEY_6},
  {KEY_7, KEY_8, KEY_9, KEY_7, KEY_8, KEY_9, KEY_7, KEY_8, KEY_9, KEY_9},
  {KEY_1, KEY_2, KEY_3, KEY_1, KEY_2, KEY_3, KEY_1, KEY_2, KEY_3, KEY_3}
};
//initialize array for tracking up/down state of keys to zeros
int keyTrack [rows][cols]={};

void setup() {
  Serial.begin(9600);
}

void loop() {
  //check matrix for key movements
  matrix1.scan();
  //read array status
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      //check if any new keys overcame debounce threshold
      if((keyTrack[i][j]==0)&&(matrix1.matrixState[i][j]==matrix1.debounceOn)){
        //Serial.println("Key Pressed");
        //set state of that key in tracking table
        keyTrack[i][j]=1;
        Keyboard.press(keyMatrix1[i][j]);
      }
      //check if previously pressed keys have been released
      if((keyTrack[i][j]==1)&&(matrix1.matrixState[i][j]==matrix1.debounceOff)){
        //set state to released
        keyTrack[i][j] = 0;
        Keyboard.release(keyMatrix1[i][j]);
        //Serial.println("Key released");
      }
    }
    //delay(100);
  }
}
