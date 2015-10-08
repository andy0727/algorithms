//
//  main.cpp
//  Reverse Integer
//
//  Created by Andy Zhu on 10/31/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int reverse(int x) {
    int result =0;
    queue<int> digits;
    while (x>= 10 || x<=-10){
        int temp = x%10;
        x= x/10;
        cout<< temp<<endl;
        digits.push(temp);
    }
    digits.push(x);
    
    while (!digits.empty()){
        result= result*10+ digits.front();
        digits.pop();
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int x = 10;
    std::cout << reverse(x);
    return 0;
}
