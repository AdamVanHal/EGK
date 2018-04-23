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

class matrixScan {
private:
public:
  //array for debouncing/storing state
  int **matrixState;
  //values used to determine if a switch is on or off
  int debounceOn;
  int debounceOff;
  //Constructor
  matrixScan(int colCount, int rowCount, int colArr[], int rowArr[]);

  //scan matrix for state changes
  int scan();
};
