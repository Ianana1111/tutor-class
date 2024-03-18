#include <iostream>
#include <string>
using namespace std;

struct Container {
    int index; // 貨櫃編號
    int weight; // 貨櫃重量
    Container *next; 
};
Container* insert(Container* head, int index, int weight){
    Container *tmp = new Container;
    tmp -> index = index;
    tmp -> weight = weight;
    tmp -> next = nullptr;
    if(head == nullptr){
        head = tmp;
        return head;
    }
    Container *rec = head;
    while(rec != nullptr){
        if(index > rec -> index){
            if(rec -> next == nullptr){
                tmp -> next = rec -> next;
                rec -> next = tmp;
                return head;
            }
            if(index < rec -> next -> index){
                tmp -> next = rec -> next;
                rec -> next = tmp;
                return head;
            }
        }else {
            tmp -> next = head;
            head = tmp;
            return head;
        }
        rec = rec -> next;
    }
    return head;
}

Container* remove(Container* head, int max_weight){
    Container *tmp = head;
    if(head == nullptr)
        return head;
    if(head -> weight == max_weight){
        head = head -> next;
        delete(tmp);
    }
    while(tmp -> next != nullptr){
        if(tmp -> next -> weight == max_weight){
            Container *rec = tmp -> next;
            tmp -> next = rec -> next;
            delete(rec);
            return head;
        }
        tmp = tmp -> next;
    }
}

void print_list(Container *head){
    Container *cur = head;
    while (cur!=nullptr) {
        cout << cur->index << " " << cur->weight << endl;
        cur = cur->next; 
    }
}

void clear_list(Container *head){
    Container *tmp;
    while(head != nullptr){
        tmp = head;
        head = head -> next;
        delete(tmp);
    }
}

int main() {
    Container *head = nullptr;
    int N;
    cin>>N;
    while (N--) {
        string cmd;
        cin >> cmd;
        if (cmd == "insert") {
            int index, weight;
            cin >> index >> weight;
            head = insert(head, index, weight);
        } else if (cmd == "remove") {
            int max_weight;
            cin >> max_weight;
            head = remove(head, max_weight);
        }
    }
    print_list(head);
    clear_list(head);
    return 0; 
}