//
//  main.cpp
//  Palindrome Number
//
//  Created by Andy Zhu on 11/11/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
bool isPalindrome(int x) {
    int reverse=0;
    if (x<0)
        return false;
    int cursor=x;
    while(cursor>0){
        int temp = cursor%10;
        reverse=reverse*10+temp;
        cursor=cursor/10;
    }
    return (reverse==x);
}
int main(int argc, const char * argv[]) {
    if(isPalindrome(12))
    std::cout << "Hello, World!\n";
    return 0;
}
