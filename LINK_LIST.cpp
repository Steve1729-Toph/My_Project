#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};
typedef struct Node* node;

//make node
node Makenode(int a){
    node tmp = new Node();
    tmp->data = a;
    tmp->next = NULL;
    return tmp;
}

//kiem tra rong
bool Empty(node a){
    return a == NULL;
}

//do dai list
int size(node a){
    int cnt = 0;
    while (a != nullptr){
        cnt++;
        a = a->next;
    }
    return cnt;
}

//them 1 phan tu vao dau list
void InsertFirst(node &a, int x){
    node tmp = Makenode(x);
    if(a == nullptr){
        a = tmp;
    }else{
        tmp->next = a;
        a = tmp;
    }
}

//them 1 phan tu vao cuoi list
void InsertLast(node &a, int x){
    node tmp = Makenode(x);
    if(a == nullptr){
        a = tmp;
    }else{
        node p = a;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = tmp;
    }
}

//them 1 phan tu vao giua tai vi tri pos
void InsertPos(node &a,int x, int pos){
    int n = size(a);
    if(pos <= 0 || pos > n + 1){
        cout<<"vi tri khong thoa man"<<endl;
        return;
    }else{
        if(pos == 1){
            InsertFirst(a,x);
            return;
        }
        if(pos == n + 1){
            InsertLast(a,x);
            return;
        }
        node p = a;
        for(int i = 1; i < pos-1; ++i){
            p = p->next;
        }
        node tmp = Makenode(x);
        tmp->next = p->next;
        p->next = tmp;
    }
}

//xoa phan tu o dau list
void DeleteFirst(node &a){
    if(a == nullptr) return;
    a = a->next;
}

//xoa phan tu o cuoi list
void DeleteLast(node &a){
    if(a == nullptr) return;
    int n = size(a);
    if(n == 1) a = nullptr;
    node p = a;
    for(int i = 1; i < n-1; ++i){
        p = p->next;
    }
    p->next = nullptr;
}

//xoa o giua tai vi tri pos
void DeletePos(node &a, int pos){
    if(pos <= 0 || pos > size(a)){
        cout<<"vi tri khong thoa man\n";
        return;
    } 
    node truoc = NULL, sau = a;
    for (int i = 1; i < pos; ++i){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL) a = a->next;
    else truoc->next = sau->next;
}

//in ra man hinh
void Out(node a){
    cout<<"\n----------------------------------------\n";
    while(a != NULL){
        cout<<a->data<<" ";
        a = a->next;
    }
    cout<<"\n----------------------------------------\n";
}

//sap xep tang dan list
void Sort(node &a){
    for(node p = a; p != nullptr; p = p->next){
        node min = p;
        for(node q = p->next; q != nullptr; q = q->next){
            if(q->data < min->data){
                min = q;
            }
        }
        int tmp = min->data;
        min->data = p->data;
        p->data = tmp;
    }
}
int main(){
    node head = nullptr;
    int x,pos;
    while(1){
        cout<<"\n-------------------MENU-----------------\n";
        cout<<"1.Chen 1 phan tu vao dau\n";
        cout<<"2.Chen 1 phan tu vao cuoi\n";
        cout<<"3.Chen 1 phan tu vao vi tri pos\n";
        cout<<"4.Xoa 1 phan tu o dau\n";
        cout<<"5.Xoa 1 phan tu o cuoi\n";
        cout<<"6.Xoa 1 phan tu o vi tri pos\n";
        cout<<"7.Duyet list\n";
        cout<<"8.Sap xep danh sach tang dan\n";
        cout<<"9.Kiem tra co rong khong\n";
        cout<<"10.Thoat ra di";
        cout<<"\n----------------------------------------\n";
        cout<<"nhap lua chon: ";
        int lc;cin>>lc;
        switch (lc)
        {
        case 1:
            cout<<"nhap gia tri can chen: ";
            cin>>x;
            InsertFirst(head,x);
            break;
        case 2:
            cout<<"nhap gia tri can chen: ";
            cin>>x;
            InsertLast(head,x);
            break; 
        
        case 3:
            cout<<"nhap gia tri va vi tri can chen: ";
            cin>>x>>pos;
            InsertPos(head,x,pos);
            break; 
        case 4:
            DeleteFirst(head);
            break;
        case 5:
            DeleteLast(head);
            break;
        case 6:
            cout<<"nhap vi tri muon xoa: ";
            cin>>pos;
            DeletePos(head,pos);
            break;
        case 7:
            Out(head);
            break;
        case 8:
            Sort(head);
            break;
        case 9:
            (Empty(head)) ? cout<<"danh sach trong rong":cout<<"danh sach co "<<size(head)<<" phan tu";
            break;
        case 10:
            cout<<"nhan phim bat ky de thoat khoi day nhe";
            return 0;
        }
    }
    cout<<endl;
    return 0;
}