#include <iostream>
#define MAX_SIZE 14

using namespace std;

class QueueAI {
  int head,tail;
  int Array [MAX_SIZE] ;
  int NoM ; // Number of Members
  public:
  QueueAI();
  ~QueueAI();
  bool enQueue (int key)    ;
  int deQueue ();
  bool isEmpty ();
  bool isFull ();
  void printQueue ();

};

QueueAI ::QueueAI (){ head=tail = -1; NoM=0;}
QueueAI ::~QueueAI () {}

bool QueueAI::isEmpty () { if (NoM==0) return true; else return false;}
bool QueueAI::isFull () { //return ((tail+1)%MAX_SIZE == head);
                            return (NoM == MAX_SIZE-1);}

bool QueueAI::enQueue (int key) {
    if ( isEmpty()) { //cout<<"atEnq0 ";
                      Array[0] = key; head =tail=0;NoM++; return true;}
    else if (isFull()){//cout<<"atEnq1";
                       cout <<"\n Queue is Full";
                       return false;}
    else { //cout<<"atEnq2 tail = "<<tail;
        tail = (tail+1) % MAX_SIZE;
        ++NoM;
        Array[tail] = key;
        return true;}
}
int QueueAI::deQueue (){ //cout<<"at deq";
    if (isEmpty()) {//cout<<"atDeq0";
                    cout<<"\n Queue is Empty" ; return -1;}
    else if (NoM == 1){
                   // cout<<"atDeq1";
                    int temp = tail;
                    head = tail = -1;
                    NoM=0;
                    return Array[temp];}
    else { //cout<<"atDeq2";
         int temp = head;
         head = (head+1)% MAX_SIZE;
      //   cout<<"Head : "<<head;
         --NoM;
         return Array[temp];
    }
}
void QueueAI::printQueue (){
        int headtemp = head;
        int tailtemp = tail;
        cout<<endl;
    for (;headtemp%MAX_SIZE != tailtemp; headtemp ++)
         cout <<"  "<<Array[headtemp];
  }

int main (){
QueueAI myqueue ;
for (int i= 0; i < 12; i++)
    myqueue.enQueue (i*4);

myqueue.printQueue ();

int val = 0;
for (int i=0; i<14; i++){
        val = myqueue.deQueue ();
        cout<<"\nDequeued value :"<< val;
        myqueue.printQueue ();
}

return 0;

}


