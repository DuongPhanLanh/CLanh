#include<iostream>
#include<cstdlib>
#include<vector>
#include <algorithm>
#define MAX 100

using namespace std;

void menu() {
	cout<<"\n";
    cout<<"Nhap 1 cho cau b: "<<"\n";
    cout<<"Nhap 2 cho cau c: "<<"\n";
    cout<<"Nhap 3 cho cau d: "<<"\n";
    cout<<"Nhap 4 cho cau e: "<<"\n";
    cout<<"Nhap 5 cho cau f: "<<"\n";
    cout<<"Nhap 6 cho cau g: "<<"\n";
    cout<<"Nhap 7 cho cau h: "<<"\n";
    cout<<"Nhap 8 cho cau i: "<<"\n";
    cout<<"Lua chon cau muon nhap: "<<"\n";
}
void NhapMang(int a[], int n) {
    for(int i=0;i<n;i++) {
        cout<<"Nhap mang i thu "<<i<<" la: ";
        cin>>a[i];
    }
}

void XuatMang(int a[], int n) {
    cout<<"Danh sach la: ";
    for(int i=0; i<n; i++) {
        cout<<a[i]<<",\t";
    }
}

void Xoa1PhanTu(int a[], int &n, int pos) {
    if(n<0) {
    	return ;
	}
	if(pos<0) {
		//xoa dau
		pos=0;
	}else if(pos>=n){
		//xoa cuoi
		pos = n-1;
	}	
	for(int i=pos; i<n-1;i++) {
		a[i]=a[i+1];
	}
	n--;
}

void CacPhanTuLonNhat(int a[], int n) {
	int max = a[0];
	for(int i=0; i<n;i++) {
		if(a[i]>max) {
			max=a[i];
		}
	}
	cout<<"Cac phan tu lon nhat la: ";
	for(int i=0; i<n;i++) {
		if(a[i]==max) {
			cout<<a[i];
		}
	}
}

void CacPhanTuNhoNhat(int a[], int n) {
	int min = a[0];
	for(int i=0; i<n;i++) {
		if(a[i]<min) {
			min=a[i];
		}
	}
	cout<<"Cac phan tu nho nhat la: ";
	for(int i=0; i<n;i++) {
		if(a[i]==min) {
			cout<<a[i];
		}
	}
}

void DemSoAm(int a[], int n) {
	int soAm=0;
	for(int i=0; i<n;i++) {
		if(a[i]<0) {
			soAm++;
		}
	}
	cout<<"Co "<<soAm<<" trong mang";
}

void SoAmLonNhat(int a[], int n) {
	int min=a[0];
	for(int i=0; i<n;i++) {
		if(a[i]<0 || a[i]<min) {
				min=a[i];
		}
	}
	cout<<"Co "<<min<<" la so am lon nhat(nho nhat) trong mang";
}

void SoDuongNhoNhat(int a[], int n) {
	int min=a[0];
	for(int i=0; i<n;i++) {
		if(a[i]>0 || a[i]<min) {
				min=a[i];
		}
	}
	cout<<"Co "<<min<<" la so duong nho nhat trong mang";
}

int timKiemNhiPhan(int a[], int n, int x) {
	sort(a, a + n);
	int left =0, right=n-1;
	while(left<=right) {
		int mid = left + (right - left) / 2;
		if(a[mid]==x) {
			return mid;
		}else if(a[mid]<x) {
			left=mid+1;
		}else{
			right=mid-1;
		}
	}
	return -1;
}

int DemBangtimKiemTuyenTinh(int a[], int n, int x) {
	int dem=0;
	for(int i=0;i<n;i++) {
		if(a[i]==x)
		dem++;
	}
	return dem;
}

int main() {
    int a[MAX];
    int n, x;
    
    cout<<"Nhap so luong n: ";
    cin>>n;

    NhapMang(a, n);
    XuatMang(a, n);
    int luaChon=0;
    do {
        menu();
        cin>>luaChon;
        switch (luaChon) {
        case 1:
        cout<<"Nhap vi tri thu i muon xoa: ";
        cin>>x;
        Xoa1PhanTu(a, n, x);
        XuatMang(a, n);
            break;
        case 2:
			CacPhanTuLonNhat(a, n);
        	break;
        case 3:
			CacPhanTuNhoNhat(a, n);
        	break;
        case 4:
			DemSoAm(a, n);
        	break;
        case 5:
			SoAmLonNhat(a, n);
        	break;
        case 6:
			SoDuongNhoNhat(a, n);
        	break;
//        case 7:
//			cout<<"Nhap gia tri x: ";
//            cin>>x;
//			int TKNP = timKiemNhiPhan(a, n, x);
//			if(TKNP !=-1){
//				cout<<"Tim thay "<<x<<"Xuat hien o vi tri thu: "<<TKNP;
//			}else {
//				cout<<"Ko ton tai";
//			}
//			break;
			
//        case 8: 
//        cout<<"Nhap gia tri x: ";
//            cin>>x;
//            int tim = DemBangtimKiemTuyenTinh(a, n, x);
//            if(tim >0){
//				cout<<"ta co so lan xuat hien cua  "<<x<<" phan tu can tim trong "<<tim;
//			}else {
//				cout<<"Ko ton tai";
//			}
//			break;
			
		case 7:
            cout << "Ket thuc chuong trinh.\n";
            break;
        default:
            break;
        }
    }while(luaChon!=9);
    


    return 0;

}
