#include<iostream>
#include<algorithm>
#include<cstring>

#include<cstdlib>
#include <ctime>
#define MAX 100

using namespace std;

// Cau 1
//void Nhap(int arr[], int n) {
//	for(int i=0;i<n;i++) {
//			cout<<"Nhap so phan tu thu"<< i+1<<" :\n";
//		    cin>>arr[i];
//		}
//	}

// Cau 6
//void NhapNgauNhien(int arr[], int n) {
//	for(int i=0;i<n;i++) {
//		arr[i] = rand() %100;
//	}			
//	}

// Cau 7	
void NhapNgauNhienTangDan(int arr[], int n) {
	for(int i=0;i<n;i++) {
		arr[0] = rand() %100;
		arr[i] = arr[i-1] +rand()%100;
	}
}
	

void Xuat(int arr[], int n) {
	cout<<"Danh sach mang la: ";
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<"\n";
	}
}

void TongMang(int arr[], int n) {
	int tong=0;
	for(int i=0;i<n;i++) {
		tong +=arr[i];
	}
	cout<<"Tong mang la: "<<tong<<"\n";
}

// Cau 3
void TimSoChan(int arr[], int n) {
	for(int i=0;i<n;i++) {
		if(arr[i]%2==0 ) {
			cout<<"Danh sach mang la so chan: ";
			cout<<arr[i]<<"\n";
		}	
	}
}

// Cau 5, 8
void TimKiemTuyenTinh(int arr[], int n, int x) {
	for(int i=0;i<n;i++) {
		if(arr[i]==x)
			cout<<"Ket qua tuyen tinh o vi tri thu: "<<i<<"\n";
	}
	//cout<<"Ko tim thay"<<"\n";
}

// Cau 9
void TimKiemNhiPhan(int arr[], int n, int x) {
	int left = 0, right=n-1;
		while(left<=right) {
			int mid = left+(right-left)/2;
			if(arr[mid]==x) {
				cout<<"Ket qua nhi phan o vi tri thu: "<<mid<<"\n";
				break;
			}else if(arr[mid]>x) {
				right=mid-1;
			}else {
				left=mid+1;
			}
		}
		//cout<<"Ko tim thay"<<"\n";
}

//Cau 10
struct SanPham{
	int MaSP;
	char TenSP[100];
	float GiaBan;
};

void NhapSP(SanPham &sp) {
	cout<<"Nhap ma san pham: ";cin>>sp.MaSP;
	cin.ignore();
	cout<<"Nhap ten san pham: ";cin.getline(sp.TenSP, 100);
	cout<<"Nhap gia san pham: ";cin>>sp.GiaBan;
}

void XuatSP(SanPham &sp) {
	cout<<"ma la:"<<sp.MaSP;
	cout<<"ten la: "<<sp.TenSP;
	cout<<"gia la: "<<sp.GiaBan;	
}

void TimKiemTuyenTinh_MaSP(SanPham sp[], int n, int maSP) {
	for(int i=0;i<n;i++) {
		if(sp[i].MaSP==maSP) {
			XuatSP(sp[i]);
			return;
		}
	}
}



int main() {
	int n, x, sp, MSP;
	int arr[MAX];
	cout<<"Nhap so luong phan tu: ";cin>>n;
	if(n<=0 || n>MAX) {
		cout<<"Nhap ko hop le";
		return 1;
	}else {
		srand(time(NULL));
//	    NhapNgauNhien(arr, n);
	    NhapNgauNhienTangDan(arr, n);
//		Nhap(arr, n);
	    Xuat(arr, n);
	    TongMang(arr, n);
	    TimSoChan(arr, n);
	}

	
cout<<"Nhap so can tim: ";cin>>x;
	
	
	TimKiemTuyenTinh(arr, n, x);
	
	sort(arr, arr+n);
	TimKiemNhiPhan(arr, n, x);
	
	
cout<<"Nhap san pham: ";cin>>sp;
SanPham* sanpham = new SanPham[sp];

for(int i=0;i<n;i++) {
	cout<<"Nhap san pham"<<"\n";
	NhapSP(sanpham[i]);
}
for(int i=0;i<n;i++) {
	cout<<"Danh sach thu: "<<i+1<<"\n";
	XuatSP(sanpham[i]);
}

cout<<"Nhap ma can tim: ";cin>>MSP;
TimKiemTuyenTinh_MaSP(sanpham, sp, MSP);

	return 0;
}
