#include<iostream>
#include <cstdlib>
#include <ctime>
#define MAX 100
using namespace std;

void MangNgauNhien(int a[], int n) {
    for(int i=0;i<n;i++) {
         a[i] = rand() % 199 - 99;
    }
}

void XuatMang(int a[], int n) {
    cout<<"Danh sach la: ";
    for(int i=0;i<n;i++) {
        cout<<a[i]<<",\t";
    }
    cout<<"\n";
}

void swap(int &a, int &b) {
    int temp = a; 
    a=b;
    b=temp;
}

void CauA_SelectionSort(int a[], int n) {
    // so am tang dan dau day
    for(int i=0; i<n-1;i++) {
        int min=i;
        for(int j=i+1; j<n;j++) {
            if(a[j]<a[min] && a[j]<0) {
                min=j;
            }
        }
        if (min != i) {
            swap(a[min], a[i]);
        }
    }

    // so ko am ( so duong) giam dan cuoi day
    for(int i=n-1; i>0;i--) {
        int max=i;
        for(int j=i-1; j>=0;j--) {
            if(a[j]>a[max] && a[j]>0) {
                max=j;
            }
        }
        if (max != i) {
            swap(a[max], a[i]);
        }
    }
}

void CauB_InsertionSort(int a[], int n) {
    int pos, x;
    // so ko am tang dan ben phai
    for(int i=0;i<n;i++) {
        x=a[i];
        pos=i-1;
        if(a[pos]>=0) 
            while (pos >= 0 && a[pos] >= 0 && a[pos] < x)
        {
            a[pos+1]=a[pos];
            pos--;
        }
        a[pos+1]=x;
    }

    // so am giam dan ben trai
    for(int i=n-2;i>0;i--) {
        x=a[i];
        pos=i+1;
        if(a[pos]<=0) 
            while(pos<0 && a[pos]<=0 && a[pos]>x) 
            {
                a[pos-1] = a[pos];
                pos++;
            }
            a[pos-1]=x;
    }
}

void CauC_QuickSort(int a[], int left, int right) {
    int i, j, x;
    if(left>=right)
    return;
    x=a[(left+right)/2];
    i=left, j=right;
    do {
        while(a[i]<x &&a[j]<0)
            i++;
        while(a[j]>x &&a[i]>0)
            j--;
        if(i<=j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(left<j)
    CauC_QuickSort(a, j+1, left);
    if(right>i)
    CauC_QuickSort(a, right, i+1);
}

void CauD_QuickSort(int a[], int left, int right) {
    int i, j, x;
    if(left>=right)
    return;
    x=a[(left+right)/2];
    i=left, j=right;
    do {
        while(a[i]>x && a[j]<0)
        i++;
        while(a[j]<x && a[i]>0)
        j--;
        if(i<=j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(left>j)
    CauD_QuickSort(a, j+1, left);
    if(right<i)
    CauD_QuickSort(a, right, i+1);
}

int main() {
    int a[MAX];
    int n;
    cout<<"Nhap so luong n: ";
    cin>>n;

    srand(time(0));
    MangNgauNhien(a, n);
    XuatMang(a, n);

    cout<<"Cau a: "<<"\n";
    CauA_SelectionSort(a, n);
    XuatMang(a, n);

    cout<<"Cau b: "<<"\n";
    CauB_InsertionSort(a, n);
    XuatMang(a, n);

    cout<<"Cau c: "<<"\n";
    CauC_QuickSort(a, 0, n-1);
    XuatMang(a, n);

    cout<<"Cau d: "<<"\n";
    CauD_QuickSort(a, 0, n-1);
    XuatMang(a, n);
    
    return 0;
}