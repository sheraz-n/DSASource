#include <iostream>
using namespace std;

class Heap {
int *data ; // Array to store data
int asize; //
int heapsize ;  // current
int getLeftChildIndex (int parentIndex){
    if (parentIndex > ((heapsize-1)/2 )) cerr<<"\n Child Not available for current Node ..";
    else return (2*parentIndex +1); }
int getRightChildIndex (int parentIndex){
    if (parentIndex > ((heapsize -1)/2 )) cerr<<"\n Child Not available for current Node ..";
    else return (2*parentIndex + 2); }
int getParentIndex (int childindex) {return (childindex-1)/2 ; }
void siftUp (int); //Will take index
void siftDown (int);
bool isEmpty (){ return (heapsize ==0) ;}

public:
Heap () { // Default size=10
         asize = 10; data = new int [asize]; heapsize = 0;  for (int i=0; i<asize; i++) *(data + i) = -1;}
void insertNode (int);
void initialize ();
void printHeap () { cout<<"*********** Heap ********************\n" ;
                    if(!isEmpty()) for (int i=0; i<heapsize ; i++) cout<<" "<<data[i] ;}
int deQueue();
int maxElement (int , int );
void exchange (int *x, int * y) { int tmp = *x ; *x= *y; *y = tmp;   }
~Heap () { delete data; }
};

int Heap:: maxElement (int a, int b) {return (a<b ?a:b) ;}
// Doesnot maintain heap property
void Heap::insertNode (int key){
    cout<<"\n Inserting element : "<<key;
 if (heapsize == asize)
       cerr<<"\nHeap's is Full, Can not enter more Data ...";
else {
      heapsize++;
      data[heapsize - 1] = key;
      siftUp(heapsize - 1);
      }
}

int Heap::deQueue (){
    int retval = -1 ;
    if (isEmpty()) { cerr<<" Tree is empty, can not proceed with dequeue ..." ;}
    else {
     retval = data[0];  // Return value at root
     data[0] = data[heapsize-1]; //dequeue the value
     //exchange (data[0], data[heapsize-1]);
     data[heapsize-1] = -1;  // init empty with -1;
     heapsize --;  // manage heapsize
     siftDown(0);  // hepify down
    }
    return retval;
}

void Heap::siftUp(int nodeIndex) {
      int parentIndex, tmp;
      if (nodeIndex != 0) {
            parentIndex = getParentIndex(nodeIndex);
            if (data[parentIndex] < data[nodeIndex]) {
                  exchange( &data[parentIndex], &data[nodeIndex]);
              //    tmp = data[parentIndex];
              //    data[parentIndex] = data[nodeIndex];
              //    data[nodeIndex] = tmp;
                  siftUp(parentIndex);
            }
      }
}


 /*
void Heap::siftDown(int nodeIndex){
    int leftchildIndex, rightchildIndex, maxChild;
     leftchildIndex = getLeftChildIndex(nodeIndex);
     rightchildIndex = getRightChildIndex(nodeIndex);


    //if ( data[nodeIndex] < data[leftchildIndex] || data[nodeIndex] < data[rightchildIndex]  ){
     if ( leftchildIndex < heapsize ){

  //       cout<<"\n Node index is : "<<nodeIndex<<" heapsize is : "<<heapsize;
   //      cout<<"\n Left Child index is : "<<leftchildIndex<<" Right Child Index is : "<<rightchildIndex;
               //tmp = maxElement(data[])
           if (data[nodeIndex] < data[leftchildIndex] ) {
                 maxChild= leftchildIndex
                 //exchange ( &data[nodeIndex] , &data[leftchildIndex]);
                 //siftDown (leftchildIndex);}

           else if (data[nodeIndex] < data[rightchildIndex] ) {
                 maxChild= leftchildIndex
                 //exchange ( &data[nodeIndex] , &data[leftchildIndex]);
                 //siftDown (rightchildIndex);}
                }
           //Do nothing if both are equal
           exchange ( &data[nodeIndex] , &data[maxChild]);
    }
 */

void Heap::initialize (){}

int main (){

Heap *myheap = new Heap ();

myheap->insertNode(16);
myheap->insertNode(26);
myheap->insertNode(36);
myheap->insertNode(15);
myheap->insertNode(6);
myheap->insertNode(46);
myheap->insertNode(115);
myheap->insertNode(64);
myheap->insertNode(25);
myheap->insertNode(116);
myheap->insertNode(86);

cout<<"\n";
myheap->printHeap();

cout<<"Removed Node is :" <<myheap->deQueue()<<endl;
myheap->printHeap();
return 0 ;
}
