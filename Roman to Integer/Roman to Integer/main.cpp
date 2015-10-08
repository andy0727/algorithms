//
//  main.cpp
//  Roman to Integer
//
//  Created by Andy Zhu on 11/3/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int romanToInt(string s) {
    unordered_map<char, int> rton;
    rton['I'] = 1;
    rton['V'] = 5;
    rton['X'] = 10;
    rton['L'] = 50;
    rton['C'] = 100;
    rton['D'] = 500;
    rton['M'] = 1000;
    int res=0;
    for (int i =0; i<s.length(); i++)
    {
        if(i!=s.length()-1 && rton[s[i]] < rton[s[i+1]])
        {
            res -=rton[s[i]];
        }
        else
            res +=rton[s[i]];
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << romanToInt("XLV");
    return 0;
}
