//
//  main.cpp
//  Clone Graph
//
//  Created by Andy Zhu on 12/16/14.
//  Copyright (c) 2014 Andy Zhu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct LinkedList{
    int val;
    LinkedList* next;
    LinkedList(int val): val(val) {};
    
};

struct UndirectedGraphNode {
        int label;
        vector<UndirectedGraphNode *> neighbors;
        UndirectedGraphNode(int x) : label(x) {};
};

LinkedList* reverseList(LinkedList* head){
    if(!head)
        return NULL;
    LinkedList* p = head;
    LinkedList* pre = NULL;
    LinkedList* next;
    while(p){
        next=p->next;
        p->next = pre;
        pre= p;
        p=next;
    }
    return pre;
}

void reverseList_rec(LinkedList* head){
    if(!head)
        return;
    if(!head->next)
        return;
    LinkedList* node = head->next;
    reverseList_rec(node);
    head->next->next=head;
    head->next=NULL;
    head = head->next;
    head = node;
}
UndirectedGraphNode *dfs(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>& visited) {
    UndirectedGraphNode* res=new UndirectedGraphNode(node->label);
    visited[node] = res;
    for (UndirectedGraphNode* m:node->neighbors){
        if(visited.count(m)>0)
            res->neighbors.push_back(visited[m]);
        else
            res->neighbors.push_back(dfs(m,visited));
    }
    return res;
}
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
    if(!node)
        return NULL;
    return dfs(node,visited);
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    UndirectedGraphNode* node1= new UndirectedGraphNode(1);
    UndirectedGraphNode* node2= new UndirectedGraphNode(1);
    UndirectedGraphNode* node3= new UndirectedGraphNode(1);
    node1->neighbors.push_back(node1);
    node1->neighbors.push_back(node1);
    //node1->neighbors.push_back(node2);
    //node1->neighbors.push_back(node3);
    UndirectedGraphNode* res = cloneGraph(node1);
    std::cout << "Hello, World!\n";
    return 0;
}
