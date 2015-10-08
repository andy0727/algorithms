//
//  main.cpp
//  Linked List Cycle
//
//  Created by Andy Zhu on 11/1/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    unordered_map<ListNode*, int> map;
    ListNode* cursor = head;
    while (cursor != NULL){
        cursor = cursor->next;
       
        if ( map[cursor]== 1)
            return true;
        else
            map[cursor]=1;
    }
    return false;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* root = new ListNode(0);
    ListNode* node1 = new ListNode(1);
    root->next = node1;
    node1->next = root;
    if (hasCycle(root))
        std::cout << "true";
    else
        std::cout<<"false";
    return 0;
}
