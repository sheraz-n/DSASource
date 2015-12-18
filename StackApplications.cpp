#include <iostream>
#define MAX_SIZE 10
using namespace std;

class StackAI {
    int A[MAX_SIZE];
    int top;
public:
    StackAI();
    bool isEmpty ();
    bool isFull ();
    bool push (int key);
    int pop ();
    int getSize ();
//    int top ();
    void printStack();
};

StackAI:: StackAI () { top = -1;}
bool StackAI::isEmpty () {return top == -1;}
bool StackAI::isFull  () {return top == MAX_SIZE-1 ;}
bool StackAI::push (int key) {if (isFull()) {cout<<"\nStack is Full"; return false;}
                               else {A[++top] = key; return true; }
 }
int StackAI::pop() { if (isEmpty()) {cout<<"\nStack is Empty, Nothing to Pop"; return -1;}
                    else {return A[top--];}
}
void StackAI::printStack(){ cout <<"\n"; for (int i=top; i>-1; i--) cout<<A[i]<<" "; }
int StackAI::getSize() {return MAX_SIZE ; }

void displayTowerStatus (StackAI *source, StackAI *Aux, StackAI *des)
{
cout<<"\n*************************";
cout<<" \nSource Tower :";
source->printStack();
cout<<" \nTemp Tower :";
Aux->printStack();
cout<<" \nDest Tower :";
des->printStack();
cout<<"\n*************************";
}

void towerOfHanoi (int disk, StackAI *source, StackAI *temp, StackAI * dest ){
    if (disk == 1)
        dest->push(source->pop());
    else{
        displayTowerStatus(source, temp, dest);
        towerOfHanoi(disk-1, source, dest, temp);
        displayTowerStatus(source,temp, dest);
        dest->push(source->pop());
        displayTowerStatus(source, temp, dest);
        towerOfHanoi(disk-1, temp, source,dest);
        displayTowerStatus(source,temp,dest);
    }

}

int main () {

    StackAI src;
    StackAI temp;
    StackAI dest;
    int nod = 2; // Number of disks
    cout<<"Number of Disks  : "<<nod;
//Source initialization
    for (int i=nod; i > 0; i--) src.push (i);
    towerOfHanoi(nod,&src, &temp ,&dest);
    return 0;
}
