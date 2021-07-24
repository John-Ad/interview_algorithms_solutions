#include "Trees.h"

Tree::Tree(int* arr, int n)
{
    root = new TNode();

    populateLevelOrder(arr, n);
}

void Tree::populateLevelOrder(int* arr, int n)
{
    /*
     * As new nodes are created, they are added to a list in the order in which they are populated (left first then right)
     * The list is looped through and the first node encountered with an open space (left or right) will be populated
     * Once a node is full, it is removed from the list
     * */

    if (n <= 0)
        return;

    root->elem = arr[0];

    vector<TNode*> nodeArr; // stores each node as its added. Makes it easier to traverse tree to add new nodes
    nodeArr.push_back(root);

    for (int i = 1; i < n; i++) {
        TNode* node = new TNode(arr[i]);

        for (int e = 0; e < nodeArr.size(); e++) {
            if (nodeArr[e]->left != NULL && nodeArr[e]->right != NULL) { // if node is full, remove it
                nodeArr.erase(nodeArr.begin() + e);
                e--;
            } else {
                if (nodeArr[e]->left == NULL) {
                    nodeArr[e]->left = node;
                } else {
                    nodeArr[e]->right = node;
                }
                nodeArr.push_back(node); // push new node to back of list
                e = nodeArr.size();
                cout << "node added:" << node->elem << endl;
            }
        }
    }
}

void Tree::preOrder(TNode* node)
{
    if (node == NULL)
        return;

    cout << node->elem << endl;
    preOrder(node->left);
    preOrder(node->right);
}
void Tree::inOrder(TNode* node)
{
    if (node == NULL)
        return;

    inOrder(node->left);
    cout << node->elem << endl;
    inOrder(node->right);
}

int Tree::depth(TNode* node) // each level in tree adds 1
{
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;

    int dLeft = depth(node->left);
    int dRight = depth(node->right);

    return (1 + max(dLeft, dRight));
}

TNode* Tree::getRoot()
{
    return root;
}
