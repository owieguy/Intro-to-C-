/*********************************************************
* Summary: This code detects if the matrix is square or not
*
* Author: Owen Burns
* Created: 09/28/23
*
********************************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {
   //Define and initialize needed variables
   int size;
   cin >> size;
   int value;

   int array[size][size];
   int row[size];
   int column[size];
   int diag[2];

   bool tfRow = true;
   bool tfColumn = true;
   bool tfNums = true;
   bool tfDiag = true;
   bool square = false;

   int sumDiag1 = 0;
   int sumDiag2 = 0;
   int sumNums = 0;
    
   //Loads the values from the input into the array
   for (int i = 0; i < size; ++i){
      for (int j = 0; j < size; ++j) {
         cin >> value;
         array[i][j] = value;
      }
   }
   
   //Creates variables to check if 
   //the sums and the rows and columns all add to the same number
   for (int i = 0; i < size; ++i){
      int sumRow = 0;
      int sumColumn = 0;
      for (int j = 0; j < size; ++j) {
         sumRow += array[i][j];
         sumColumn += array[j][i];
      }
      row[i] = sumRow;
      column[i] = sumColumn;
   }
   
   //Creates variables to check if 
   //the sums and the diagonals add to the same number
   int j = size;
   for (int i = 0; i < size; ++i) {
      j -= 1;
      sumDiag1 += array[i][i];
      sumDiag2 += array[i][j];
   }

   //Creates variables to check if 
   //all the numbers are used 
   for (int k = 0; k < size*size; ++k) {
      for (int i = 0; i < size; ++i){
         for (int j = 0; j < size; ++j) {
            if ((array[i][j] == k + 1) && (sumNums < k + 1)) {
               sumNums += 1;
            }
         }
      }
   }

   //Uses the information above to assign true and false values
   //true represents the condition is met
   for (int i = 1; i < size; ++i) {
      if (row[i] != row[i - 1]) {
         tfRow = false;
      }
      if (column[i] != column[i - 1]) {
         tfColumn = false;
      }
      if (sumDiag1 != sumDiag2) {
         tfDiag = false;
      }
   }
      if (sumNums != size*size) {
         tfNums = false;
      }
      if ( tfRow && tfColumn && tfDiag && tfNums) {
         if ((row[0] == column[0]) && (row[0] == sumDiag1)){
         square = true;
      }
   }

   //Prints statements based on the boolian values found above
   cout <<"sum of numbers = " << sumNums << endl;
   if (!tfNums) {
      cout << "Not all expected numbers are present" << endl;
      return 0;
   }
   if (!tfRow) {
      cout << "Row sums differ" << endl;
      return 0;
   }
   if (!tfColumn) {
      cout << "Column sums differ" << endl;
      return 0;
   }
   if (!tfDiag) {
      cout << "Diagonal sums differ" << endl;
      return 0;
   }
   if (square) {
      cout << "The given matrix is a magic square" << endl;
      return 0;
   }
return 0;
}