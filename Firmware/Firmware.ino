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
class matrixScan {
  public:
  //array for debouncing/storing state
  int **matrixState = NULL;
  //values used to determine if a switch is on or off
  int debounceOn = 5;
  int debounceOff = -5;
  //Constructor
  matrixScan(int colCount, int rowCount, int colArr[], int rowArr[]) {
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
  void scan(){
    
  }
};
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



