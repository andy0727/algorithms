//
//  main.cpp
//  Anagrams
//
//  Created by Andy Zhu on 11/22/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
vector<string> anagrams(vector<string> &strs) {
    vector<string> res;
    unordered_map<string, vector<string> > map;
    for(string s:strs){
        string tmp = s;
        sort(s.begin(),s.end());
        map[s].push_back(tmp);
    }
    
    for(auto m:map)
        if(m.second.size()>1)
            res.insert(res.end(), m.second.begin(), m.second.end());
    
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
