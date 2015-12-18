#include <iostream>
using namespace std;

int main() {

// This programs practice using arrays as pointers

int size = 5;
//int a[size];
int * arr ;


//initialization using pointer
/*
for (int i=0; i<size; i++) {
    *(a + i) = i;
    cout<< a[i]<<"\n";
}
*/
//User defined array size and its initialization
cout <<"Enter array size : ";
cin>>size;

arr = new int[size];

for (int i=0; i<size; i++) {
    *(arr + i) = 2*i;
    //arr[i] = 2*i;
    cout<< *(arr + i)<<"\n";
}

//cout <<"Elements : "<< a ;

//delete [] arr;
return 0;
}
