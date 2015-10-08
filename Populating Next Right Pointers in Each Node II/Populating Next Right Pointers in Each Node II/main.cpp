//
//  main.cpp
//  Populating Next Right Pointers in Each Node II
//
//  Created by Andy Zhu on 11/9/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

//
//  main.cpp
//  Populating Next Right Pointers in Each Node
//
//  Created by Andy Zhu on 11/1/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
using namespace std;
struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int val): val(val), left(NULL), right(NULL),next(NULL){};
};

void connect(TreeLinkNode *root) {
    if (root == NULL )
        return;

    
    if (root->left !=NULL){
        if(root->right!=NULL)
            root->left->next = root->right;
        
        else if(root->next!=NULL){
            TreeLinkNode* next = root->next;
            while(next!=NULL && next->left==NULL && next->right==NULL)
                next= next->next;
            if(next!=NULL)
                root->left->next = (next->left !=NULL)? next->left:next->right;
            
        }
        
    }
    
    if(root->next != NULL && root->right!=NULL){
        TreeLinkNode* next = root->next;
        while(next!=NULL && next->left==NULL && next->right==NULL)
            next= next->next;
        if(next!=NULL)
            root->right->next = (next->left !=NULL)? next->left: next->right;
    }
    connect(root->right);
    connect(root->left);
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeLinkNode* root = new TreeLinkNode(2);
    TreeLinkNode* node1 = new TreeLinkNode(1);
    TreeLinkNode* node2 = new TreeLinkNode(3);
    TreeLinkNode* node3 = new TreeLinkNode(0);
    TreeLinkNode* node4 = new TreeLinkNode(7);
    TreeLinkNode* node5 = new TreeLinkNode(9);
    TreeLinkNode* node6 = new TreeLinkNode(1);
    TreeLinkNode* node7 = new TreeLinkNode(2);
    TreeLinkNode* node8 = new TreeLinkNode(1);
    TreeLinkNode* node9 = new TreeLinkNode(0);
    TreeLinkNode* node10 = new TreeLinkNode(8);
    TreeLinkNode* node11 = new TreeLinkNode(8);
    TreeLinkNode* node12 = new TreeLinkNode(7);
    //TreeLinkNode* node13 = new TreeLinkNode();
    //TreeLinkNode* node14 = new TreeLinkNode();
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    
    node2->left = node5;
    node2->right = node6;
    node3->left = node7;
    //node3->right = node8;
    node4->left = node8;
    node4->right = node9;
    //node5->left = node11;
    //node5->right = node7;
    node6->left = node10;
    node6->right = node11;
    
    connect(root);
    TreeLinkNode* cursor = root;

    
    std::cout << "Hello, World!\n";
    return 0;
}
