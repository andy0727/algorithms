//
//  main.cpp
//  Distinct Subsequences
//
//  Created by Andy Zhu on 11/22/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int numDistinct(string S, string T) {
    int count=0;
    int m=S.size();
    int n=T.size();
    vector<int>path(n+1,0);
    path[0]=1;
    if(m<n)
        return 0;
    
    for(int i=0; i<m;i++)
        for(int j=n;j>=1;j--)
            path[j]=path[j]+(S[i]==T[j-1]?path[j-1]:0);
    return path[n];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string S="rabbbit";
    string T="rabbit";
    int count= numDistinct(S, T);
    std::cout << count<<endl;
    return 0;
}
