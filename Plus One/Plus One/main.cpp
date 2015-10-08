//
//  main.cpp
//  Plus One
//
//  Created by Andy Zhu on 11/6/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
vector<int> plusOne(vector<int> &digits) {
    int carry=1;
    for (auto it= digits.rbegin(); it!=digits.rend()&&carry;++it){
        int sum = carry+(*it);
        *it = sum%10;
        carry= sum/10;
    }
    if(carry ==1){
        digits[0]=1;
        digits.push_back(0);
    }
    
    return digits;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> v;
    v.push_back(9);
    v.push_back(9);
    v.push_back(8);
    v= plusOne(v);
    for(auto it=v.begin(); it!=v.end();++it)
        std::cout << *it<<endl;
    return 0;
}
