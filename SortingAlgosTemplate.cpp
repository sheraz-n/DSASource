#include <iostream>
#include <vector>
using namespace std;

template <class T>
void swap (T* x, T* y){T temp = *x; *x = *y; *y= temp;}
void bubleSort(vector<int>& );
void selectionSort (int [], int );
//void selectionSort ( vector<int>&, int);
//void swap (int *num1, int *num2);
void printArray (int [], int );
void printArray (vector<int>&);
//void bubleSort (int [], int size);
void quickSort (vector<int> &, int , int);
int Qpartition (vector<int> &, int, int);

void insertionSort (int [], int );

int main (){

//int MyArray [] = {10,3,17,4,15,8,4,12,100,2,900,400,300,104,89,78};
//int arr[]= {6,10,13,5,8,3,2,25,4,11,17,15,7};
int arr1[]= {45,82,25,94,50,60,78,32,92};
int arr[]= {11,2,15,1,17,6,9,8,3,5,14 };
//vector<int> A( Arr, 13 );

//int arr[] = {10,20,30};
vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
//cout<<"\nTesting of First and Last : " << int (vec.begin()) << " "<<int (vec.end());
//int asize = sizeof(MyArray)/sizeof(MyArray[0]);
cout<< " Unsorted Array with size = "<<vec.size()<<endl;
printArray(vec);
//cout<<"\n*********************Quick Sort*****************\n";
//cout<<" \nSorting Process \n";
//quickSort(vec,0,vec.size());
bubleSort(vec);
//cout<<" \nSorted Array\n";
printArray(vec);
//swap (MyArray [0], MyArray [2]);
//printArray(MyArray,asize );
//selectionSort (MyArray, asize);
//insertionSort (MyArray, asize);
//printArray(MyArray, asize);

return 0;
}


void swap (int *num1, int* num2){ int temp = *num1; *num1 = *num2; *num2= temp;}
void printArray (int A [], int size) { cout <<"\n"; for (int i=0; i< size; i++) cout<< A[i]<<" "; }
void printArray(vector<int> & v){ for( vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
                        std::cout << *i << ' '; cout<<endl;}

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
    //FO is the First Ordered
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
void bubleSort(vector<int>& Ve)
{
   cout<<"\n******** Bubble Sort Algorithm *********** "<<endl;
   bool sorted = false;
   int last = (Ve.size()-1);
   for (int i = 0; (i < last) && !sorted; i++){
      printArray(Ve);
      sorted = true;
      for (int j=last; j > i; j--)
         if (Ve.at(j-1) > Ve.at(j))
             { swap(Ve[j],Ve[j-1]);  sorted = false; }// signal exchange
    }
    printArray(Ve);
}

void quickSort(vector<int> & vec, int first, int last) {
// First and Last indices
int r;
int p = first;
int q = last;
if (p < q) { //More than One elements are in List
    r = Qpartition (vec, p,q);
   // cout<<"\nSelected Pivot: "<<vec[r]<<endl;
    printArray(vec);
    quickSort (vec, p, r);
    quickSort (vec, r+1, q);
}
}
/*/Find and return the index of pivot element.
 * @param Vec - The array.
 * @param first - The start of the sequence.
 * @param last - The end of the sequence.
 * @return - the pivot element/ */
int Qpartition (vector<int> & vec, int first, int last) {
   // printArray(vec);
    //cout<<endl ;
    int pivot = vec[first];
    int p = first;
    for (int i= p+1; i< last; i++)
        {
           if (vec[i] <= pivot) { p++ ; swap(vec[i],vec[p]); }
    }
    swap (vec[p], vec[first]);
    return p;
}
