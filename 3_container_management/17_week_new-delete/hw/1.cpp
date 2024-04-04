#include <iostream>
using namespace std;

struct family{
  int money;
  family *kid;
  family *dad;
};

family *head = NULL;
family *tail = NULL;

void Initing(int arr[]){
  for(int i=0; i<6; i++){
    family *new_family = (family *)malloc(sizeof(family));
    new_family -> money = arr[i];
    if(head == NULL){
      new_family -> dad = NULL;
      new_family -> kid = NULL;
      head = new_family;
      tail = new_family;
    }else {
      new_family -> kid = NULL;
      new_family -> dad = tail;
      tail -> kid = new_family;
      tail = new_family;
    }
  }
}

void exchange(){
  // 要在這裡交換
  // TODO
  family *reset = head;
  for(int i=0; i<5; i++){
    family *tmp = head;
    int maxx = -1;
    int *address = NULL;
    while(tmp != NULL){
      if(tmp -> money > maxx){
        address = &(tmp -> money);
        maxx = tmp -> money;   
      }
      tmp = tmp -> kid;
    }
    int change = head -> money;
    head -> money = *address;
    *address = change;
    head = head -> kid;
  }
  head = reset;
}

int main(){
  int money_in_da_bank[6] = {600, 10, 300, 50, 1000, 100};
  Initing(money_in_da_bank);
  exchange();

  // 請嘗試將所有祖先的錢都輸出，head存的就是曾曾曾祖先的資料
  // TODO
  while(head != NULL){
    printf("%d ", head -> money);
    head = head -> kid;
  }
  printf("\n");
} 

