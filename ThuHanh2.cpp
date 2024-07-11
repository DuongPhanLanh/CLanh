#include<iostream>
#include <algorithm>
#define MAX 100
using namespace std;

int timKiemTuyenTinh(int arr[], int n, int x) {
	for(int i=0;i<n;i++) {
		if(arr[i]==x)
		return i;
	}
	return -1;
}

int timKiemNhiPhan(int arr[], int n, int x) {
	int left =0, right=n-1;
	while(left<=right) {
		//int mid=(left-right)/2;
		int mid = left + (right - left) / 2;
		if(arr[mid]==x) {
			return mid;
		}else if(arr[mid]<x) {
			left=mid+1;
		}else{
			right=mid-1;
		}
	}
	return -1;
}

int main() {
	int n, x, arr[MAX];
	cout<<"Nhap so luong n: ";cin>>n;
	while(n<=0) {
		cout<<"Nhap lai: ";
		cin>>n;
	}
	for(int i=0;i<n;i++){
		cout<<"Nhap so arr thu "<< i + 1 << ": ";cin>>arr[i];
	}
	cout<<"Ta co Mang la: ";
	for(int i=0;i<n;i++){
		cout<<arr[i];
	}
	cout<<endl;
	
	
	cout<<"Nhap gia tri can tim: ";cin>>x;
	//Tim kiem tuyen tinh
	int TKTT = timKiemTuyenTinh(arr, n, x);
	if(TKTT !=-1){
		cout<<"Xuat hien o vi tri thu: "<<TKTT;
	}else {
		cout<<"Ko ton tai";
	}
	
	sort(arr, arr + n);
	int TKNP = timKiemNhiPhan(arr, n, x);
	if(TKNP !=-1){
		cout<<"Xuat hien o vi tri thu: "<<TKNP;
	}else {
		cout<<"Ko ton tai";
	}
	return 0;
}
