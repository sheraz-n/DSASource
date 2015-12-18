#include <iostream>

using namespace std;

class IntDLLNode {
public:
IntDLLNode *next;
IntDLLNode *prev;
int info;
    IntDLLNode (){
        int info = 0;
        next = prev = NULL;
    }
    IntDLLNode (int inf, IntDLLNode * n = 0, IntDLLNode * p = 0) {
        info = inf;
        next = n;
        prev = p;
        }
};

class IntDLList {
    IntDLLNode * head;
    IntDLLNode * tail;
    int index ;
public:
    IntDLList (){head = tail = NULL; index=0;}
    void printList();
    void printListFromTail();
    bool isEmpty (){if (head == NULL) return true; else return false;}
    void insertAtHead (int);
    void insertAtTail (int);
    int deleteFromHead ();
    int deleteFromTail ();
    int isInList (int); //Return index of element if it exists

    ~IntDLList();
};

void IntDLList::insertAtHead(int key){
    //Cases 1: List is empty
   if (head == NULL) {
        tail = head = new IntDLLNode (key,head,NULL); index ++;
   }
   //List is not empty, assigned Node is the first Node
   else
   {
       IntDLLNode *node = new IntDLLNode (key, head, NULL);
       head -> prev = node;
       head = node;
       index ++ ;
    }
   }

void IntDLList::insertAtTail (int key){
    if (head == NULL) {
        tail = head = new IntDLLNode (key,head,NULL); index ++;
   }
   else{
        IntDLLNode *node = new IntDLLNode (key, NULL, tail);
        tail -> next = node;
        tail = node;
        index++;
       }
   }

int IntDLList::deleteFromHead ()
{
    if (this->isEmpty ()) throw "Empty List encountered while deletion";
    int value = head->info;
    IntDLLNode * ptr = head;
    if (head == tail){ // List with only one element
        head = tail = NULL;
     }
     else {
        head = head->next;
        head -> prev = NULL;
        }
      delete ptr;
      index--;
      return value;
}
int IntDLList::deleteFromTail ()
    {
    if (this->isEmpty ()) throw "Empty List encountered while deletion";
    int value = tail->info;
    IntDLLNode * ptr = tail;
    if (head == tail){ // List with only one element
        head = tail = NULL;
     }
    else{
        tail = tail ->prev;
        tail->next = NULL;
        }
    delete ptr;
    index--;
    return value;
}
IntDLList::~IntDLList (){
    if (this->isEmpty()){return;} // empty List
    IntDLLNode *ptr;
    while (head){ ptr = head; head = head->next; delete ptr;}
}

void IntDLList::printList(){
    IntDLLNode * ptr = head;
    cout<<"\n";
    while (ptr) { cout <<" "<<ptr->info; ptr = ptr->next;}
}

void IntDLList::printListFromTail(){
    IntDLLNode * ptr = tail;
    cout<<"\n";
    while (ptr) { cout <<" "<<ptr->info; ptr = ptr->prev;}
}
int IntDLList:: isInList (int key){
    IntDLLNode * ptr = head;
    bool found = false;
    int valueAtIndex = 0;
    for (int i=1; i<=index; i++){
        if (ptr->info == key){ valueAtIndex = i; found=true; break;}
        ptr= ptr->next;
    }
    if (found) return valueAtIndex;
    else return -1;
}

int main (){

IntDLList mylist ;//= *(new IntSLList ());
for (int i=1; i< 10; i++)
mylist.insertAtHead(i*5);
//mylist.addToHead(23);
//mylist.addToHead(43);
//mylist.addToHead(8);
//mylist.addToHead(93);
cout<<"\n Traversal From Head";
mylist.printList();
cout<<"\n Traversal From Tail";
mylist.printListFromTail();
cout<<endl;
cout<<"\n Insertion at Tail";
for (int i=1; i< 4; i++)
mylist.insertAtTail(i*4);
mylist.printList();
mylist.deleteFromHead();
cout<<"\n Deletion at Head";
mylist.printList();
cout<<"\n Deletion at Tail";
mylist.deleteFromTail();
mylist.printList();
//int num= 5;
//if (num==5){ IntSLList mylist3 ;}
//cout<<"\nAfter 2nd object";
cout<<"\n Location of 25 in List : "<<mylist.isInList(25);
cout<<"\n Location of 8 in List : "<<mylist.isInList(8);
cout<<"\n Location of 100 in List : "<<mylist.isInList(100);
return 0 ;
}
