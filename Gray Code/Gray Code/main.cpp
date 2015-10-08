//
//  main.cpp
//  Gray Code
//
//  Created by Andy Zhu on 11/4/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool valid (int n1, int n2){
    int temp= n1 ^ n2;
    return (temp != 0) && (((~temp+1) & temp) == temp);
}
/*
vector<int> grayCode(int n) {
    vector<int>  res;
    res.push_back(0);
    if (n<=0)
        return res;
   
    
    int val = 1;
    vector<int> holds;
    int size = pow(2,n);
    while (res.size() <size)
    {
        if (val <size && valid(val,res[res.size()-1]))
        {
            res.push_back(val);
            val++;
        }
        
        else
        {
            if (holds.empty() ||holds[holds.size()-1]!= val)
                holds.push_back(val);
            bool found = false;
            //look back see if any previous value fits.
            for (auto it= holds.begin(); it!= holds.end(); ++it)
            {
                if (valid(*it , res[res.size()-1])){
                    found = true;
                    res.push_back(*it);
                    holds.erase(it);
                    break;
                }
            }
            
    
            //no match found. have to continue
            if (!found)
                val++;
        }
    }
    
    return res;
}
*/
vector<int> grayCode(int n) {
    vector<int> v;
    v.push_back(0);
    if (n<=0)
        return v;
    if (n==1){
        v.push_back(1);
    }
    
    vector<int>  res;
    res = grayCode(n-1);
    int size = res.size()-1;
    while (size >=0)
    {
        res.push_back(res[size]+ (1<<(n-1)));
        size--;
    }
    
    
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> v= grayCode(5);
    for (auto it = v.begin(); it != v.end(); ++it)
        std::cout << *it<<endl;
    return 0;
}
