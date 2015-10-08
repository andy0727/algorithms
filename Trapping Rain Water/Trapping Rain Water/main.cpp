//
//  main.cpp
//  Trapping Rain Water
//
//  Created by Andy Zhu on 11/11/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <math.h>
int trap(int A[], int n) {
    if(n<=0)
        return 0;
    int l=0;
    int r= n-1;
    int res=0;
    int lmax =l;
    int rmax=r;
    while(l<=r){
        lmax =(A[lmax]>A[l])?lmax:l;
        rmax =(A[rmax]>A[r])?rmax:r;
        if(A[lmax]<=A[rmax]){
            res+=A[lmax]-A[l];
            l++;
        }
        else{
            res+=A[rmax]-A[r];
            r--;
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int A[12]={0,1,0,2,1,0,1,3,2,1,2,1};
    int res = trap(A, 12);
    std::cout << res;
    return 0;
}
