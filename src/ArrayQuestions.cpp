#include "ArrayQuestions.h"

void getMissingNum(int* arr){   // assume 1 to 100
    for(int i=0;i<100;i++){    // use xor approach
        if((arr[i]^i+1) != 0){  // any number XOR itself = 0 
            cout<<"missing number is "<<i+1<<endl;
            return;
        }
    }
    cout<<"no number is missing"<<endl;
    /*
     * another approach is to add up all the numbers and subtract that from 
     * sum of all numbers 1 to 100
     */
}

void findNumOfPairs(){

    /*
     *  To find the number of pairs where elem[i] != elem[j] we first count the total number of pairs using the formula n(n+1)/2
     *  However, we input n = n-1 into the formula since elems cannot pair with themselves.
     *  Then we count the number of occurrences of each elem. The formula n(n+1)/2 is then applied due to the fact that we have to count the number of 
     *  occurrences of elem after elem[i] for each elem[i]. n-1 is used for n since we dont count the first occurrence.
     *  The approach taken here uses a hashmap to store an index for arr that corresponds to a specific elem. when a repeating elem
     *  is found, the index of that elem is retrieved from the map and used to access arr. The value stored at the arr[index] is then increased 
     *  by 1
     *  Finally we loop through arr and decrease pairs by arr[i](arr[i]+1)/2. We will then be left with the total number of pairs excluding those 
     *  where elem[i]==elem[j]
     */

    int n,temp,pairs=0;
    unordered_map<int,int> hMap;
    vector<int> arr;
    cin>>n;

    if(n<1){
        cout<<"0";
        return;
    }

    int count=0;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(!hMap.contains(temp)){       // if elem not in map, it is added
            hMap[temp]=count;
            arr.push_back(0);           // value initialized to 0
            count++;
        }else{
            arr[hMap[temp]]++;
            if(temp==1)
                cout<<"1 val: "<<arr[hMap[temp]]<<endl;
        }
    }


    pairs=(n-1)*(n)/2;                  // n-1 since elems cannot pair with themselves (i<j) // (n-1)+1 = n
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            pairs-=(arr[i]*(arr[i]+1)/2);
        }
    }

    cout<<pairs<<endl;
}
