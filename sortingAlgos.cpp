#include <iostream>
using namespace std;

void selectionSort (int A[], int size);
void swap (int *num1, int *num2);
void printArray (int A [], int size);
//void bubleSort (int [], int size);
void insertionSort (int [], int size);

int main (){

int MyArray [] = {10,3,17,4,15,8,4,12,100,2,900,400,300,104,89,78};

int asize = sizeof(MyArray)/sizeof(MyArray[0]);
cout<< " Unsorted Array\n ";
printArray(MyArray, asize);
cout<<" \nSorting Process \n";
//swap (MyArray [0], MyArray [2]);
//printArray(MyArray,asize );
//selectionSort (MyArray, asize);
insertionSort (MyArray, asize);
printArray(MyArray, asize);

return 0;
}

void swap (int *num1, int* num2){ int temp = *num1; *num1 = *num2; *num2= temp;}

void printArray (int A [], int size) { cout <<"\n"; for (int i=0; i< size; i++) cout<< A[i]<<" "; }

void selectionSort (int A[], int size){
        cout<<"\n******** Selection Sort Algorithm *********** ";
        int minIndex = 0;
        for (int element = 0; element < size; element ++){
              minIndex = element;
             for (int index = element; index < size; index ++) {
                  if (A[minIndex] > A [index] )  minIndex = index;
                  }
             swap (A[minIndex], A[element]);
        printArray ( A, size);
        }
}
void insertionSort (int A[], int size){
    cout<<"\n******** Insertion Sort Algorithm *********** ";
    int FO, location = 0;
    int temp;
    for (FO =1; FO < size; FO++){
         if (A[FO] < A[FO-1] ){
             location = FO;
             temp = A[FO];
             do{
                A [location] = A[location -1];
                location --;
                }
             while (location > 0 && A[location - 1] > temp );
              }
          A[location] = temp;
          printArray(A,size);
        }
}
