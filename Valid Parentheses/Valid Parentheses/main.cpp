//
//  main.cpp
//  Valid Parentheses
//
//  Created by Andy Zhu on 11/13/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool match(char val1,char val2){
    switch (val1) {
        case ')':
            if(val2=='(')
                return true;
            else
                return false;
            break;
            
        case ']':
            if(val2=='[')
                return true;
            else
                return false;
            break;
        case '}':
            if(val2=='{')
                return true;
            else
                return false;
            break;
        default:
            return false;
            break;
    }
}

bool isValid(string s) {
    stack<char> mystack;
    for (int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
            mystack.push(s[i]);
        else{
            if(!mystack.empty()){
                char temp = mystack.top();
                if(match(s[i],temp))
                    mystack.pop();
                else
                    return false;
            }
            else
                return false;
        }
            
    }
    if(mystack.empty())
        return true;
    else
        return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
