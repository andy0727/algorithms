//
//  main.cpp
//  Set Matrix Zeroes
//
//  Created by Andy Zhu on 11/9/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int> > &matrix) {
    if(matrix.size()<=0 || matrix[0].size()<=0)
        return;
    
    int n = matrix.size();
    int m = matrix[0].size();
    bool firstrowzero = false;
    
    for(int i =0; i<m;++i)
        if(matrix[0][i]==0)
            firstrowzero=true;
    
    for(int i=1; i<n;++i)
        for(int j=0; j<m;++j)
        {
            if(matrix[i][j]==0)
            {
                matrix[0][j]=0;
                matrix[i][0]=0;
            }
        }
    
    for(int i=1; i<n;++i)
        for(int j=1; j<m;++j)
            if(matrix[i][0]==0 || matrix[0][j]==0)
                matrix[i][j]=0;
    
   
    if(matrix[0][0]==0)
         for(int j=0;j<n;j++)
             matrix[j][0]=0;
    if(firstrowzero)
         for(int i =0; i<m;++i)
             matrix[0][i]=0;
            
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> v1,v2;
    v1.push_back(0);
    v2.push_back(1);
    vector<vector<int> >res;
    res.push_back(v1);
    res.push_back(v2);
    setZeroes(res);
    for(int i =0; i<res.size();i++){
        for(int j=0;j<v1.size();j++)
                std::cout << res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
