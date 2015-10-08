//
//  main.cpp
//  Largest Consecutive Integer
//
//  Created by Andy Zhu on 11/12/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include<unordered_map>
using namespace std;
int longestConsecutive(vector<int> &num) {
    int maxlen=1;
    unordered_map<int, int> mymap;
    for(int i=0; i<num.size();i++){
        if(mymap[num[i]]!=0)
            continue;
        else{
            int len=1;
            mymap[num[i]]= 1;
            if( mymap[num[i]-1]!=0){
                len = 1+mymap[num[i]-1];
                mymap[num[i]]= len;
                mymap[num[i]-len+1]++;
                maxlen=max(len,maxlen);
            }
            if( mymap[num[i]+1]!=0){
                int start = num[i]-len+1;
                int end = num[i]+mymap[ num[i]+mymap[num[i]+1] ];
                len = mymap[end]+mymap[num[i]];
                mymap[end]=len;
                mymap[start]=len;
                maxlen=max(len,maxlen);
                
            }
        }
    }
    for(auto it=mymap.begin(); it!=mymap.end();it++)
        cout<<"first: "<<it->first<<" second: "<<it->second<<endl;
    return maxlen;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array;
    array.push_back(-1);
    array.push_back(1);
    array.push_back(0);
       std::cout << longestConsecutive(array);
    return 0;
}
