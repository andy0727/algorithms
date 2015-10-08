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
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
};

void connect(TreeLinkNode *root) {
    if (root == NULL )
        return;
    
    if (root->left !=NULL){
        root->left->next = root->right;
        connect(root->left);
    }
    
    if(root->next != NULL && root->right!=NULL){
        root->right->next = root->next->left;
    }
    if (root->right !=NULL)
        connect(root->right);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeLinkNode* root = new TreeLinkNode();
    TreeLinkNode* node1 = new TreeLinkNode();
    TreeLinkNode* node2 = new TreeLinkNode();
    TreeLinkNode* node3 = new TreeLinkNode();
    TreeLinkNode* node4 = new TreeLinkNode();
    TreeLinkNode* node5 = new TreeLinkNode();
    TreeLinkNode* node6 = new TreeLinkNode();
    TreeLinkNode* node7 = new TreeLinkNode();
    TreeLinkNode* node8 = new TreeLinkNode();
    TreeLinkNode* node9 = new TreeLinkNode();
    TreeLinkNode* node10 = new TreeLinkNode();
    TreeLinkNode* node11 = new TreeLinkNode();
    TreeLinkNode* node12 = new TreeLinkNode();
    TreeLinkNode* node13 = new TreeLinkNode();
    TreeLinkNode* node14 = new TreeLinkNode();
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;
    node3->left = node7;
    node3->right = node8;
    node4->left = node9;
    node4->right = node10;
    node5->left = node11;
    node5->right = node12;
    node6->left = node13;
    node6->right = node14;
    connect(root);
    TreeLinkNode* cursor = root;
    while (cursor != NULL){
        if (cursor->next != NULL)
            cursor= cursor->left;
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
