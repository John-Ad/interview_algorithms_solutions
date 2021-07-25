#include "ArrayQuestions.h"
#include "LinkedList.h"
#include "Trees.h"
#include <chrono>
#include <ctime>
#include <string>

using namespace std::chrono;

int main()
{
    /*
    LinkedList list;

    list.add(9);
    list.add(8);
    list.add(7);
    list.add(6);
    list.add(5);
    list.add(4);
    list.add(3);
    list.add(2);
    list.add(1);

    list.displayList();
    list.reverse();
    list.displayList();
    list.reverse();
    list.displayList();

    // find missing number between 1 and 100
    int arr[100]={
        1, 2, 3, 4, 5, 6, 7, 8, 9,
        10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
        30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
        40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
        50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
        60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
        70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
        80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
        90, 0, 92, 93, 94, 95, 96, 97, 98, 99,
        100
    };

    getMissingNum(arr);

    int n,temp;
    vector<int> arr;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        arr.push_back(temp);
    }
    findNumOfOpsForPalindrome(arr);

    auto before=duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    findNumOfPairsBetweenTwoNums(4,10);
    auto after=duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    cout<<"run time: "<<(after-before)<<endl;
    */

    int arr[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    Tree tree(arr, 7);
    tree.preOrder(tree.getRoot());
    cout << endl
         << endl;
    tree.breadthFirst();
    //tree.inOrder(tree.getRoot());
    //cout << to_string(tree.depth(tree.getRoot())) << endl;
    //cout << "breadth: " << to_string(tree.breadth()) << endl
    //     << endl;

    /*
    TNode* n2 = new TNode(2);
    TNode* n3 = new TNode(3);
    TNode* n4 = new TNode(4);
    TNode* n5 = new TNode(5);

    tree.getRoot()->left = n2;
    tree.getRoot()->left->left = n3;
    tree.getRoot()->left->left->left = n4;
    tree.getRoot()->left->left->right = n5;

    tree.inOrder(tree.getRoot());
    cout << endl
         << endl;
    cout << "breadth: " << to_string(tree.breadth()) << endl;
    */

    return 0;
}
