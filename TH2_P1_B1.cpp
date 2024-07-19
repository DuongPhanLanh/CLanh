#include<iostream>
#define MAX 100
using namespace std;

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

void swap(int &a, int &b) {
    int temp = a;
    a=b;
    b=temp;
}

void tang_InterchangeSort(int a[], int n) {
    for(int i=0;i<n-1;i++) 
        for(int j=i+1;j<n;j++) {
            // tang dan
            if(a[i]>a[j]) {
                swap(a[i], a[j]);
            }
        }
}

void giam_InterchangeSort(int a[], int n) {
    for(int i=0;i<n-1;i++) 
        for(int j=i+1;j<n;j++) {
            if(a[i]<a[j]) {
                swap(a[i], a[j]);
            }
        }
}

void tang_SelectionSort(int a[], int n) {
    int max;
    for(int i=0;i<n-1;i++) 
        for(int j=i+1;j<n;j++) {
            max=i;
            if(a[j]>max)
                max=j;
                swap(a[i], a[j]);
        }
}

void giam_SelectionSort(int a[], int n) {
    int min;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++) {
            min=i;
            if(a[j]<min)
                min=j;
                swap(a[i], a[j]);
        }
}

void tang_InsertionSort(int a[], int n) {
    int pos, x;
    for(int i=1;i<n;i++) {
        // Buoc 1
        x=a[i+1];
        //Buoc 2
        pos=i;
        // Buoc 3
        while(pos>=0 && a[pos]>x) {
            // Buoc 4
            a[pos+1] = a[pos];
            pos--;
        }
        a[pos]=x;
    }
}

void tang_BubbleSort(int a[], int n) {
    for(int i=0;i<n-1;i++) 
        for(int j=n-1; j>i;j--) {
            if(a[j]<a[j-1]) {
                swap(a[j], a[j-1]);
            }
        }
}

int main() {
    int a[MAX];
    int n;
    cout<<"Nhap so luong n: "<<"\t";
    cin>>n;

    NhapMang(a, n);
    XuatMang(a, n);

    // tang dan bang pp doi cho truc tiep
    cout<<"Sap xep TANG doi cho truc tiep: "<<"\n";
    tang_InterchangeSort(a, n);
    XuatMang(a, n);

    // giam dan bang pp doi cho truc tiep
    cout<<"Sap xep GIAM doi cho truc tiep: "<<"\n";
    giam_InterchangeSort(a, n);
    XuatMang(a, n);

    // tang dan bang pp chon truc tiep
    cout<<"Sap xep TANG chon truc tiep: "<<"\n";
    tang_SelectionSort(a, n);
    XuatMang(a, n);

    // giam dan bang pp chon truc tiep
    cout<<"Sap xep Giam chon truc tiep: "<<"\n";
    giam_SelectionSort(a, n);
    XuatMang(a, n);

    // tang dan bang pp chen truc tiep
    cout<<"Sap xep TANG chen truc tiep: "<<"\n";
    tang_SelectionSort(a, n);
    XuatMang(a, n);

    // tang dan bang pp chen truc tiep
    cout<<"Sap xep TANG noi bot: "<<"\n";
    tang_BubbleSort(a, n);
    XuatMang(a, n);


}