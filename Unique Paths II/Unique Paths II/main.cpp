//
//  main.cpp
//  Unique Paths
//
//  Created by Andy Zhu on 11/5/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int m= obstacleGrid.size();
    if(m<=0)
        return 0;
    int n= obstacleGrid[0].size();
    
    if(n<=0)
        return 0;
    
    int grid[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            grid[i][j]=0;
    
    if(obstacleGrid[0][0]!=1)
        grid[0][0]=1;
    
    for(int i=1;i<m;i++)
        if (obstacleGrid[i][0]!=1)
            grid[i][0]=grid[i-1][0];
    
    for(int j=1;j<n;j++)
        if(obstacleGrid[0][j]!=1)
            grid[0][j]=grid[0][j-1];
    
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
            if (obstacleGrid[i][j]!=1)
                grid[i][j]=grid[i-1][j]+grid[i][j-1];
    
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    return grid[m-1][n-1];
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //vector<vector<int> >obstacleGrid(3,vector<int>(3,0));
    //obstacleGrid[1][1]=1;
    vector<vector<int> >obstacleGrid(1,vector<int>(1,0));
    obstacleGrid[0].push_back(1);
    std::cout << uniquePathsWithObstacles(obstacleGrid);
    return 0;
}
