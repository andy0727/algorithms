//
//  main.cpp
//  Subsets
//
//  Created by Andy Zhu on 11/13/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>
using namespace std;

vector<vector<int> > subsets(vector<int> &S) {
    int num= S.size();
    sort(S.begin(), S.end());
    int tot = pow(2,num);
    vector<vector<int> > res(tot, vector<int>());

    for(int i=0;i<num;i++)
        for(int j=0;j<tot;j++)
            if(j>>i &1)
                res[j].push_back(s[i]);
    
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
