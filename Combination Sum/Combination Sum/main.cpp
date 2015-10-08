//
//  main.cpp
//  Combination Sum
//
//  Created by Andy Zhu on 11/16/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

struct set{
    vector<int>  c;
    int sum;
};

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    queue<set> s;
    vector<vector<int> > res;
    for(int i=0; i<candidates.size();i++)
    {
        if(candidates[i]<target)
        {
            set temp;
            temp.c.push_back(candidates[i]);
            temp.sum=candidates[i];
            s.push(temp);
        }
        if(candidates[i]==target)
        {
            vector<int> t;
            t.push_back(candidates[i]);
            res.push_back(t);
        }
        
    }

    while(!s.empty())
    {
        
       
        for(int i=0; i<candidates.size();i++)
        {
            set temp =s.front();
            if(candidates[i]>=temp.c[temp.c.size()-1])
            {
                temp.sum+=candidates[i];
                temp.c.push_back(candidates[i]);
                if(temp.sum<target)
                    s.push(temp);
                else if (temp.sum==target)
                    res.push_back(temp.c);
            }
        }
        
        s.pop();
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> candidates;
    candidates.push_back(1);
    candidates.push_back(2);
    candidates.push_back(6);
    candidates.push_back(7);
    vector<vector<int> >res = combinationSum(candidates, 3);
    std::cout << "Hello, World!\n";
    return 0;
}
