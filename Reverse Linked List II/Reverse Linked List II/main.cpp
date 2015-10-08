//
//  main.cpp
//  Reverse Linked List II
//
//  Created by Andy Zhu on 11/19/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode* pre=NULL, *cur=head;
    ListNode* tmp;
    int start = m>1?m:1;
    while(start>1 && cur){
        cur=cur->next;
        start--;
    }
    
    start=n;
    pre=cur;
    while(start>0 && pre){
            pre=pre->next;
            start--;
    }
    
    start=m>1?m:1;
    while(start<n+1&& cur){
        tmp=cur->next;
        cur->next=pre;
        pre=cur;
        cur=tmp;
        start++;
    }
    if(m>1){
        head->next=pre;
        return head;
    }
    else
        return pre;
    
}

ListNode *reverse(ListNode* head){
    ListNode* pre=NULL,*cur=head;
    ListNode* tmp;
    while(cur){
        tmp=cur->next;
        cur->next=pre;
        pre= cur;
        cur=tmp;
    }
    return pre;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* node1= new ListNode(1);
    ListNode* node2=new ListNode(2);
    ListNode* node3=new ListNode(3);
    ListNode* node4= new ListNode(4);
    ListNode* node5=new ListNode(5);
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    ListNode* res = reverseBetween(node1, 2, 6);
    //ListNode* res2= reverse(NULL);
    std::cout << "Hello, World!\n";
    return 0;
}
