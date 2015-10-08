//
//  main.cpp
//  Search in Rotated Sorted Array II
//
//  Created by Andy Zhu on 11/9/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
using namespace std;

bool search(int A[], int n, int target) {
    int start = 0;
    int end = n-1;
    while(start<end){
        int mid = (start+end)/2;
        if (A[start]== A[end])
            start+=1;
        
        else if(A[mid]>A[end])
            start = mid+1;
        
        else
            end = mid;
        
    }
    
    int rot = start;
    start =0;
    end = n-1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        int realmid = (mid+rot)%n;
        if(A[realmid] ==target)
            return true;
        else if (A[realmid]<target)
            start = mid+1;
        else
            end = mid-1;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[7]={4,2,2,2,2,2,2};
    if (search(A, 7, 4))
        std::cout << "Hello, World!\n";
    return 0;
}
