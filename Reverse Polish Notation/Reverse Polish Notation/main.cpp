//
//  main.cpp
//  Reverse Polish Notation
//
//  Created by Andy Zhu on 8/19/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <String>
#include <stdlib.h>
#include <stack>
using namespace std;
int evaluate (int val1, int val2, char operators)
{
    int result=0;
    switch(operators){
        case '+':
        result = val1+ val2;
        break;
        
        case '-':
        result= val1- val2;
        break;
        
        case '*':
        result =val1* val2;
        break;
        
        case '/':
        result = val1/val2;
        break;
    }
    return result;
}

bool isdigit(string it){
    try {
        stoi(it);
        return true;
    } catch (exception e) {
        return false;
    }
    return false;
}

bool isoperands(string it)
{
    return (it=="+" || it=="-" || it=="*" || it=="/");
}
            
int evalRPN(vector<string> &tokens) {
    stack<int> mystack;
    int val1=0;
    int val2=0;
    try {

        for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it)
        {
            if (isoperands(*it) && mystack.size() >=2){
                val2 = mystack.top();
                mystack.pop();
                val1 = mystack.top();
                mystack.pop();
                //cout<<val1<<" "<<*it<<" "<<val2<<" = "<<evaluate(val1, val2, (*it).c_str()[0])<<endl;
                mystack.push( evaluate(val1, val2, (*it).c_str()[0]));
            }
            
            else if (isdigit(*it)){
                mystack.push(stoi(*it));
            }
            else
                throw exception();
        }
    } catch (exception e) {
        cerr<< "parsing error!";
    }
    return mystack.top();
}

int main(int argc, const char * argv[])
{
    if(isoperands("1"))
        cout<<"wrong!!"<<endl;
    //10*6/((9+3)*-11)+17+5
    string temp[] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    vector<string> test(temp, temp+ sizeof(temp)/sizeof(string));
    // insert code here...
    std::cout << evalRPN(test)<<endl;
    return 0;
}

