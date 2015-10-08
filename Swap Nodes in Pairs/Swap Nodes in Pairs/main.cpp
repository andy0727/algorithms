//
//  main.cpp
//  Swap Nodes in Pairs
//
//  Created by Andy Zhu on 11/3/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    ListNode* temp =head->next;
    head->next = swapPairs( head->next->next);
    temp->next = head;
    head = temp;
    
    return head;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *node1= new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3= new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    node1 = swapPairs(node1);
    while (node1 != NULL){
        
        std::cout << node1->val<<std::endl;
        node1 = node1->next;
        
    }
    return 0;
}
