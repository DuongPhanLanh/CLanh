#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct QLSach{
	int maSach;
	char tenSach[100];
	float gia;
};

void NhapSach(QLSach &sach) {
	cout<<"Nhap ma Sach: ";cin>>sach.maSach;
	cin.ignore();
	cout<<"Nhap ten Sach: ";
	cin.getline(sach.tenSach, 100);
	cout<<"Nhap gia tien: ";cin>>sach.gia;
}

void XuatSach(QLSach &sach) {
	cout<<"Ma sach: "<<sach.maSach;
	cout<<"Ten sach: "<<sach.tenSach;
	cout<<"Gia tien: "<<sach.gia;
}

// Tim kiem theo ma Sach
void TimKiemTuyenTinh_MaSach(QLSach sach[], int n, int maSach) {
    for (int i = 0; i < n; ++i) {
        if (sach[i].maSach == maSach) {
            cout << "Tim thay ma sach la: " << maSach << "\n";
            XuatSach(sach[i]);
            return; 
        }
    }
    cout << "Khong tim thay ma sach la: " << maSach << "\n";
}

bool sortMaSach(QLSach &a, QLSach &b) {
	return a.maSach <b.maSach;
}

void TimKiemNhiPhan_MaSach(QLSach sach[], int n, int maSach) {
	// duong dan con tro chi diem
    QLSach* sortedBooks = new QLSach[n];
    copy(sach, sach + n, sortedBooks);
    
    sort(sortedBooks, sortedBooks + n, sortMaSach);
    
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sortedBooks[mid].maSach == maSach) {
            cout << "Tim thay ma sach la: " << maSach << "\n";
            XuatSach(sortedBooks[mid]);
            //giai phong 
            delete[] sortedBooks;
            return;
        }
        if (sortedBooks[mid].maSach < maSach) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    delete[] sortedBooks;
    cout << "Khong tim thay ma sach la: " << maSach << "\n";
}

// Tim kiem theo ten Sach
void TimKiemTuyenTinh_TenSach(QLSach sach[], int n, char tenSach[]) {
    for (int i = 0; i < n; ++i) {
    	// so sach chuoi ky tu
        if (strcmp(sach[i].tenSach, tenSach)==0) {
            cout << "Tim thay ten sach la: " << tenSach << "\n";
            XuatSach(sach[i]);
            return; 
        }
    }
    cout << "Khong tim thay ten sach la: " << tenSach << "\n";
}

//bool sortTenSach(QLSach &a, QLSach &b) {
//	return strcmp(a.tenSach, b.tenSach) < 0;
//}
bool sortTenSach(const QLSach &a, const QLSach &b) {
    return strcmp(a.tenSach, b.tenSach) < 0;
}


//void TimKiemNhiPhan_TenSach(QLSach sach[], int n, char maSach[]) {
//	// duong dan con tro chi diem
//    QLSach* sortedBooks = new QLSach[n];
//    copy(sach, sach + n, sortedBooks);
//    
//    sort(sortedBooks, sortedBooks + n, sortTenSach);
//    
//    int left = 0, right = n - 1;
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        int cmp = strcmp(sortedBooks[mid].tenSach, tenSach);
//        if (cmp == 0) {
//            cout << "Tim thay ten sach la: " << tenSach << "\n";
//            XuatSach(sortedBooks[mid]);
//            delete[] sortedBooks;
//            return;
//        }
//        if (cmp < 0) {
//            left = mid + 1;
//        } else {
//            right = mid - 1;
//        }
//    }
//    delete[] sortedBooks;
//    cout << "KO Tim thay ten sach la: " << tenSach << "\n";
//}

void TimKiemNhiPhan_TenSach(QLSach sach[], int n, char tenSach[]) {
    QLSach* sortedBooks = new QLSach[n];
    copy(sach, sach + n, sortedBooks);
    
    sort(sortedBooks, sortedBooks + n, sortTenSach);
    
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(sortedBooks[mid].tenSach, tenSach);
        if (cmp == 0) {
            cout << "Tim thay sach voi ten: " << tenSach << "\n";
            XuatSach(sortedBooks[mid]);
            delete[] sortedBooks;
            return;
        }
        if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    delete[] sortedBooks;
    cout << "Khong tim thay sach voi ten: " << tenSach << "\n";
}

int main() {
	int n;
	cout<<"Nhap so luong n: ";cin>>n;
	while (n <= 0) {
        cout << "Nhap lai: ";
        cin >> n;
    }
    //QLSach sach[n];
    // cho no co the tim kiem ca so lan chu
    QLSach* sach = new QLSach[n];


    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin cho sach thu " << i + 1 << ":\n";
        NhapSach(sach[i]);
    }
    
    cout << "Danh sach cac sach da nhap:";
    for (int i = 0; i < n; ++i) {
        cout << "Sach thu " << i + 1 << ":\n";
        XuatSach(sach[i]);
        cout<<"\n";
    }
    
    int chon;
    do {
        cout << "Chon loai tim kiem:\n";
        cout << "1. Tim sach theo ma thu vien\n";
        cout << "2. Tim sach theo ten\n";
        cout << "3. Sap xep tang dan\n";
        cout << "Lua chon cua ban: ";
        cin >> chon;

        switch (chon) {
            case 1: {
                int maSach;
                cout << "Nhap ma ma sach tim: ";
                cin >> maSach;
                cout<<"Tim kiem tuyen tinh: ";
				TimKiemTuyenTinh_MaSach(sach,n, maSach);
				cout<<"\n";
                cout<<"Tim kiem nhi phan: ";
				TimKiemNhiPhan_MaSach(sach,n, maSach);
				cout<<"\n";
                break;
            }
            case 2: {
                char tenSach[100];
                cout << "Nhap ten sach tim: ";
                cin.ignore(); 
                cin.getline(tenSach, 100);
                
                cout<<"Tim kiem tuyen tinh: ";
				TimKiemTuyenTinh_TenSach(sach,n, tenSach);
				cout<<"\n";
                cout<<"Tim kiem nhi phan: ";
				TimKiemNhiPhan_TenSach(sach,n, tenSach);
				cout<<"\n";
                break;
            }
            case 3:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lai.\n";
        }
    } while (chon != 3);

    return 0;
}


