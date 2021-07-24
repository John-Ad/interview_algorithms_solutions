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

    void preOrder(TNode* node); // root, left, right
    void inOrder(TNode* node);  // left, root, right

    int depth(TNode* node);

    TNode* getRoot();
};