#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <class Item>
class BTNode {
public:
    Item info;
    BTNode<Item> * left;
    BTNode<Item> * right;
    //BTNode (Item key){info = key; left = right = NULL;}
    BTNode (Item key){info = key; left = right = NULL;}

//friend class BTree<Item>;
//friend class BSTree<Item>;
};

template <class Item>
class BTree {
protected:
    BTNode<Item> * root;
    int nodeCount;
    void destroy (BTNode<Item> *);

  //  void destroy ();
public:
    BTree();
    void inorder (BTNode<Item> *);
    void preorder (BTNode<Item> *);
    void postorder (BTNode<Item> *);
    bool isEmpty (){if (this->left == NULL && this->right == NULL) return true; else return false;}
    int max (int x, int y) { return ( (x>y)? x : y);}

    void inorderTraversal() { cout<<endl; inorder (this->root);}
    void preorderTraversal() { cout<<endl; preorder (this->root);}
    void postorderTraversal() { cout<<endl; postorder (this->root);}
    ~BTree(){ if (root) {destroy (root); root = NULL;}   }

};

template <class Item>
BTree<Item> :: BTree () { nodeCount = 0; root = NULL;}

template <class Item>
void BTree<Item> :: inorder (BTNode<Item> * node){
    if (node){
        inorder(node->left);
        cout<<node->info <<" ";
        inorder (node->right);
        }
    }

template <class Item>
void BTree<Item> :: preorder (BTNode<Item> * node){
    if(node){
        cout<<node->info<<" ";
        preorder (node->left);
        preorder (node -> right);
    }
}
template <class Item>
void BTree<Item> :: postorder (BTNode<Item> * node){
    if (node){
    postorder(node->left);
    postorder (node->right);
    cout<< node->info<<" ";
    }
}

template <class Item>
void BTree<Item> :: destroy (BTNode<Item> * node){
    if (node != NULL){
    destroy(node->left);
    destroy (node->right);
    delete node;
    node = NULL;
    }
}

template <class Item>
class BSTree : public BTree<Item> //Inheritence
{
 public:
    bool searchNode (Item key);
    void insertNode (Item key);
    Item deleteNode  (Item key);
};

template <class Item>
void BSTree<Item> :: insertNode (Item key){
BTNode<Item> * newnode = new BTNode<Item>(key);	 //Create Node
if (this->root == NULL)				// Find the appropriate place
          this->root= newnode;
    else {
           BTNode<Item> *node = this->root;
           BTNode<Item> *previous = NULL;
     while (node != NULL) {
           if (key == node->info ) {cerr<<"\n Can Not duplicate,"<<key<<" already present in Binary Search Tree."<<endl; return ;}
           else if (key > node->info) { previous = node; node=node->right;}
           else {previous = node; node = node->left;}         }
if (key > previous->info ) {			 //Add the Node to the right Place
           previous->right = newnode;
           this->nodeCount++ ;      }
    else {  previous->left = newnode ;
            this->nodeCount++ ;
            }
        }
}

template <class Item>
bool BSTree<Item> :: searchNode (Item key) {
    bool found = false;
    if ( this->root == NULL){ cerr<<" \nEmpty BST, Can not continue ...."; return false;}
    else {
        BTNode<Item> * current = this->root;
        while (current != NULL && !found){
             if ( key == current->info ) found = true;
             else if ( key < current->info ) current = current->left;
             else  current = current->right;
        }
//        cout<<"\nValue at current : "<<current->info;
    }
    return found;
}
//There are four cases of deletion
//Case 1: Node is a leaf
//Case 2: Node has left subtree
//Case 3: Node has left subtree
//Case 4: Node has both Trees

template <class Item>
Item BSTree<Item> :: deleteNode (Item key){
    //Part one Search the Node containing item
    Item retval;
    bool found = false;
    bool left,right = false;
    if ( this->root == NULL){ cerr<<" \nEmpty BST, Can not continue ...."; return false;}
    else {
        BTNode<Item> * current = this->root;
        BTNode<Item> * parent = NULL;  // For tail pointing
        BTNode<Item> * temp = NULL; // For deletion
         BTNode<Item> * successor = NULL; //for case 4
        while (current != NULL && !found){
             if ( key == current->info ) {found = true; }
             //if left is on, it means current is left child of parent
             //if right is on, it means current is right child of parent
             else if ( key < current->info ) {parent = current; current = current->left; right = false; left = true;}
             else  {parent = current; current = current->right; right =true; left = false;}
        }
     int caseSelect = -1;
     if (current->left == NULL && current->right == NULL ) // leaf Node
         caseSelect = 0;
     else if (current->left != NULL && current->right == NULL) // Left Subtree Node
         caseSelect = 1;
     else if (current->left == NULL && current->right != NULL) // Right Subtree Node
         caseSelect = 2;
     else caseSelect = 3;                                       // Both subtree Node
  //      cout<<"\nValue at current : "<<current->info;
  // Current is pointing at the required value
  //Part two gracefully delete the Node from tree
        //Case 1: Leaf node
    switch (caseSelect){
        case 0:
            if (left) parent->left = NULL; else if (right) parent->right = NULL;
            temp=current;
            retval = temp->info;
            delete temp;
            current = NULL;
            break;
        case 1:             // only left subtree exists
            if (left)       // current is left subchild of predecessor
                parent -> left = current-> left;
            else            // current is right subchild of predecessor
                parent->right = current-> left;
            temp = current;
            retval = temp->info;
            delete temp;
            current = NULL;
            break;
        case 2:             // only left subtree exists
            if (left)       // current is left subchild of parent
                parent -> left = current-> right;
            else            // current is right subchild of parent
                parent->right = current-> right;
            temp = current;
            retval = temp->info;
            delete temp;
            current = NULL;
            break;
        case 3:
             // Calculate successor

             successor = current-> left;
             while (successor->right != NULL){
                   parent = successor;
                   successor = successor -> right;
             }
             retval = current->info;
             current->info = successor->info;
             parent->right = NULL;
             delete successor;
             break;
        default:
            cout<<"Something Weird has happened .";
            break;
     }
  }
  return retval;
}

int main (){

BSTree<int> * mystree = new BSTree<int>();
srand(time(NULL));
int r=0;
int chk = 45;
for (int i=1; i < 16; i++){
     r = rand()%99;
     mystree->insertNode(r);
     if (i==5) mystree->insertNode(chk);
}
mystree->inorderTraversal();
//mystree->preorderTraversal();
//mystree->postorderTraversal();
cout<<"\n Searching element : "<<chk;
cout<<"\n Found? : "<<mystree->searchNode(chk);
// /*
cout <<"\n Deleting element : "<<chk;
mystree->deleteNode (chk);
mystree->inorderTraversal();
// */
return 0;

}








