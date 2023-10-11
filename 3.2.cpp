#include<iostream>
using namespace std;
class PhanSo{
    int tuso,mauso;
    public:
      PhanSo(){
        tuso = 0;
        mauso = 1;
      }
      PhanSo(int num, int mau){
        tuso = num;
        mauso = mau;
      }
      void display(){
     cout << tuso << "/" << mauso << endl;
      }
      void nhap(){
        cout << "Nhap tuso:";
        cin >> tuso;
        cout << "Nhap mauso:";
        cin>>mauso;
      }
      PhanSo operator+(PhanSo f){
        PhanSo sum;
        sum.tuso = tuso*f.mauso+f.tuso*mauso;
        sum.mauso = mauso * f . mauso;
        return sum;
      }
      bool operator==(PhanSo f){
        return(tuso*f.mauso == mauso*f.tuso);
      }
      PhanSo operator*(PhanSo f){
        PhanSo product;
        product.tuso = tuso * f.tuso;
          product.mauso = mauso * f.mauso;
          return product;
      }
      PhanSo operator++(){
        tuso = tuso + mauso;
        return *this;
      }
};
int main(){
PhanSo f1,f2,sum,prod;
cout << "Nhap phan so 1:\n";
f1.nhap();
cout << "Nhap phan so 2:\n";
f2.nhap();
sum = f1 + f2;
prod = f1 * f2;
cout << "Nhap Phan So 1:";
f1.display();
cout << "Nhap Phan So 2:";
f2.display();
cout << "Tong cac phan so:";
sum.display();
cout << "San pham phan so:";
prod.display();
if(f1 == f2){
    cout << "Hai phan so bang nhau.\n";
}
else{
    cout <<"Hai phan so khong bang nhau.\n";
}
++f1;
cout << "Phan So 1 sau khi tang:";
f1.display();
}