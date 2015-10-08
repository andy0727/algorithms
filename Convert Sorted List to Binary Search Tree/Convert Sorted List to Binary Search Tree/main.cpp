//
//  main.cpp
//  Convert Sorted List to Binary Search Tree
//
//  Created by Andy Zhu on 11/13/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

     struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *sortedListToBST(ListNode *head) {
    TreeNode* res;
    if(head==NULL)
        return res;
    if(head->next==NULL)
        return new TreeNode(head->val);
    ListNode* cursor=head;
    ListNode* cursor2=head->next;
    while(cursor2->next!=NULL && cursor2->next->next!=NULL){
        cursor=cursor->next;
        cursor2=cursor2->next->next;
    }
    res= new TreeNode(cursor->next->val);
    ListNode*right= cursor->next->next;
    cursor->next=NULL;
    res->left = sortedListToBST(head);
    res->right = sortedListToBST(right);
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* head=new ListNode(3);
    ListNode* node1=new ListNode(5);
    ListNode* node2=new ListNode(8);
    ListNode* node3=new ListNode(10);
    head->next=node1;
    node1->next=node2;
    node2->next=node3;
    //node1->next=node2
    TreeNode* res= sortedListToBST(head);
    std::cout << "Hello, World!\n";
    return 0;
}
