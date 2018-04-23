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
  {KEY_A, KEY_B},
  {},
  {},
  {},
  {},
  {},
  {},
  {},
  {},
  {}
};

void setup() {
}

void loop() {
  // put your main code here, to run repeatedly:
  matrix1.scan();
}



