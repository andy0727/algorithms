//
//  main.cpp
//  Pascal's Triangle
//
//  Created by Andy Zhu on 11/7/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > generate(int numRows) {
    vector<vector<int> >res;
    if (numRows<=0)
        return res;
    if(numRows==1)
    {
        vector<int> v;
        v.push_back(1);
        res.push_back(v);
        return res;
    }
    else {
        res = generate(numRows-1);
        vector<int> v;
        v.push_back(1);
        
        for(auto j = res[numRows-2].begin(); j!=res[numRows-2].end()-1;++j){
                v.push_back((*j)+ (*(j+1)));
            }
        
        v.push_back(1);
         res.push_back(v);
    }
    return res;
    
}
int main(int argc, const char * argv[]) {
    vector<vector<int> > res= generate(5);
    // insert code here...
    for (auto it= res.begin(); it!=res.end();++it)
    {
        for (auto i=it->begin(); i!=it->end(); ++i)
            cout<<*i<<" ";
        cout<<endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
