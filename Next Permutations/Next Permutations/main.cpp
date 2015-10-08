//
//  main.cpp
//  Next Permutations
//
//  Created by Andy Zhu on 11/21/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void nextPermutation(vector<int> &num) {
    if(num.size()<=1)
        return;
    int first=num.size()-2;
    int minmax=num.size()-1;
    while(first>=0&&num[first]>num[first+1])first--;
    while(minmax>0&&num[minmax]<=num[first])minmax--;
    
    int temp=num[minmax];
    num[minmax]=num[first];
    num[first]=temp;
    cout<<first<<endl;
    cout<<minmax<<endl;
    for(int i=first+1;i<=(num.size()+first)/2;i++){
        int temp=num[i];
        num[i]=num[num.size()+first-i];
        num[num.size()-i+first]=temp;
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(0);
    v.push_back(2);
    v.push_back(3);
    v.push_back(2);
    v.push_back(0);
    nextPermutation(v);
    for (int i=0;i<v.size();i++)
        std::cout << v[i]<<endl;
    return 0;
}
