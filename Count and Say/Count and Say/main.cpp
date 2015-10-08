//
//  main.cpp
//  Count and Say
//
//  Created by Andy Zhu on 11/19/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n) {
    string s;
    if(n<=0)
        return s;
    if(n>=1)
        s="1";
    for(int i=1;i<n;i++)
    {
        char cur=s[0];
        int count=0;
        string news;
        for(int j=0;j<s.length();j++)
        {
            if(cur==s[j]){
                count++;
            }
            else{
                news.append(to_string(count));
                news.append(1,cur);
                count=1;
                cur=s[j];
            }
            
        }
        news.append(to_string(count));
        news.append(1,cur);
        s=news;
    }
    return s;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << countAndSay(5)<<endl;
    return 0;
}
