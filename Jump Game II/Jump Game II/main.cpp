//
//  main.cpp
//  Jump Game II
//
//  Created by Andy Zhu on 11/22/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int jump(int A[], int n) {
    int curr=0;
    int last=0;
    int count=0;
    for(int i=0; i<n;i++){
        if(curr<i)
            return -1;
        
        if(i>last){
            last= curr;
            count++;
        }
        curr=max(curr,A[i]+i);
    }
    return count;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[15]={4,3,2,1,0,5};
    std::cout << jump(A, 15)<<endl;
    return 0;
}
