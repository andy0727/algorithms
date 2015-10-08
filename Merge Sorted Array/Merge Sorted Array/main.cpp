//
//  main.cpp
//  Merge Sorted Array
//
//  Created by Andy Zhu on 11/4/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
void merge(int A[], int m, int B[], int n) {
    if (m==0){
        for (int i =0; i<n;++i)
            A[i]=B[i];
        return;
    }
    else if (n==0){
        return;
    }
    else if (A[0] > B[0]){
        int temp = A[0];
        A[0]= B[0];
        B[0] = temp;
        for (int i=1; i<n; ++i){
            if(B[i-1] > B[i]){
                int val = B[i];
                B[i] =B[i-1] ;
                B[i-1]= val;
            }
            
        }
      
    }
    merge(A+1,m-1, B, n);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int A[5]= {0,0,5};
    int B[0] = {};
    merge(A, 3, B, 0);
    for (int i =0; i<3; i++)
        std::cout <<A[i]<<std::endl;
    
    return 0;
}
