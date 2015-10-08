//
//  main.cpp
//  reverse words
//
//  Created by Andy Zhu on 8/19/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <String>
#include <stack>
using namespace std;
void reverseWords(string &s) {
    stack<string> mystack;
    string token="";
    
    for (char temp:s)
    {
        if (temp ==' ' && token != "")
        {
            mystack.push(token);
            token = "";
        }
        else if (temp ==' ')
            continue;
        else
                 token += temp;
    }
    
    if (token != "")
        mystack.push(token);
    string result;
    while (!mystack.empty())
    {
        result += mystack.top()+" ";
        mystack.pop();
    }
    s = result.substr(0, result.size()-1);
}

void reverseWords2(string &s) {

    istringstream is(s);
    string result;
    string out;
    while(is>>out)
    {
        out += " ";
        out += result;
        result = out;
    }
    s= result.substr(0, result.size()-1);
    
}



int main(int argc, const char * argv[])
{

    string s = "  the sky is blue ";
    cout<< s<<endl;
    reverseWords2(s);
    cout<<s<<endl;
    return 0;
}

