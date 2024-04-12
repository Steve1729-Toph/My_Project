#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
typedef struct Node* node;

bool empty(node back){
    return back == nullptr;
}
int getSize(node back){
    int cnt = 0;
    while(back != nullptr){
        ++cnt;
        back = back->next;
    }
    return cnt;
}
node makeNode(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next = nullptr;
    return tmp;
}

void push(node& back, int x){
    node tmp =  makeNode(x);
    tmp->next = back;
    back = tmp;
}

void pop(node& back){
    node truoc = nullptr;
    node sau = back;
    while(sau->next != nullptr){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == nullptr){
        back = nullptr;
    }else{
        truoc->next = nullptr;
    }
}

int front(node back){
    while(back->next != nullptr){
        back = back->next;
    }
    return back->data;
}
 int main(){
    node back = nullptr;
    push(back, 6);
    push(back, 8);
    vector<int> lp;
    while(1){
        int top = front(back);pop(back);
        string s = to_string(top);
        if(s.size() == 9) break;
        lp.push_back(top);
        push(back, top * 10 + 6);
        push(back, top * 10 + 8);
    }
    for(int x:lp){
        cout<< x << " \n";
    }
    return 0;
 }