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

class IntSLList {
    IntSLLNode * head;
    IntSLLNode * tail;
public:
    IntSLList () { head = NULL; tail = NULL; cout<<"constructor called";}
    ~IntSLList ();
    bool isEmpty () { if (head == NULL) return true; else return false; }
    void addToHead (int);
    void addToTail (int);
    int deleteFromHead ();
    int deleteFromTail ();
    void deleteNode (int);
    bool isInList (int) const;
    void printList ();

};

IntSLList::~IntSLList(){
        cout<<"\nDestructor called";
    if (this->isEmpty()){return;}
    else {
        IntSLLNode * ptr;
        //Possible Bug in Destructor use while (head) instead following statement.
        while (head){ ptr = head; head = head->next; delete ptr;}
    }
}

void IntSLList::addToHead(int key){
    head = new IntSLLNode (key, head);
    if (tail == NULL ) tail = head;
}

void IntSLList::addToTail(int key) {
    if (tail!= NULL) { // List is not empty
        tail->next = new IntSLLNode (key);
        tail = tail->next;}
    else    //List is empty
        head = tail = new IntSLLNode (key); // The pointer will automatically be set to NULL due to constructor
    }
int IntSLList::deleteFromHead(){
    // Save the key value before deletion
    if (this->isEmpty ()) throw "Empty List encountered while deletion";
    int value = head->info;
    IntSLLNode * ptr = head;
    if (head == tail)
        head = tail = NULL;
    else
        head = head -> next;
    delete ptr;
    return value;
}
int IntSLList::deleteFromTail(){
    if (this->isEmpty ()) throw "Empty List encountered while deletion";
    int value = tail->info;
    if (head == tail ) {// Only one element in the list
        delete head;
        head=tail= NULL;
    }
    else{ // More than one elements in the List
        IntSLLNode * ptr = head;
        while (ptr->next != tail) ptr = ptr->next; //After this statement ptr is pointing element previous to tail
        delete tail;
        tail = ptr;
        tail->next = NULL;
        }
}
void IntSLList::deleteNode(int key){
        //Case1: List is empty
        if (this->isEmpty ()) throw "Empty List encountered while deletion";

        // Case 2: List has one element and its info == key
        if (head == tail && head->info == key) { delete head; head=tail= NULL;}
        else if (head->info == key){ // Case 3 At least two nodes and key is at head
            IntSLLNode * ptr = head;
            head = head->next;
            delete ptr;
        }
        else if (tail->info == key) {this->deleteFromTail();}
        else { //At least two nodes and key is not at head nor at tail
             IntSLLNode * ptr = head;
             IntSLLNode * prev = NULL;
             while (ptr->next != NULL || ptr->info != key){
                prev = ptr;
                ptr = ptr -> next;
             }
             if (ptr->info == key) {prev->next = ptr->next; delete ptr;}
             else cout<<"Key Not Found\n";
        }
}
void IntSLList::printList(){
    IntSLLNode * ptr = head;
    cout<<"\n";
    while (ptr) { cout <<" "<<ptr->info; ptr = ptr->next;}
}


int main (){

IntSLList mylist ;//= *(new IntSLList ());
for (int i=1; i< 10; i++)
mylist.addToHead(i*3);
//mylist.addToHead(23);
//mylist.addToHead(43);
//mylist.addToHead(8);
//mylist.addToHead(93);
mylist.printList();
mylist.deleteFromHead();
mylist.printList();
mylist.deleteFromTail();
mylist.printList();
int num= 5;
if (num==5){ IntSLList mylist3 ;}
cout<<"\nAfter 2nd object";

return 0 ;
}
