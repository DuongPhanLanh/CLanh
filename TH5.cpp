#include<iostream>

using namespace std;

typedef struct tagTNode {
    int data;
    struct tagTNode *pLeft, *pRight;
} TNode;

typedef TNode* Tree;

TNode *createNode(int x) {
    TNode *p= new TNode;
    if(!p) return nullptr;
    p->data = x;
    p->pLeft=nullptr;
    p->pRight=nullptr;
    return p;
}
Tree insertNode(Tree root, int x) {
    if(root==nullptr) {
        return createNode(x);
    }
    if(x < root->data) {
        root->pLeft = insertNode(root->pLeft, x);
    }else {
        root->pRight = insertNode(root->pRight,x);
    }
    return root;
}
Tree xuatTree() {
    Tree root = nullptr;
    int x, n;
    cout<<"\nNhap so luong n cay: ";
    cin>>n;
    cout<<"\nNhap gia tr cac cay: ";
    for(int i=0;i<n;i++) {
        cin>>x;
        root = insertNode(root, x);
    }
    return root;
}
void destroyTree(Tree root) {
    if (root != nullptr) {
        destroyTree(root->pLeft);
        destroyTree(root->pRight);
        delete root;
    }
}
//Cau 1
void LNR(Tree root) {
    if(root !=nullptr) {
        LNR(root->pLeft);
        cout<<root->data;
        LNR(root->pRight);
    }
}
void LRN(Tree root) {
    if(root !=nullptr) {
        LRN(root->pLeft);
        LRN(root->pRight);
        cout<<root->data;
    }
}
void NLR(Tree root) {
    if(root !=nullptr) {
        cout<<root->data;
        NLR(root->pLeft);
        NLR(root->pRight);
    }
}

void NRL(Tree root) {
    if(root !=nullptr) {
        cout<<root->data;
        NRL(root->pRight);
        NRL(root->pLeft);
    }
}
void RNL(Tree root) {
    if(root !=nullptr) {
        RNL(root->pRight);
        cout<<root->data;
        RNL(root->pLeft); 
    }
}
void RLN(Tree root) {
    if(root !=nullptr) {
        RLN(root->pRight);
        RLN(root->pLeft);
        cout<<root->data;
    }
}

//Cau 2
TNode *searchNode(Tree T, int x) {
    TNode *p=T;
    while(p!=nullptr) {
        if(x==p->data) return p;
        else if(x<p->data)
            p=p->pLeft;
        else 
            p=p->pRight;
    }
    return nullptr;
}

//Cau 3
void ChangeSearch(Tree &p, Tree &q) {
    if(q->pLeft) {
        ChangeSearch(p, q->pLeft);
    }else {
        p->data = q->data;
        p=q;
        q=q->pRight;
    }
}
int delNode(Tree &T, int x) {
    if(T==nullptr) return 0;
    if(T->data > x)
        delNode(T->pLeft, x);
    if(T->data <x)
        delNode(T->pRight, x);
    else {
        TNode*p=T;
        if(T->pLeft==nullptr)
        T=T->pRight;
        else if(T->pRight ==nullptr)
            T=T->pLeft;
            else {
                TNode*q=T->pRight;
                ChangeSearch(p,q);
            }
            delete p;
    }
}

//Cau 4
int TongNode(Tree root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + TongNode(root->pLeft) + TongNode(root->pRight);
}

//Cau 5
int Node2Cay(Tree root) {
    if (root == nullptr) {
        return 0;
    }
    int count = (root->pLeft != nullptr && root->pRight != nullptr) ? 1 : 0;
    return count + Node2Cay(root->pLeft) + Node2Cay(root->pRight);
}

//Cau 6, Cau 7
int Node1Cay(Tree root) {
    if (root == nullptr) {
        return 0;
    }
    int count = ((root->pLeft != nullptr && root->pRight == nullptr) || (root->pLeft == nullptr && root->pRight != nullptr)) ? 1 : 0;
    return count + Node1Cay(root->pLeft) + Node1Cay(root->pRight);
}

// Cau 8
int SoNode(Tree root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->pLeft == nullptr && root->pRight == nullptr) {
        return 1;
    }
    return SoNode(root->pLeft) + SoNode(root->pRight);
}
// Cau 9
int chieuCaoCay(Tree root) {
    if (root == nullptr) {
        return -1; 
    }
    int leftHeight = chieuCaoCay(root->pLeft);
    int rightHeight = chieuCaoCay(root->pRight);
    return 1 + max(leftHeight, rightHeight);
}


int main() {
    Tree root = nullptr;
    int choice;
    do {
        cout << "1. Nhap cay\n";
        cout << "2. Cau 1\n";
        cout << "3. Cau 2\n";
        cout << "4. Cau 3\n";
        cout << "5. Cau 4\n";
        cout << "6. Cau 5\n";
        cout << "7. Cau 6\n";
        cout << "8. Cau 7\n";
        cout << "9. Cau 8\n";
        cout << "10. Cau 9\n";
        cout << "11. Cau 10\n";
        cout << "12. Cau 11\n";
        cout << "13. Cau 12\n";
        cout << "14. Cau 13\n";
        cout << "15. Cau 14\n";
        cout << "16. Cau 15\n";
        cout<<"0. Nhap 0 de huy cay\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                root = xuatTree();
                break;
            case 2:
                cout << "NLR: ";
                NLR(root);
                cout << endl;
                
                cout << "LNR: ";
                LNR(root);
                cout << endl;
                
                cout << "LRN: ";
                LRN(root);
                cout << endl;

                cout << "RNL: ";
                RNL(root);
                cout << endl;

                cout << "RLN: ";
                RLN(root);
                cout << endl;

                cout << "NRL: ";
                NRL(root);
                cout << endl;
                break;
            case 3:
            {
                int x;
                cout<<"\nNhap gia tri can tim: ";
                cin>>x;
                TNode *tim = searchNode(root, x);
                if(tim!=nullptr) {
                    cout<<"\nTim thay gia tri "<<x<<"trong cay";
                }else {
                    cout<<"\nKo tim thay gia tri";
                }
            }
                
                break;
            case 4:
                {
                int x;
                cout<<"\nNhap gia tri can xoa: ";
                cin>>x;
                delNode(root, x);
                
                    cout<<"\nDa xoa gia tri "<<x<<"trong cay";
                
                }
                break;
            case 5:
                cout<<"\nTong so Node la: "<<TongNode(root)<<"\n";
                break;
            case 6:
                cout<<"\nTong so Node 2 cay la: "<<Node2Cay(root)<<"\n";
                break;
            case 7:
                cout<<"\nTong so Node 1 cay la: "<<Node1Cay(root)<<"\n";
                break;
            case 8:
                cout<<"\nTong so Node  cay con phai la: "<<Node1Cay(root)<<"\n";
                break;
            case 9:
                cout<<"\nSo Node  cay  la: "<<SoNode(root)<<"\n";
                break;
            case 10:
                cout<<"\nChieu Cao  cay  la: "<<chieuCaoCay(root)<<"\n";
                break;
            case 0:
                destroyTree(root);
                break;
            default:
                cout << "Tùy chọn không hợp lệ. Vui lòng chọn lại.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}

