#include<iostream>
#include<cstring>

using namespace std;

struct SinhVien {
    int maSv;
    char tenSv[100];
    int namSinh;
    double diemTB;
};

struct Node {
    SinhVien *data;
    Node *next;
};

struct List {
    Node *head;
};

SinhVien *nhapSV() {
    SinhVien *sv = new SinhVien;
    cout<<"\nNhap maSV: ";
    cin>>sv->maSv;
    cin.ignore();
    cout<<"\nNhap tenSV: ";
    cin.getline(sv->tenSv, sizeof(sv->tenSv));
    cout<<"\nNhap namSinh: ";
    cin>>sv->namSinh;
    cout<<"\nNhap diemTB: ";
    cin>>sv->diemTB;
    return sv;
};

void xuatSV(List *l) {
    Node *pNode = l->head;
    if(pNode==nullptr) {
        cout<<"\nKo du bo nho";
        return;
    }
    while (pNode!=nullptr)
    {
        SinhVien *sv = pNode->data;
        cout<<sv->maSv;
        cout<<sv->tenSv;
        cout<<sv->namSinh;
        cout<<sv->diemTB;
        pNode = pNode->next;
    }
    
}

Node *CreateSV(SinhVien *sv) {
    Node *p=new Node;
    if(p==nullptr) {
        cout<<"\nKo du bo nho";
        return nullptr;
    }
    p->data = sv;
    p->next = nullptr;
    return p;
}

//Them dau danh sach
void ThemDau(List *l, SinhVien *sv) {
    Node *pNode = CreateSV(sv);
    if(l->head==nullptr) {
        l->head = pNode;
        pNode->next = nullptr;
    }else {
        pNode->next = l->head;
        l->head = pNode;
    }
}

//Them cuoi danh sach
void ThemCuoi(List *l, SinhVien *sv) {
    Node *pNode = CreateSV(sv);
    if(l->head==nullptr) {
        l->head = pNode;
    }else {
        Node *cuoi = l->head;
        while (cuoi->next !=nullptr)
        {
            cuoi = cuoi->next;
        }
        cuoi->next = pNode;
    }
}

//In danh sach SV diemTB <=5
void xuatDiemSVNhoHon5(List *l) {
    Node *pNode = l->head;
    if(pNode==nullptr) {
        cout<<"\nKo du bo nho";
        return;
    }
    while (pNode!=nullptr)
    {
        SinhVien *sv = pNode->data;
        if(sv->diemTB<=5) {
            cout<<"\nMaSV:"<<sv->maSv;
            cout<<"\nTenSV: "<<sv->tenSv;
            cout<<"\nNamSinh: "<<sv->namSinh;
            cout<<"\nDiemTB: "<<sv->diemTB;
        }
        pNode = pNode->next;
    }  
}

//Xoa cac SinhVien co namSinh la 2000
void XoaSVNam200(List *l, int nam) {
    Node *pDel = l->head;
    Node *pPer=nullptr;
        while (pDel->next!=nullptr) {
            SinhVien *sv = pDel->data;
            if(sv->maSv==nam) {
                if(pDel==l->head) {
                    l->head = l->head->next;
                    delete pDel->data;
                    delete pDel;
                    pDel =l->head;
                }else {
                    pPer->next = pDel->next;
                    delete pDel->data;
                    delete pDel;
                    pDel = pPer->next;
                }
            }else {
                pPer=pDel;
                pDel=pDel->next;
            }
        }   
}           

//Sap xep tang danh diemTB
void swap(int *&a, int *&b) {
    int *temp = a;
    a=b;
    b=temp;
}

void InterchangeSort_Asc(List *l) {
    if(l->head ==nullptr) return;
    Node *p, *q;
    for(p=l->head; p !=nullptr;p=p->next) {
        for(q=p->next; q !=nullptr; q=q->next) {
            if(p->data->diemTB > q->data->diemTB) {
                swap(p->data, q->data);
            }
        }
    }      
}

// Xoa tat ca nhung xuat danh sach xoa
void xuatAfterDelete(List *l) {
    if(l->head==nullptr) {
        cout<<"\nKo du bo nho";
        return;
    }
    Node *pNode = l->head;
    while(pNode !=nullptr) {
        SinhVien *sv = pNode->data;
        cout<<"\nMaSV:"<<sv->maSv;
        cout<<"\nTenSV: "<<sv->tenSv;
        cout<<"\nNamSinh: "<<sv->namSinh;
        cout<<"\nDiemTB: "<<sv->diemTB;

        Node *pNode1 = pNode;
        pNode = pNode->next;
        delete pNode1->data;
        delete pNode1;
    }
    l->head=nullptr;
}

int main() {
    List l;
    l.head = nullptr;

    int luaChon;
    do
    {
        cout<<"\nNhap 1 de thuc hien cau 1";
        cout<<"\nNhap 2 de thuc hien cau 2";
        cout<<"\nNhap 7 de thuc hien xuat gia tri";
        cout<<"\nNhap 3 de thuc hien cau 3";
        cout<<"\nNhap 4 de thuc hien cau 4";
        cout<<"\nNhap 5 de thuc hien cau 5";
        cout<<"\nNhap 6 de thuc hien cau 6";
        cout<<"\nNhap cac so con lai de thoat";
        cin>>luaChon;
        cin.ignore();
       switch (luaChon) {
            case 1: {
                SinhVien *sv = nhapSV();
                ThemDau(&l, sv);
                break;
            }
            case 2: {
                SinhVien *sv = nhapSV();
                ThemCuoi(&l, sv);
                break;
            }
            case 3:
                xuatDiemSVNhoHon5(&l);
                break;
            case 4:
                XoaSVNam200(&l, 2000);
                break;
            case 5:
                InterchangeSort_Asc(&l);
                cout << "\nDanh sach da sap xep";
                break;
            case 6:
                xuatAfterDelete(&l);
                cout << "\nDanh sach da dc xoa";
                break;
            case 7:
                xuatSV(&l);
                break;
            default:
                cout << "\nLua chon khong hop le.";
                break;
        }
    } while (luaChon != 0);
    return 0;
}
