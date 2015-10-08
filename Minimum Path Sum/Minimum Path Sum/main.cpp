//
//  main.cpp
//  Minimum Path Sum
//
//  Created by Andy Zhu on 11/7/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int minPathSum(vector<vector<int> > &grid) {
    if(grid.size()<=0 || grid[0].size()<=0)
        return 0;
    
    int m =grid.size();
    int n =grid[0].size();
    int res[n];
    res[0]= grid[0][0];
    for(int i =0; i<m;i++)
        for(int j =0; j<n; j++){
            if(i==0)
            {
                if(j>0)
                    res[j]= grid[i][j]+res[j-1];
            }
            else
            {
                if(j==0)
                    res[j]= grid[i][j]+res[j];
                else
                    res[j]= grid[i][j]+min(res[j], res[j-1]);
            }
        }
    
    return res[n-1];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
