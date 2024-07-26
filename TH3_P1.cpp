# include<iostream>
# include<cmath>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {} 
};

struct LinkedList {
    Node* head;
    Node* tail;
    LinkedList() : head(nullptr), tail(nullptr) {}
};

Node* createNode(int value) {
    // struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    Node* newNode = new Node(value);
    if(newNode ==nullptr) {
        cout<<"Ko du bo nho";
        exit(1);
    }
    newNode ->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Cau 1
void add(LinkedList &list, int data) {
    struct Node* new_node = createNode(data);
    if(list.head==nullptr) {
        list.head = new_node;
         list.tail = new_node;
    }else {
            list.tail->next = new_node;
            list.tail = new_node;
        }
        
    }  

void display(LinkedList &list) {
    struct Node* current = list.head;
    while(current !=nullptr) {
        cout<<current ->data<<", ";
        current = current -> next;
    }
}


// Cau 2
bool soNT(int n) {
    int dem=0;
	for(int i=1; i<=n; i++)
		if(n%i == 0)
			dem++;
	if(dem==2)
		return true;
	return false;
}

void displayCau2(LinkedList &list) {
    struct Node* current = list.head;
    bool NT = false;
    while(current !=nullptr) {
        if(soNT(current ->data)==true) {
            cout<<current ->data<<", ";
            NT = true;
        }  
        current = current ->next;
    }
    if(!NT) {
        cout<<"0";
    }else {
        cout<<endl;
    }
}

// Cau 3
// void RemoveHeadAfter(LinkedList &list, int x) {
//     struct Node* currentHead = list.head;
//     struct Node* currentTail = nullptr;

//     while(currentHead !=nullptr) {
//         if(currentHead ->data==x) {
//             break;
//         }
//         currentTail = currentHead;
//         currentHead = currentHead ->next;
//     }
//     if(currentHead==nullptr) {
//         cout<<"Ko co ket qua xoa";
//         return;
//     }else {
//         // xoa dau truoc
//         if(currentHead==list.head) {
//             list.head = list.head ->next;
//             currentHead ->next = nullptr;
//             delete(currentHead);
//             currentHead = nullptr;
//         }else if(currentHead->next ==nullptr){ //  xoa dau cuoi
//             list.tail = currentTail;
//             currentTail = currentHead ->next;
//             delete(currentHead);
//             currentHead = nullptr;
//         }
//     }
    
// }

void RemoveHead(LinkedList &list) {
    if (list.head == nullptr) {
        cout << " ";
        return;
    }
    Node* temp = list.head;
    list.head = list.head ->next;
    if(list.head==nullptr) {
        list.tail = nullptr;
    }
    delete temp;
}
void RemoveAfter(LinkedList &list) {
    if (list.head == nullptr) {
        cout << " ";
        return;
    }
    if(list.head==list.tail) {
         delete list.head;
         list.head = nullptr;
         list.tail = nullptr;
         return;
    }
    Node* current = list.head;
    while (current->next != list.tail) {
        current = current->next;
    }
    delete list.tail;
    list.tail = current;
    list.tail->next = nullptr;
}

// Cau 4
struct ListConnect {
    Node* A;
    Node* B;
    Node* list;
    ListConnect() : A(nullptr), B(nullptr), list(nullptr) {}

            void InputList(Node*& head) { // tạo tham chiếu conn trỏ cho head 
                cout << "Nhap vao cac gia tri cho danh sach, nhap -1 de ket thuc: " << endl;
                int value;
                while (true) {
                    cin >> value;
                    if (value == -1) break;
                    Node* newNode = new Node(value);
                    if (head == nullptr) {
                        head = newNode;
                    } else {
                        Node* current = head;
                        while (current->next != nullptr) {
                            current = current->next;
                        }
                        current->next = newNode;
                    }
                }
            }

            void Conn_Cau4() {
                if (A == nullptr) {
                list = B;
            } else {
                list = A;
                Node* last = list;
                while (last->next != nullptr) {
                    last = last->next;
                }
                last->next = B;
            }
            }
            void displayCau4(Node *head) const {
            Node *ptr = head;

            cout << "Ta co";
            while (ptr != nullptr) {
                cout <<ptr->data << ", ";
                ptr = ptr->next;
            }
                cout << "\n";
            }

};


int main() {
    LinkedList linkedList;
    ListConnect linkedConn;

    cout<<"Nhap vao cac gia tri x, nhap -1 de ket thuc: "<<"\n";
    int x;
    while(true) {
        cin>>x;
        if(x==-1) {
            break;
        }
        add(linkedList, x);// them gia tri vao danh sach
    }
    cout<<"Ta co: ";
    display(linkedList);

    cout<<"\nTa co cac so NT la: ";
    displayCau2(linkedList);

    RemoveHead(linkedList);
    RemoveAfter(linkedList);
    cout<<"KQ LA: ";
    display(linkedList);

    cout << "\nDanh sach A: ";
    linkedConn.InputList(linkedConn.A);
    cout << "\nDanh sach B: ";
    linkedConn.InputList(linkedConn.B);
    linkedConn.Conn_Cau4();

    cout << "\nKQ la: ";
    linkedConn.displayCau4(linkedConn.list);




    //Gia phong bo nho 
    struct Node* current = linkedList.head;
    while(current !=nullptr ) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }

}