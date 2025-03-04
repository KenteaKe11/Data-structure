#include <iostream>
#include <ctime>
using namespace std;

struct node{
  char data;
  node* previ;
  node* next;
  node(char value){
    data = value;
    previ = nullptr;
    next = nullptr;
  }
};

struct linkedlist{
  node* p = nullptr;
  node* save = nullptr;
  void Insert(char x){
    node* temp = new node(x);
    if(p == nullptr){
      p = temp;
      save = p;
    }else if(p->next == nullptr){
      p->next = temp;
      temp->previ = p;
      p = temp;
    }else{
      temp->next = p->next;
      p->next->previ = temp;
      p->next = temp;
      temp->previ = p;
      p = temp;
    }
  }
  void Get(){
    node* r = save;
    while(r){
      cout << r->data;
      r = r->next;
    }
  }
  void Left(){
    if(p->previ != nullptr){
      p = p->previ;
    }
  }
  void Right(){
    if(p->next != nullptr){
      p = p->next;
    }
  }
  void Delete(){
    if(p != nullptr){
      node* temp = p;
      if(p->next == nullptr){
        p = p->previ;
        p->next = nullptr;
      }else if(p->previ == nullptr){
        p = nullptr;
      }else{
        p = p->previ;
        p->next = p->next->next;
        p->next->previ = p;
      }
      delete temp;
    }
  }
};

int main(){
  clock_t begin = clock();
  linkedlist l;
  //Nhap ham duoi day: l.Insert('x'); l.Delete(); l.Right(); l.Left(), l.Get();
  for(int i = 0; i < 100000; i++){
    l.Insert('K');
  }
  l.Delete();
  l.Get();
  clock_t end = clock(); //ghi lại thời gian lúc sau
  cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
  return 0;
}