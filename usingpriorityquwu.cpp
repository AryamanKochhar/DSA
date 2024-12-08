#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int main(){
    int arr[]={1,3,4,6,8,7,9};
    priority_queue<int> test;
    for(int i=0;i<sizeof(arr)/sizeof(arr[1]);i++){
        test.push(arr[i]);
    }
    // for(int k=0;k<7;k++){
    //     printf("%d",test[i]);
    // }
    //it is not an array but a data structure heap  and is its implementatioon 
    while (!test.empty())
    {
        printf("%d",test.top());        
        test.pop();

    }
    return 0;
    
}