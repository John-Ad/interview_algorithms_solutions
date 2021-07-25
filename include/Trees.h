#include "include.h"

struct TNode {
    int elem;
    TNode* left;
    TNode* right;

    TNode()
    {
        this->left = NULL;
        this->right = NULL;
    }

    TNode(int elem)
    {
        this->elem = elem;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree {
private:
    TNode* root;

public:
    Tree(int* arr, int n);
    void populateLevelOrder(int* arr, int n);

    void preOrder(TNode* node);  // root, left, right
    void inOrder(TNode* node);   // left, root, right
    void postOrder(TNode* node); // left, right, root
    void breadthFirst();         // level by level starting at root

    int depth(TNode* node); // returns max depth
    int breadth();          // returns max breadth

    TNode* getRoot();
};
