#include <iostream>
#include <ctime>
using namespace std;

struct arr{
    char *p;
    int n;
    char *save0;
    arr(int n){
        this->n = n;
        p = new char[n];
        save0 = p;
    }
    ~arr(){
        delete[] save0;
        save0 = nullptr;
        p = nullptr;
    }
    void Get(){
        int i = 0;
        char* g = save0;
        while(i < n){
            cout << *(g+i);
            i++;
        }
        cout << endl;
    }
    void Left(){
        if(p > save0){
            p = p - 1;
        }
    }
    void Right(){
        if(p < save0 + n - 1){
            p = p + 1;
        }
    }
    void Delete(){
        if(n > 0){
            char* run = save0;
            int k = p - save0;
            for(int i = k; i < n - 1; i++){
                *p = *(p + 1);
                p++;
            }
            n--;
            char* p2 = new char[n];
            char* save2 = p2;
            for(int i = 0; i < n; i++){
                *p2++ = *run++;
            }   
            delete[] save0;
            save0 = save2;
            p = save0 + k - 1;
        }
    }
    void Insert(char value) {
        char* p2 = new char[n + 1];
        char* save2 = p2;
        char* run = save0;
        int i = p - save0;
        for(int j = 0; j < i; j++){
            *p2++ = *run++;
        }
        *p2++ = value;
        for(int j = i; j < n; j++){
            *p2++ = *run++;
        }
        delete[] save0;
        save0 = save2;
        p = save2 + i + 1;
        n++;
    }
};

int main(){
    clock_t begin = clock();
    arr a(0);
    //Nhap ham duoi day: a.Insert('x'); a.Delete(); a.Right(); a.Left(), a.Get();
    for(int i = 0; i < 100000; i++){
        a.Insert('K');
    }
    a.Delete();
    a.Get();
    clock_t end = clock(); //ghi lại thời gian lúc sau
    cout<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}