//
//  main.cpp
//  Subsets II
//
//  Created by Andy Zhu on 11/16/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > subsetsWithDup(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int> > res;
    res.push_back(vector<int>());
    int size=0;
    for (int i =0; i<S.size();i++)
    {
        int start = i>=1&&S[i]==S[i-1]?size:0;
        size= res.size();
        for(int j =start;j<size;j++)
        {
            vector<int> temp = res[j];
            temp.push_back(S[i]);
            res.push_back(temp);
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
