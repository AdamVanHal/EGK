/*
   Matrix Scanning
   basic matrix scanning
   Started Feb 11 2018
   Adam Van Hal

   Feature List:
   Todo:
   rewrite to activate key on press, then lockout during debounce period to improve response
 X Matrix scanning
 O Keypress reporting
   Destructor to free memory allocated by new

*/
#include "matrixScan.hpp"
#include "WProgram.h"

//Constructor
matrixScan::matrixScan(int colCountA, int rowCountA, int colArrA[], int rowArrA[]) {
  //save args
  colCount = colCountA;
  rowCount = rowCountA;
  colArr = new int[colCount];
  for(int i=0;i<colCount;i++){
    colArr[i]= colArrA[i];
  }
  rowArr = new int[rowCount];
  for(int i=0;i<rowCount;i++){
    rowArr[i]= rowArrA[i];
  }
  
  //array for debouncing/storing state
  //**matrixState = NULL;
  //values used to determine if a switch is on or off
  debounceOn = 5;
  debounceOff = -5;
  //set up drive pins
  for (int i = 0; i < colCount; i++) {
    pinMode(colArr[i], OUTPUT);
  }
  for (int i = 0; i < colCount; i++) {
    digitalWrite(colArr[i], HIGH);
  }
  //setup read pins
  //Pullup resistor so high means it is not driven, shorting to the drive pins drives it low when scanned
  for (int i = 0; i < rowCount; i++) {
    pinMode(rowArr[i], INPUT_PULLUP);
  }

  //initialize matrix array for tracking state
      //dynamically allocated, remove with delete
      matrixState = new int* [rowCount];
      for(int i=0;i<rowCount;i++){
        matrixState[i] = new int[colCount];
        for(int j=0;j<colCount;j++){
          matrixState[i][j]=0;
        }
      }
}//end constructor

matrixScan::~matrixScan(){
  delete[] colArr;
  delete[] rowArr;
  delete[] matrixState;
}

//scan matrix for state changes
int matrixScan::scan() {
  //set column pins low one at a time and read in the rows one at a time
  for (int i = 0; i < colCount; i++) {
    digitalWrite(colArr[i], LOW);
    for (int j = 0; j < rowCount; j++) {
      if(!digitalRead(rowArr[j])){
        matrixState[i][j]= matrixState[i][j]+ 1;
      }else{
        matrixState[i][j]=matrixState[i][j]-1;
      }
      if(matrixState[i][j] >= debounceOn){
        matrixState[i][j] = debounceOn;
      }
      if(matrixState[i][j] <= debounceOff){
        matrixState[i][j] = debounceOff;
      }
    }
    digitalWrite(colArr[i], HIGH);
  }
  return 0;
}
