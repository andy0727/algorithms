//
//  main.cpp
//  Permutations
//
//  Created by Andy Zhu on 11/6/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > res;
    for(auto i =num.begin(); i!= num.end() ; ++i)
    {
        int temp = *i;
        num.erase(i);
        vector<vector<int>> v= permute(num);
        
        if (v.size()<=0)
        {
            vector<int> n;
            n.push_back(temp);
            //cout<<"i got skipped"<<endl;
            num.insert(i,temp);
            v.push_back(n);
            return v;
        }
        
        for(auto j = v.begin(); j!=v.end();++j){
            j->push_back(temp);
            res.push_back(*j);
        }
        
        num.insert(i, temp);
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    vector<vector<int> > res = permute(v);
    for(auto i =res.begin(); i!= res.end() ; ++i)
    {
        cout<<"[";
        for(auto j = i->begin(); j!=i->end();++j){
            cout<<(*j)<<",";
        }
        cout<<"]"<<endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
