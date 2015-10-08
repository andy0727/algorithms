//
//  main.cpp
//  Add Binary
//
//  Created by Andy Zhu on 11/21/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
string addBinary(string a, string b) {
    string s;
    int s1=a.size();
    int s2=b.size();
    int index=1;
    string carry="0", sum="0";
    while(index<=s1&& index<=s2){
        char w1=a[s1-index], w2=b[s2-index];
        if(w1==w2){
            s=carry+s;
            if(w1=='1')
                carry="1";
            else
                carry="0";
        }
        else{
            if(carry=="1")
                s="0"+s;
            else
                s="1"+s;
        }
        index++;
    }
    cout<<s<<endl;
    while(index<=s1){
        char w1=a[s1-index];
        if(w1=='0'){
            s=carry+s;
            carry="0";
        }
        else{
            if(carry=="1")
                s="0"+s;
            else
                s="1"+s;
        }
        index++;
    }
    
    while(index<=s2){
        char w2=b[s2-index];
        if(w2=='0'){
            s=carry+s;
            carry="0";
        }
        else{
            if(carry=="1")
                s="0"+s;
            else
                s="1"+s;
        }
        index++;
    }
    if(carry=="1")
        s=carry+s;
    return s;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string a="100";
    string b="110010";
    string s=addBinary(a, b);
    std::cout << s<<endl;
    return 0;
}
