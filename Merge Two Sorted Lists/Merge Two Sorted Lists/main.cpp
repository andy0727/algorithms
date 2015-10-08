//
//  main.cpp
//  Merge Two Sorted Lists
//
//  Created by Andy Zhu on 11/3/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

/*
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode* res;
    if(l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    
    if (l1->val <= l2->val){
        res = l1;
        res->next = mergeTwoLists(l1->next, l2);
        
    }
    else{
        res= l2;
        res->next = mergeTwoLists(l1, l2->next);
    }
    
    return res;
    
    
}
*/

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode* cursor1 = l1;
    ListNode* cursor2 = l2;
    ListNode* res= NULL;
    ListNode* cursor3= NULL;
    while (cursor1 != NULL || cursor2 != NULL){

        
        if (cursor1 == NULL){
            if (res == NULL){
                res= cursor2;
                cursor3 = res;
            }
            else
                cursor3->next = cursor2;
            break;
        }
        
        
        if (cursor2 == NULL){
            if (res== NULL){
                res= cursor1;
                cursor3=res;
            }
            else
                cursor3->next = cursor1;
            break;
        }

        
        if (cursor1->val <= cursor2->val)
        {
            if (res == NULL){
                res = cursor1;
                cursor3 = res;
            }
            
            else{
                
                cursor3->next = cursor1;
                cursor3= cursor3->next;
            }
            cursor1 = cursor1->next;
        }
        
        else
        {
            if (res == NULL){
                res= cursor2;
                cursor3= res;
            }
            else{
                cursor3->next = cursor2;
                cursor3= cursor3->next;
            }
            cursor2= cursor2->next;
        }
        
    }
    return res;
        
}
int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* node1= new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    node1->next = node3;
    ListNode* res = mergeTwoLists(node1,node2);
    while (res != NULL){
        cout<<res->val<<endl;
        res= res->next;
        
    }
    std::cout << "Hello, World!\n";
    return 0;
}
