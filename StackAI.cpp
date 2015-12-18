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

int main () {

    StackAI myStack ;

    cout<<"\nSize of Stack :"<<myStack.getSize();

    for (int i=0; i < 11; i ++) myStack.push (i*3);
    myStack.printStack();

    int val;
    for (int i=0; i< 12; i++) { val = myStack.pop (); cout << "\nPopped Value : "<<val;}
    return 0;
}
