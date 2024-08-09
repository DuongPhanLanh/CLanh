// 1. Cho một dãy số như sau 18, 12, 8, 10, 6, 4, 2.
// a. Cai dat thuat toan tim kiem nhi phan theo thu tu giam dan
//b. Tim gia tri 20 trong da so vua cho

//2. Cho mang so nguyen nhu sau 85, 65, 64, 25, 13, 12, 22, 11
//a. Sử dụng thuật toán chọn trực tiếp sắp xếp mảng tăng dần
//b. Tim gia tri 100 trong mang vua cho

// 3. 
// a.Tao 1 cau truc du lieu stack 
// b. viết hanmf khởi tạo node
// c. viết hàm khởi tạo stack
// d. viết hàm tạo stack rỗng
// e. viết hàm viết hàm push 1 phan tu vao stack

// 4. Cho 1 mang so a nhu sau 38, 81, 22, 48, 13
// a. su dung thuat toan bullbeSort sap xep mang tang dan

#include <iostream>
#include <algorithm>
# define MAX 100
using namespace std;

//Cau 1
int BinarySearch(int a[], int n, int x) {
    int left, right, mid;
    left=0; right = n-1;
    do{
        mid=(left+right)/2;
        if(a[mid]==x) return 1;
        else if(a[mid]>x)
            left=mid+1;
        else 
            right=mid-1;
    }while(left<=right);
    return 0;
}

// Cau 2
void swap(int &a, int &b) {
    int temp=a;
    a=b;
    b=temp;
}
int SelectionSort(int a[], int n) {
    int max;
    for(int i=0;i<n-1;i++) 
        for(int j=i+1;j<n;j++) {
            max=i;
            if(a[j]>max)
                max=j;
                swap(a[i], a[j]);
        }
}

//Cau 3
//a.
struct Node {
    int data;
    Node *next;
};
struct Stack {
    Node *top;
};
//b.
Node *createNode(int x) {
    Node *p=new Node;
    if(p==nullptr) {
        printf("Ko du bo nho");
        return nullptr;
    }
    p->data=x;
    p->next=nullptr;
    return p;
}
//c. 
void Init(Stack &s) {
    s.top=nullptr;
}
//d.
bool isEmty(Stack s) {
    if(s.top==nullptr) {
        return 1;
    }    
    return 0;
} 
//e.
int push(Stack &s, int x) {
    Node *newNode = createNode(x);
    if(newNode !=nullptr) {
        newNode->next=s.top;
        s.top=newNode;
    }
}

//Cau 4
void BubbleSort(int a[], int n) {
    for(int i=0;i<n-1;i++) 
        for(int j=n-1; j>i;j--) {
            if(a[j]<a[j-1]) {
                swap(a[j], a[j-1]);
            }
        }
}

// NHAP-XUAT
void NhapMang(int a[], int n) {
    for(int i=0;i<n;i++) {
        cout<<"Nhap so i thu "<<i<<" la: ";
        cin>>a[i];
    }
}

void XuatMang(int a[], int n) {
    cout<<"Danh sach la: "<<"\n";
    for(int i=0;i<n;i++) {
        cout<<a[i];
    }
    cout<<"\n";
}

int main() {
     int a[MAX];
     int n, x;
     cout<<"Nhap so luong n: ";cin>>n;
     NhapMang(a, n);
     
     XuatMang(a, n);
     
    //  SelectionSort(a, n);
    //  XuatMang(a, n);

     BubbleSort(a, n);
     XuatMang(a, n);
     cout<<"\nNhap so muon tim: ";
     cin>>x;
     if(BinarySearch(a, n, x)){
        cout<<"Co gia tri"<<x<<"trong mang";
     }else{
        cout<<"Ko co";
     }
     return 0;
}
