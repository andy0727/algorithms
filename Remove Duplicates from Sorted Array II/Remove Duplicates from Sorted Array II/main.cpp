//
//  main.cpp
//  Remove Duplicates from Sorted Array II
//
//  Created by Andy Zhu on 11/10/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
int removeDuplicates(int A[], int n) {
    if(n<=1)
        return n;
    int l = removeDuplicates(A, n/2);
    int r = removeDuplicates(A+n/2, n-n/2);
    if(A[l-1]==A[n/2]){
        if(l>=2 && A[l-2]==A[l-1])
            l--;
        if(r>=2 && A[n/2]==A[n/2+1])
            l--;
    }
    for(int i=l; i<l+r;i++)
        A[i]=A[n/2+i-l];
    
    return l+r;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int A[6]={1,1,1,1,2,3};
    int n = removeDuplicates(A, 6);
    for(int i=0;i<n;i++)
        std::cout <<A[i];
    return 0;
}
