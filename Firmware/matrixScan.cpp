/*
   Matrix Scanning
   basic matrix scanning
   Started Feb 11 2018
   Adam Van Hal

   Feature List:
   Todo:
   Matrix scanning
   Keypress reporting

*/
#include "matrixScan.hpp"
#include "WProgram.h"

//Constructor
matrixScan::matrixScan(int colCount, int rowCount, int colArr[], int rowArr[]) {
  
  //array for debouncing/storing state
  //**matrixState = NULL;
  //values used to determine if a switch is on or off
  debounceOn = 5;
  debounceOff = -5;
  //set up driven pins
  for (int i = 0; i < colCount; i++) {
    pinMode(colArr[i], OUTPUT);
  }
  //setup read pins
  for (int i = 0; i < rowCount; i++) {
    pinMode(rowArr[i], INPUT_PULLUP);
  }

  //initialize matrix array for tracking state
  //    matrixState = new int[rowCount][7];
  //    for(int i=0;i<rowCount;i++){
  //      for(int j=0;j<colCount;j++){
  //        matrixState[i][j]=0;
  //      }
  //    }
}//end constructor

//scan matrix for state changes
int matrixScan::scan() {
  return 0;
}
