//
//  main.cpp
//  Single Number II
//
//  Created by Andy Zhu on 11/3/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
int singleNumber(int A[], int n) {
    int res=0;
    int twice=0;
    for (int i=0; i<n; i++){
        res = res^A[i] & ~twice;
        twice =twice^A[i]& ~res;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[4]= {1,1,1,2};
    std::cout <<singleNumber(A, 4);
    return 0;
}
