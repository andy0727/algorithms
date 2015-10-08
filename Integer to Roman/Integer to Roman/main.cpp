//
//  main.cpp
//  Integer to Roman
//
//  Created by Andy Zhu on 11/3/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;
struct interval_tree{
    string val;
    int small;
    int large;
    interval_tree* left;
    interval_tree* right;
    interval_tree(string val): val(val){}
};

struct classcomp {
    bool operator() (const int& lhs, const int& rhs) const
    {return lhs>rhs;}
};

string intToRoman(int num) {
    string res;
    map<int, string,classcomp> itor;
    

 
    itor[1000] = "M";
    itor[900] = "CM";
    itor[500] = "D";
    itor[400] = "CD";
    itor[100] = "C";
    itor[90] = "XC";
    itor[50] = "L";
    itor[40] = "XL";
    itor[10] = "X";
    itor[9] = "IX";
    itor[5] = "V";
    itor[4] = "IV";
    itor[1] = "I";

    while (num>0){
        for (auto it = itor.begin(); it != itor.end(); ++it){
            //std::cout << " " << it->first << ":" << it->second<<endl;

            if (num >= it->first){
                res+= it->second;
                num-= it->first;
                break;
            }
        }
    }
    return res;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << intToRoman(44);
    return 0;
}
