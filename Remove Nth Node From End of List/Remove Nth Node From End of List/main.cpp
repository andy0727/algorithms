//
//  main.cpp
//  Remove Nth Node From End of List
//
//  Created by Andy Zhu on 11/11/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
    if(head==NULL)
        return NULL;
    if(n<=0)
        return head;
    
    ListNode* cursor = head;
    ListNode* cursor2=head;
    int steps=n;
    
    
    while(cursor2!=NULL && steps>=0)
    {
        cursor2=cursor2->next;
        steps--;
    }
    if(cursor2==NULL && steps==0)
    {
        return head->next;
    }
    while(cursor2!=NULL)
    {
        cursor=cursor->next;
        cursor2=cursor2->next;
    }
    cursor->next= cursor->next->next;
    return head;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* head=new ListNode(1);
    ListNode* node1= new ListNode(2);
    head->next=node1;
    ListNode* temp= removeNthFromEnd(head, 1);
    std::cout << "Hello, World!\n";
    return 0;
}
