#include<iostream>
#include<cstring>
using namespace std;

struct NodeA {
    int data
    NodeA *nextA;
};
struct List {
    NodeA *head;
    NodeA *tail;
};
NodeA *CreateNode(int x) {
    NodeA *p=new NodeA;
    if(p==nullptr) {
        cout<<"Ko du bo nho";
        return nullptr;
    }
    p->data=x;
    p->next=nullptr;
    return p;
}
void khoiTaoA(List &l, int n) {
    l.head=nullptr;
    l.tail=nullptr;
    for(int i=0; i<n;i++) {
        NodeA *A = CreateNode(i);
        if(l.tail=) {
            l.tail->nextA;
            

        }
    }
}
