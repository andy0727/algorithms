//
//  main.cpp
//  Remove Duplicates from Linked List
//
//  Created by Andy Zhu on 11/1/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

ListNode *deleteDuplicates(ListNode *head) {
    if (head ==NULL)
        return head;
    
    ListNode* cursor = head;
    while (cursor!=NULL && cursor->next!= NULL){
        if(cursor->val ==cursor->next->val)
        {
            
            ListNode* temp = cursor->next;
            cursor->next = temp->next;
            delete temp;
        }
        else
            cursor= cursor->next;
        
            
    }
    return head;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* node1= new ListNode(0);
    ListNode* node2= new ListNode(2);
    ListNode* node3= new ListNode(1);
    node1->next = node2;
    node2->next= node3;
    
    ListNode* cursor = deleteDuplicates(node1);
    while (cursor!= NULL){
        std::cout<<cursor->val<<std::endl;
        cursor= cursor->next;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
