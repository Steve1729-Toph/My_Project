#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
typedef struct Node* node;
bool empty (node top){
    return top == nullptr;
}
int getsize(node top){
    int ans = 0;
    while(top != nullptr){
        top = top->next;
        ans++;
    }
    return ans;
}
node makeNode(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next = nullptr;
    return tmp;
}
void push(node& top, int x){
    node tmp = makeNode(x);
    if(top == nullptr){
        top = tmp;
    }else{
        tmp->next = top;
        top = tmp;
    }
}

void pop(node& top){
    if(top == nullptr) return;
    top = top->next;
}
int getTop(node top){
    return top->data;
}
 int main(){
    node top = nullptr;
    long long n;cin >> n;
    while(n){
        int r = n % 2;
        push(top,r);
        n /= 2;
    }
    while(!empty(top)){
        cout<<getTop(top);
        pop(top);
    }
    return 0;
 }