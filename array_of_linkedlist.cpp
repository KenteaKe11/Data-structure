#include <iostream>
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

struct Aol{
  //array
  node** save0 = nullptr;
  //count
  int m = 0;
  int n = 0;
  //LL
  node* p = nullptr;
  node* save = nullptr;
  //Function
  ~Aol(){
    delete[] save0;
    save0 = nullptr;
  }
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
    ++m;
    arr();
  }
  void Get(){
    node** duyetmang = save0;
    for(int i = 0; i < n; i++){
      node* duyetnode = duyetmang[i];
      while(duyetnode && ((duyetnode != duyetmang[i + 1] && i + 1 < n) || i == n - 1)){
        cout << duyetnode->data;
        duyetnode = duyetnode->next;
      }
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
      --m;
      arr();
    }
  }
  void arr(){
    if(n != ((m - 1)/10 + 1)){
      n = (m - 1)/10 + 1;
      //Tao mang moi
      node** run = new node*[n];
      node* r = save;
      //khoi tao gia tri cho mang
      int cnt = 0;
      int i = 0;
      while(r && i < n){
        cnt++;
        if(cnt % 10 == 1){
          run[i] = r;
          
          i++;
        }
        r = r->next;
      }
      //thay mang cu thanh mang moi
      if(save0){
        delete[] save0;
      }
      save0 = run;
    }
  }
};

int main(){
  Aol al;
  //nhap lenh duoi day:
  al.Get();
  return 0;
}