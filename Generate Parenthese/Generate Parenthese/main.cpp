//
//  main.cpp
//  Generate Parenthese
//
//  Created by Andy Zhu on 11/5/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <unordered_map>
using namespace std;

void helper (vector<string> &v,string s, int l, int r){
    if (l==0 && r==0){
        v.push_back(s);
        return;
    }
    
    if(r>0)
        helper(v,s+")", l, r-1);
    if (l>0)
        helper(v,s+"(",l-1, r+1);
    
}

vector<string> generateParenthesis(int n) {
    if (n<=0){
        vector<string> res;
        string temp="";
        res.push_back(temp);
        return res;
    }
    
    vector<string>* res= new vector<string>[n];
    res[0].push_back("()");
    string temp;
    for (int i=1; i<n;i++)
    {
        for (int k= 1; k<i;++k){
            for (auto m = res[k-1].begin(); m!=res[k-1].end();++m){
                temp = "("+(*m)+")";
                for (auto  p= res[i-1-k].begin(); p!=res[i-1-k].end();++p){
                    res[i].push_back(temp+(*p));
                }
            }
        }
        
        for (auto m = res[i-1].begin(); m!=res[i-1].end();++m){
            temp = "()"+(*m);
            res[i].push_back(temp);
            temp = "("+(*m)+")";
            res[i].push_back(temp);

            
        }
        
        
    }
    return res[n-1];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> v = generateParenthesis(4);
    for (auto it= v.begin(); it!= v.end();++it)
        std::cout << *it<<endl;
    return 0;
}
