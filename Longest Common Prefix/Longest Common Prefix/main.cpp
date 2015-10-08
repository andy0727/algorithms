//
//  main.cpp
//  Longest Common Prefix
//
//  Created by Andy Zhu on 11/17/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    if(strs.size()<=0)
        return "";
    string res = strs[0];
    for(int i=0; i<strs.size();i++)
    {
        string prefix;
        for(int j=0;j<strs[i].length();j++)
        {
            if(j>=res.length() || strs[i][j]!=res[j])
                break;
            prefix+=strs[i][j];
        }
        res=prefix;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> strs;
    strs.push_back("aa");
    strs.push_back("a");
    string prefix= longestCommonPrefix(strs);
    std::cout << prefix;
    return 0;
}
