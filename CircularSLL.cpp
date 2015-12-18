#include <iostream>

using namespace std;

class IntSLLNode {

public:
IntSLLNode *next;
int info;
    IntSLLNode (){
        int info = 0;
        next = NULL;
    }
    IntSLLNode (int inf, IntSLLNode * ptr = 0) {
        info = inf;
        next = ptr;}
};

class IntCSLList {
    //IntSLLNode * head;
    IntSLLNode * tail;
    int index;
public:
    IntCSLList () { tail = NULL; index = 0;}
    ~IntCSLList ();
    bool isEmpty () { if (tail == NULL) return true; else return false; }
    void insert (int);
    void insertAtIndex (int,int);
    int deleteFromFront ();
//    void deleteNode (int);
//    bool isInList (int) const;
    void printList ();
};

void IntCSLList::insert (int key){
    if (index==0) { tail = new IntSLLNode (key, NULL); tail->next = tail; index++ ;}
    else { // Not empty
        IntSLLNode * ptr = new IntSLLNode (key, tail->next);
        tail->next = ptr;
        index++;
    }
}

void IntCSLList::insertAtIndex (int key, int providedind){
//    cout<<"\ncurrent index"<<index;
    if (providedind > index || providedind == 0){cout<<"\nProvided index Not in Range"; return;}
    else{
        IntSLLNode * ptr = tail;
        IntSLLNode * nn; //New Node
        for (int i=1; i<providedind; i++ ) ptr = ptr->next;

        nn = new IntSLLNode(key, ptr->next);
        ptr->next = nn;
        index++;
    }
}

void IntCSLList::printList(){
    if (index==0 ) {cout<<"List is empty\n "; return;}
    IntSLLNode * ptr = tail->next; //Head
    cout<<"\n";
    for (int i=0; i<index; i++) { cout <<" "<<ptr->info; ptr = ptr->next;}
}

IntCSLList::~IntCSLList(){
    if (index==0) return;
    else {
        IntSLLNode * ptr;
        for (int i=0; i<index; i++){ ptr = tail; tail = tail->next; delete ptr;}
    }}
int IntCSLList::deleteFromFront (){
    if (index == 0) return -1; // empty list
    else {
        IntSLLNode * ptr = tail->next;
        tail->next = ptr->next;
        int data = ptr->info;
        delete ptr;
        index--;
        return data;
    }
}

int main (){

IntCSLList mylist = *(new IntCSLList ());
for (int i=1; i< 8; i++)
mylist.insert (i*3);
//mylist.addToHead(23);
//mylist.addToHead(43);
//mylist.addToHead(8);
//mylist.addToHead(93);
//mylist.printList();

//mylist.deleteFromFront();
//mylist.printList();
//mylist.deleteFromFront();
//mylist.printList();
//mylist.deleteFromFront();
mylist.printList();
cout <<"\n Provided index:  1  Provided Number : 38";
mylist.insertAtIndex (38, 1);
mylist.printList();
cout <<"\n Provided index:  4  Provided Number : 54";
mylist.insertAtIndex (54, 4);
mylist.printList();
cout <<"\n Provided index:  3  Provided Number : 68";
mylist.insertAtIndex (68, 3);
mylist.printList();
cout <<"\n Provided index:  7  Provided Number : 71";
mylist.insertAtIndex (71, 7);


///*mylist.deleteFromTail();
mylist.printList();
//*/
return 0 ;
}

