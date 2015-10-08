//
//  main.cpp
//  Combination Sum II
//
//  Created by Andy Zhu on 11/22/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(int pos, vector<int> oneres, vector<int>&num, int target, vector<vector<int> >& res){
    for(int i=pos; i<num.size();i++){
        if(target==num[i]){
            oneres.push_back(num[i]);
            res.push_back(oneres);
            oneres.pop_back();
        }
        else if(target>num[i]){
            oneres.push_back(num[i]);
            
            solve(i+1,oneres,num,target-num[i],res);
            oneres.pop_back();
        }
        else
            return;
        while (i < num.size() - 1 && num[i] == num[i + 1])
            i++;
    }
}
vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    vector<vector<int> >res;
    vector<int> oneres;
    sort(num.begin(), num.end());
    solve(0, oneres, num, target,res);
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> num;
    num.push_back(10);
    num.push_back(1);
    num.push_back(2);
    num.push_back(7);
    num.push_back(6);
    num.push_back(1);
    num.push_back(5);
    //num.push_back(2);
    vector<vector<int> > res= combinationSum2(num, 8);
    std::cout << res.size();
    return 0;
}
