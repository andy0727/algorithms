//
//  main.cpp
//  Climbing Stairs
//
//  Created by Andy Zhu on 11/1/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>

int climbStairs(int n) {
    if (n == 1|| n==0)
        return 1;
    if (n==2)
        return 2;
    return 3*n -7;
    
    int count[n];
    count[0]=1;
    count[1]=2;
    for (int i =0; i<n;i++)
        count[i+2] = count[i+1]+count[i];
    return count[n-1];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << climbStairs(5);
    return 0;
}
