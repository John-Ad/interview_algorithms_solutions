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
void Tree::postOrder(TNode* node)
{
    if (node == NULL)
        return;

    postOrder(node->left);
    postOrder(node->right);
    cout << node->elem << endl;
}
void Tree::breadthFirst()
{
    vector<TNode*> arr;
    TNode* currNode;

    arr.push_back(root);

    while (arr.size() > 0) {
        currNode = arr[0]; // get front of array

        cout << currNode->elem << endl;

        if (currNode->left != NULL)
            arr.push_back(currNode->left); // push to back of array
        if (currNode->right != NULL)
            arr.push_back(currNode->right);

        arr.erase(arr.begin()); // remove from front of array
    }
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
int Tree::breadth()
{
    /*
     * Starting at root, for each level push child nodes into a new seperate array and repeat until an empty array is created
     * eg root has 2 child nodes. These nodes are in their own array. The children of all the nodes in this array 
     * are placed in another seperate array. The sizes of the arrays are compared to find the max number of nodes in 
     * an array which indicates the breadth at that level.
     * 
     *                                  1
     *                              2       3
     *                            4   5   6   7
     *              -> arr1[1], arr2[2,3], arr3[4,5,6,7] 
     *              -> arr3 has most nodes and breadth is therefore size of arr3 which is 4 
     * */

    vector<vector<TNode*>> arr;      // 2d array to store nodes at each level
    arr.push_back(vector<TNode*>()); // create new arr for root level
    arr[0].push_back(root);          // add root to its arr

    int currIndex = 0; // index of current arr
    int max = 1;       // stores max value // set to 1 to represent root level breadth

    while (true) {
        arr.push_back(vector<TNode*>());     // add new arr for next level of nodes
        for (TNode* node : arr[currIndex]) { // for each node in current arr, push child nodes to the newly created array
            if (node->left != NULL)
                arr[currIndex + 1].push_back(node->left);
            if (node->right != NULL)
                arr[currIndex + 1].push_back(node->right);
        }

        currIndex++;
        if (arr[currIndex].size() > max) // compare size of newly created arr to current max
            max = arr[currIndex].size();

        if (arr[currIndex].size() == 0) // if newly created array is empty, end of tree has been reached
            break;
    }

    return max;
}

int Tree::convertToSumTree(TNode* node)
{
    if (node == NULL) // return 0 if null
        return 0;
    if (node->left == NULL && node->right == NULL) // if no children, return nodes value
        return node->elem;

    // get sum of left and right subtrees
    int sum1 = convertToSumTree(node->left);
    int sum2 = convertToSumTree(node->right);

    // set node value to sum of right and left subtrees
    node->elem = sum1 + sum2;

    return node->elem + sum1 + sum2;
}

bool Tree::isIdentical(Tree* tree)
{
    vector<vector<TNode*>> arr;

    // arrs for both trees
    arr.push_back(vector<TNode*>());
    arr.push_back(vector<TNode*>());

    // push roots to arrs
    arr[0].push_back(this->root);
    arr[1].push_back(tree->root);

    // vars to store current nodes being checked
    TNode* currNode1;
    TNode* currNode2;

    while (true) {
        // get front of arrs
        currNode1 = arr[0][0];
        currNode2 = arr[1][0];

        // check if they are equal
        if (currNode1->elem != currNode2->elem)
            return false;

        // push children to arrs
        if (currNode1->left != NULL)
            arr[0].push_back(currNode1->left);
        if (currNode1->right != NULL)
            arr[0].push_back(currNode1->right);

        if (currNode2->left != NULL)
            arr[1].push_back(currNode2->left);
        if (currNode2->right != NULL)
            arr[1].push_back(currNode2->right);

        // remove front of arrs
        arr[0].erase(arr[0].begin());
        arr[1].erase(arr[1].begin());

        // check if arrs sizes are the same
        if (arr[0].size() != arr[1].size())
            return false;

        // if both arrs are empty and this point has been reached, then the trees are identical
        if (arr[0].size() == 0 && arr[1].size() == 0)
            return true;
    }
}

TNode* Tree::getRoot()
{
    return root;
}
