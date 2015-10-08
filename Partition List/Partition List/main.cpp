//
//  main.cpp
//  Partition List
//
//  Created by Andy Zhu on 11/16/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x) {
    ListNode* l=NULL;
    ListNode* r=NULL;
    ListNode* cursor = head;
    while(cursor!=NULL){
        ListNode* next=cursor->next;
        if(cursor->val<x)
        {
            if(l!=NULL &&l->next!=cursor )
            {
                ListNode* temp= l->next;
                l->next= cursor;
                cursor->next = temp;
            }
            else if(l==NULL&& cursor!=head)
            {
                cursor->next =head;
                head = cursor;
            }
            l=cursor;
        }
        else if(cursor->val>=x)
        {
            if(r!=NULL && r->next!=cursor)
            {
                ListNode* temp= r->next;
                r->next=cursor;
                cursor->next= temp;
            }
            r= cursor;
        }
        cursor=next;
    }
    if(r!=NULL)
        r->next=NULL;
    return head;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* root=new ListNode(4);
    ListNode* node1= new ListNode(1);
    //ListNode* node2 = new ListNode(3);
    //ListNode* node3 = new ListNode(2);
    //ListNode* node4= new ListNode(5);
    //ListNode* node5 = new ListNode(2);
    root->next=node1;
    //node1->next =node2;
    //node2->next = node3;
    //node3->next =node4;
    //node4->next = node5;
    ListNode* temp  = partition(root, 4);
    std::cout << "Hello, World!\n";
    return 0;
}
