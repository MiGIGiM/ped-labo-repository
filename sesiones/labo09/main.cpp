#include <iostream>
using namespace std;

struct node {
  int data;
  node *left, *right;
};


// Binary Search Tree|| Arbol de busqueda binario
class BST {
  private:
    node *pBST;

  public:
    BST();
    ~BST();
    void insert(node **, int data);
    void getData();
    void print();
    void inorder(node *); // Inorder
    void preorder(node *); // Preorder
    void postorder(node *); // Postorder
};

BST::BST(){
  pBST = NULL;
}

void BST::insert(node **tree, int data){
  if(!*tree) {
    *tree = new node;
  } else {
    if (data < (*tree)->data) {
      insert(&(*tree)->left, data);
    } else {
      insert(&(*tree)->right, data);
    }
    }
};

void BST::print(){
  cout << "Inorder: ";
  inorder(pBST);

  cout << endl << "Preorder: ";
  preorder(pBST);

  cout << endl << "Postorder: ";
  postorder(pBST);

};

void BST::inorder(node *tree){
  if(tree) {
    inorder(tree->left); //left
    cout << tree->data << " "; //root
    inorder(tree->right); //right
  }
}

void BST::preorder(node *tree){
  if(tree) {
    cout << tree->data << " "; //root
    preorder(tree->left); //left
    preorder(tree->right); //right
  }
}

void BST::postorder(node *tree){
  if(tree) {
    postorder(tree->left); //left
    postorder(tree->right); //right
    cout << tree->data << " "; //root
  }
}

void BST::getData(){
  int data;

  while(cin>>data){
    insert(&pBST, data);
  }
}

int main () {
  BST bst;
  bst.getData();
  bst.print();
  return 0;
}


// Preorder

//  34
// /  \
//20     40
// \     / \
/15 21  nu  41

// 15 21 20 34 40 41