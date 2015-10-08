//
//  main.cpp
//  Letter Combinations of a Phone Number
//
//  Created by Andy Zhu on 11/18/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> letterCombinations(string digits) {
    vector<string> res;
    int size= digits.length();
    
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    res.push_back("");
    for(int i=0; i<size;i++)
    {
        string chars=charmap[digits[i]-'0'];
        vector<string> tempres;
        for (int j=0;j<chars.size();j++)
            for(int k=0; k<res.size();k++)
            {
                tempres.push_back(res[k]+chars[j]);
            }
        res=tempres;
    }
    return res;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
