//
//  main.cpp
//  Linked List Cycle II
//
//  Created by Andy Zhu on 11/9/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode* one,*two;
    one = head;
    two = head;
    bool isCycle;
    if (one==NULL||one->next==NULL)
        return NULL;
    
    while( one!=NULL &&two!=NULL &&two->next!=NULL){
        
        one = one->next;
        two = two->next->next;
        if(one==two)
        {
            isCycle=true;
            break;
        }
    }
    if(!isCycle)
        return NULL;
    
    one = head;
    while(one!=two){
        one = one->next;
        two = two->next;
    }
    return one;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
