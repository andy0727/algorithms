//
//  main.cpp
//  Reverse Nodes in k-Group
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
ListNode* reverseList(ListNode* head, ListNode* tail){
    if(!head|| head==tail)
        return head;
    ListNode* pre= head;
    ListNode* cursor=head->next;
    head->next=NULL;

    while(cursor!=tail){
        ListNode* tmp=cursor->next;
        cursor->next= pre;
        pre=cursor;
        cursor= tmp;
    }
    cursor->next=pre;
    return tail;
}
ListNode *reverseKGroup(ListNode *head, int k) {
    if(!head)
        return NULL;
    ListNode* cur=head;
    ListNode* pre= NULL;
    while(true){
        
        ListNode* cursor= cur;
        int count=1;
        while(cursor &&count<k){
            cursor=cursor->next;
            count++;
        }
        if(!cursor)
            return head;
        ListNode* next= cursor->next;
        
        if(pre)
            pre->next=reverseList(cur, cursor);
        else
            head = reverseList(cur, cursor);
        cur->next=next;
        pre=cur;
        cur=cur->next;
    }
    return NULL;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    ListNode* node1= new ListNode(1);
    ListNode* node2= new ListNode(2);
    ListNode* node3= new ListNode(3);
    node1->next=node2;
    node2->next=node3;
    

    ListNode* head =  reverseKGroup(node1, 1);
    while (head) {
        cout<<head->val<<endl;
        head=head->next;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
