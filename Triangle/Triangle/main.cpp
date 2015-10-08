//
//  main.cpp
//  Triangle
//
//  Created by Andy Zhu on 11/17/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int minimumTotal(vector<vector<int> > &triangle) {
    int size = triangle.size();
    int* dp = new int[size];
    int* pos =new int[size];
    if(size<=0)
        return 0;
    dp[0]= triangle[0][0];
    pos[0]=0;
    int rows = 1;
    while(rows<size)
    {
        vector<int> temp= triangle[rows];
        for(int i =temp.size()-1; i>=0;i--)
        {
            if(i==0)
                dp[0]=dp[0]+temp[0];
            else if (i==temp.size()-1)
                dp[i]=dp[i-1]+temp[i];
            else
                dp[i]=min(dp[i]+temp[i], dp[i-1]+temp[i]);
        }
        rows++;
    }
    
    int min=dp[0];
    for(int i=0; i<size;i++)
        if(min>dp[i])
            min = dp[i];
    
    return min;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
