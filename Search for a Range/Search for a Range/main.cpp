//
//  main.cpp
//  Search for a Range
//
//  Created by Andy Zhu on 11/16/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(int A[], int n, int target) {
    vector<int> range;
    range.push_back(-1);
    range.push_back(-1);
    
    int start =0;
    int end =n-1;
    while(start<end){
        int mid =(start+end)/2;
        if(A[mid]<target)
            start= mid+1;
        else
            end = mid;
    }
    if(A[start]==target)
        range[0]=start;
    
    end =n-1;
    while(start<end){
        int mid =(start+end+1)/2;
        if(A[mid]<=target)
            start= mid;
        else
            end = mid-1;
    }
    if(A[end]==target)
        range[1]=end;
    cout<<end<<endl;
    return range;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[2]={1,3};
    vector<int>range= searchRange(A, 2, 1);
    std::cout << "Hello, World!\n";
    return 0;
}
