//
//  main.cpp
//  Palindrome Partitioning
//
//  Created by Andy Zhu on 11/20/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isPalindrom(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-1-i])
            return false;
    }
    return true;
}

vector<vector<string>> partition(string s) {
    vector<vector<string> > res;
    
    if(s.length()<=0){
        res.push_back({});
        return res;
    }
    
    if(s.length()==1){
        res.push_back({s});
        return res;
    }
    
    int size = s.length();
    
    for(int i=0; i<size;i++)
    {
        string first= s.substr(0,i+1);
        if(isPalindrom(first)){
            
            vector<vector<string> > temp = partition(s.substr(i+1, size-i-1));
            for(int j=0;j<temp.size();j++){
                temp[j].insert(temp[j].begin(),first);
                res.push_back(temp[j]);
            }
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string s= "bb";
    vector<vector<string> > res = partition(s);
    for(int i=0;i<res.size();i++)
    {
        cout<<"[";
        for(int j=0;j<res[i].size();j++)
        {
            cout<<" "<<res[i][j];
        }
        cout<<"]"<<endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
