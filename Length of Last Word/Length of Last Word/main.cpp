//
//  main.cpp
//  Length of Last Word
//
//  Created by Andy Zhu on 11/11/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int lengthOfLastWord(const char *s) {
    int len=0;
    while (*s){
        if(*s++!=' ')
            len++;
        else if(*s&&*s!=' ')
            len=0;
    }
    return len;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
