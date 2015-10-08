//
//  main.cpp
//  Remove Duplicates from Sorted List II
//
//  Created by Andy Zhu on 11/22/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *deleteDuplicates(ListNode *head) {
    if(!head || !head->next)
        return head;
    ListNode* pre= NULL;
    ListNode* cursor= head;
    while(cursor){
        ListNode* temp= cursor->next;
        if(!temp || temp->val!=cursor->val){
            if(!pre)
                head= cursor;
            pre=cursor;
            cursor=cursor->next;
        }
        else{
            while(temp&& temp->val==cursor->val)
                temp=temp->next;
            cursor=temp;
            if(pre)
                pre->next=cursor;
        }
    }
    if(pre)
        return head;
    else
        return NULL;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* node1= new ListNode(2);
    ListNode* node2= new ListNode(2);
    ListNode* node3= new ListNode(2);
    ListNode* node4= new ListNode(3);
    node1->next = node2;
    node2->next= node3;
    node3->next=node4;
    ListNode* cursor = deleteDuplicates(node1);
    while (cursor!= NULL){
        std::cout<<cursor->val<<std::endl;
        cursor= cursor->next;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
