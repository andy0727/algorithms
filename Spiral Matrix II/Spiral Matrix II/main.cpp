//
//  main.cpp
//  Spiral Matrix II
//
//  Created by Andy Zhu on 11/9/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > res;
    if(n<=0)
        return res;
    
    for(int i=0;i<n;i++)
        res.push_back(vector<int> (n,0));
    
    int hstart=0;
    int vstart=0;
    int hend=n-1;
    int vend=n-1;
    int val=1;
    while(val<=n*n)
    {
        for(int i=vstart;i<=vend;i++){
            res[hstart][i]=val;
            val++;
        }
        hstart++;
        for (int j=hstart;j<=hend;j++){
            res[j][vend]=val;
            val++;
        }
        vend--;
        for(int k=vend;k>=vstart;k--){
            res[hend][k]=val;
            val++;
        }
        hend--;
        for(int l=hend;l>=hstart;l--){
            res[l][vstart]=val;
            val++;
        }
        vstart++;
        
    }
    
    return res;
}
int main(int argc, const char * argv[]) {
    vector<vector<int> > res = generateMatrix(4);
    
    for(int i=0; i<res.size();i++){
        for(int j =0; j<res[0].size();j++)
            std::cout << res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
