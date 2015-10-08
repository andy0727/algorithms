//
//  main.cpp
//  Permutations II
//
//  Created by Andy Zhu on 11/22/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > permuteUnique(vector<int> &num) {
    int n =num.size();
    vector<vector<int> > res;
    sort(num.begin(), num.end());
    if(n<=0)
        res.push_back(vector<int>());
    else
        res.push_back(num);
    
    while(true){
        int first= n-2;
        while(first>=0&& num[first]>=num[first+1])
            first--;
        int swap = n-1;
        cout<<first<<endl;
        if(first>=0){
            while(swap>first && num[swap]<=num[first])
                swap--;
            
            std::swap(num[first],num[swap]);
            reverse(num.begin() +first+1,num.end());
            res.push_back(num);
        }
        
        else
            break;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> res;
    res.push_back(1);
    res.push_back(1);
    res.push_back(2);
    vector<vector<int> > v = permuteUnique(res);
    
    std::cout << "Hello, World!\n";
    return 0;
}
