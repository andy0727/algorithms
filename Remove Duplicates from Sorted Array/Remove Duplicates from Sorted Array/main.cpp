//
//  main.cpp
//  Remove Duplicates from Sorted Array
//
//  Created by Andy Zhu on 11/3/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
using namespace std;

int removeDuplicates(int A[], int n) {
    if(n<=1)
        return n;
    
    int l = removeDuplicates(A, n/2);
    int r = removeDuplicates(A+n/2, n-n/2);
    if(A[l-1] == A[(n/2)])
        l--;
    for( int i = l; i<l+r; ++i){
        A[i] = A[(n/2)+i-l];
    }
    return l+r;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[3] ={1};
    int n = removeDuplicates(A,1);
    for (int i =0; i<n; ++i)
        std::cout << A[i]<<endl;
    return 0;
}
