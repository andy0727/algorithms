//
//  main.cpp
//  N-Queens
//
//  Created by Andy Zhu on 11/20/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> toChessString(vector<int> arr)
{
    string s(arr.size(),'.');
    vector<string> res(arr.size(),s);
    for(int i=0; i<arr.size();i++)
        res[i][arr[i]]='Q';
    
    return res;
    
}
bool isSafe(vector<int> arr, int r , int c ){
    int val;
    for(int row=r-1,ldia=c-1, rdia=c+1;row>=0;row--,ldia--,rdia++){
        val=arr[row];
        if(val==ldia || val==rdia||val==c)
            return false;
    }
    return true;
}
void solveNqueen(vector<int>& arr , int r , int c, vector<vector<string> >&res,int n)
{
    if(r==n)
        res.push_back(toChessString(arr));
    else{
        for(int i=c;i<n;i++){
            arr[r]=i;
            if(isSafe(arr, r, i))
                solveNqueen(arr, r+1, 0, res,n);
            
        }
    }
}
vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > res;
    vector<int> arr(n,0);
    solveNqueen(arr, 0, 0, res, n);
    return res;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
