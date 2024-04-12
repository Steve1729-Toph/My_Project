#include <iostream>
#include <string>
#include <iomanip>  

using namespace std;

struct Student{
    string name,id;
    double gpa;
};
struct SV{
    Student s;
    SV* next;
};
typedef struct SV* sv;

//make node
sv Makenode(){
    Student s;
    cout<< "Nhap thong tin sinh vien \n";
    cout<< "Nhap ID: ";cin>>s.id;
    cout<< "Nhap ten: ";cin.ignore();
    getline(cin, s.name);
    cout<< "Nhap gpa: "; cin>>s.gpa;
    sv tmp = new SV();
    tmp->s = s;
    tmp->next = nullptr;
    return tmp;
}

//kiem tra rong
bool Empty(sv a){
    return a == NULL;
}

//do dai list
int size(sv a){
    int cnt = 0;
    while (a != nullptr){
        cnt++;
        a = a->next;
    }
    return cnt;
}

//them 1 phan tu vao dau list
void InsertFirst(sv &a){
    sv tmp = Makenode();
    if(a == nullptr){
        a = tmp;
    }else{
        tmp->next = a;
        a = tmp;
    }
}

//them 1 phan tu vao cuoi list
void InsertLast(sv &a){
    sv tmp = Makenode();
    if(a == nullptr){
        a = tmp;
    }else{
        sv p = a;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = tmp;
    }
}

//them 1 phan tu vao giua tai vi tri pos
void InsertPos(sv &a, int pos){
    int n = size(a);
    if(pos <= 0 || pos > n + 1){
        cout<<"vi tri khong thoa man"<<endl;
        return;
    }else{
        if(pos == 1){
            InsertFirst(a);
            return;
        }
        if(pos == n + 1){
            InsertLast(a);
            return;
        }
        sv p = a;
        for(int i = 1; i < pos-1; ++i){
            p = p->next;
        }
        sv tmp = Makenode();
        tmp->next = p->next;
        p->next = tmp;
    }
}

//xoa phan tu o dau list
void DeleteFirst(sv &a){
    if(a == nullptr) return;
    a = a->next;
}

//xoa phan tu o cuoi list
void DeleteLast(sv &a){
    if(a == nullptr) return;
    int n = size(a);
    if(n == 1) a = nullptr;
    sv p = a;
    for(int i = 1; i < n-1; ++i){
        p = p->next;
    }
    p->next = nullptr;
}

//xoa o giua tai vi tri pos
void DeletePos(sv &a, int pos){
    if(pos <= 0 || pos > size(a)){
        cout<<"vi tri khong thoa man\n";
        return;
    } 
    sv truoc = NULL, sau = a;
    for (int i = 1; i < pos; ++i){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL) a = a->next;
    else truoc->next = sau->next;
}

//nhap sinh vien
void Out(Student s){
    cout<<"\n----------------------------------------\n";
    cout << "ID: " << s.id << '\n';
    cout << "Ho ten: " << s.name << '\n';
    cout << "GPA: " << fixed << setprecision(2) << s.gpa << '\n';
    cout<<"\n----------------------------------------\n";
}
//in ra man hinh
void Outds(sv a){
    cout<<"Danh sach sinh vien \n";
    while(a != NULL){
        Out(a->s);
        a = a->next;
    }
}

//sap xep tang dan list
void Sort(sv &a){
    for(sv p = a; p != nullptr; p = p->next){
        sv min = p;
        for(sv q = p->next; q != nullptr; q = q->next){
            if(q->s.gpa < min->s.gpa){
                min = q;
            }
        }
        Student tmp = min->s;
        min->s = p->s;
        p->s = tmp;
    }
}
int main(){
    sv head = nullptr;
    int pos;
    while(1){
        cout<<"\n-------------------MENU-----------------\n";
        cout<<"1.Chen 1 sinh vien vao dau\n";
        cout<<"2.Chen 1 sinh vien vao cuoi\n";
        cout<<"3.Chen 1 sinh vien vao vi tri pos\n";
        cout<<"4.Xoa 1 sinh vien o dau\n";
        cout<<"5.Xoa 1 sinh vien o cuoi\n";
        cout<<"6.Xoa 1 sinh vien o vi tri pos\n";
        cout<<"7.Duyet list\n";
        cout<<"8.Sap xep danh sach tang dan\n";
        cout<<"9.Kiem tra danh sach co rong khong\n";
        cout<<"10.Thoat ra di";
        cout<<"\n----------------------------------------\n";
        cout<<"nhap lua chon: ";
        int lc;cin>>lc;
        switch (lc)
        {
        case 1:
            InsertFirst(head);
            break;
        case 2:
            InsertLast(head);
            break; 
        
        case 3:
            cout<<"nhap vi tri can chen: ";
            cin>>pos;
            InsertPos(head,pos);
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
            Outds(head);
            break;
        case 8:
            Sort(head);
            break;
        case 9:
            (Empty(head)) ? cout<<"danh sach trong rong":cout<<"danh sach co "<<size(head)<<" sinh vien";
            break;
        case 10:
            cout<<"nhan phim bat ky de thoat khoi day nhe";
            return 0;
        }
    }
    cout<<endl;
    return 0;
}