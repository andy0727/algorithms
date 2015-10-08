//
//  main.cpp
//  Insertion Sort List
//
//  Created by Andy Zhu on 11/21/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};
/*
ListNode *insertionSortList(ListNode *head) {
    stack<ListNode*> mystack;
    if(!head)
        return head;
    ListNode* i = head;
    mystack.push(head);
    ListNode* j=i->next;
    
    while(j){
        if(mystack.empty()){
            head=j;
            mystack.push(j);
            j=j->next;
        }
        else{
            ListNode* cur= mystack.top();
            
            if(cur->val<=j->val){
                cur->next=j;
                mystack.push(j);
                j=j->next;
            }
            else
            {
                mystack.pop();
                ListNode* t = j->next;
                j->next=cur;
                cur->next=t;
            }
        }
    }
    return head;
}
*/
ListNode *insertionSortList(ListNode *head) {
    if(!head ||!(head->next))
        return head;
    ListNode* p=head;
    ListNode*q,*prep;
    q=head->next;
    head->next=NULL;
    while(q){
        prep=NULL;
        p=head;
        while(p!=NULL&&p->val<=q->val){
            prep=p;
            p=p->next;
        }
        ListNode* tmp= q->next;
        if(!prep)
            head=q;
        else
            prep->next=q;
        q->next=p;
        q=tmp;
        
    }
    return head;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* node1=new ListNode(2);
    ListNode* node2=new ListNode(1);
    ListNode* node3= new ListNode(3);
    ListNode* node4= new ListNode(1);
    node1->next=node2;
    //node2->next=node3;
    //node3->next=node4;
    
    ListNode* res= insertionSortList(node1);
    while(res){
        std::cout << res->val<<endl;
        res=res->next;
    }
    return 0;
}
