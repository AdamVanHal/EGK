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

const int rows = 3;
const int cols = 3;
int rowPins[rows] = {1, 2, 3}; //read pins
int colPins[cols] = {4, 5, 6}; //driven pins, normally 1, 0 to scan
matrixScan matrix1 = matrixScan(cols,rows,colPins,rowPins);

int keyMatrix1[rows][cols] = {//associates the keys in board with the scan matrix
  {KEY_1, KEY_2, KEY_3},
  {KEY_4, KEY_5, KEY_6},
  {KEY_7, KEY_8, KEY_9}
};

void setup() {
}

void loop() {
  // put your main code here, to run repeatedly:
  matrix1.scan();
}
