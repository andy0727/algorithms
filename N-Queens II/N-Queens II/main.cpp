//
//  main.cpp
//  N-Queens II
//
//  Created by Andy Zhu on 11/2/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool issafe(vector<int>& grid, int r, int c){
    int n= grid.size();
    int check=0;
    for(int row=r-1, ldia=c-1, rdia=c+1; row>=0;row--, ldia--, rdia++){
        check=grid[row];
        if(check==rdia||check==ldia||check==c)
            return false;
    }
    return true;
}
int resolveNQueens(vector<int>& grid, int r, int c){
    int n= grid.size();
    int count=0;
    if(r==n){
        return 1;
    }
    
    for(int i=0;i<n;i++){
        grid[r]=i;
        if(issafe(grid, r, i))
            count+=resolveNQueens(grid, r+1, 0);
    }
    return count;
}
int totalNQueens(int n) {
    int count=0;
    vector<int> grid(n,0);
    count=resolveNQueens(grid, 0, 0);
    return count;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n =2;
    std::cout << totalNQueens(4);
    return 0;
}
