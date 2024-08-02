#include<iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
};
struct stack {
    Node *top;
};
Node *CreateNode(int x) {
    Node *p=new Node;
    if(p==nullptr) {
        cout<<"Ko du bo nho";
        return nullptr;
    }
    p->data=x;
    p->next=nullptr;
    return p;
}
void Init(stack &s) {
    s.top=nullptr;
}
int isEmpty(stack &s) {
    if(s.top ==nullptr) {
        return 1;
    }
    return 0;
}
void Push(stack &s, int x) {
    Node *newNode = CreateNode(x);
    if(newNode !=nullptr) {
        if(isEmpty(s)) {
            s.top=newNode;
        }else {
            newNode->next = s.top;
            s.top = newNode;
        }
    }
}
void pop(stack &s, int &x) {
    if(isEmpty(s)==1) {
        cout<<"Ko du bo nho";
        return;
    } 
    Node *p = s.top;
    s.top = s.top->next;
    x = p->data;
    delete p;
}
void DoiCoSo(stack &s, int x, int n) {
    while (n!=0)
    {
       int a = n%x;
       Push(s, a);
       n /=x;
    }  
}
void Xuat(stack &s) {
    stack temp = s;
    while (!isEmpty(temp))
    {
        int x;
        pop(temp, x);
        cout<<x;
    }
    
}
int main() {
    stack s;
    Init(s);
    int x, n;
    cout<<"Nhap gia tri can chuyen: ";
    cin>>x;
    cout<<"Nhap so 2 de chuyen: ";
    cin>>n;
    DoiCoSo(s, n, x);
    Xuat(s);
}
