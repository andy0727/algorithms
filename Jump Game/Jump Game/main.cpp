//
//  main.cpp
//  Jump Game
//
//  Created by Andy Zhu on 11/16/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include<math.h>
using namespace std;
bool canJump(int A[], int n) {
    int reach=0;
    for(int i=0;i<n && i<=reach;i++)
        reach = max(A[i]+i, reach);
    
    return reach>= n-1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[5]={2,2,3,0,4};
    if(canJump(A, 5))
        std::cout << "Hello, World!\n";
    return 0;
}
