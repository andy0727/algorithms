//
//  main.cpp
//  Combinations
//
//  Created by Andy Zhu on 11/10/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> >res;
    
    if (n<=0 ||k<=0||k>n)
        return res;
    
    if(k==1){
        for (int i=0; i<n;i++)
        {
            vector<int> v;
            v.push_back(i+1);
            res.push_back(v);
        }
        return res;
    }
    
    res = combine(n-1, k);
    
    vector<vector<int> > temp = combine(n-1,k-1);
    for (int j=0; j<temp.size();j++){
        temp[j].push_back(n);
        res.push_back(temp[j]);
    }
    
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int> >res= combine(3,3);
    for (int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
