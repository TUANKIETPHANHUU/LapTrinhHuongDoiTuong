#include<iostream>
using namespace std;
class Vector{
     private:
     int size;
     double *a;
     public:
     Vector(int size = 0){
        this->size = size;
        this->a = new double[size];
     }
     void nhap(){
        cout << "Nhap thanh phan vecto:" << endl;
        for(int i=0; i<size; i++){
            cout <<"vector["<< i <<"]:";
            cin>>a[i];
        }
     }
     void xuat(){
        cout << "Vector:";
        for(int i=0; i<size; i++){
            cout << a[i] << " ";
        }
        cout << endl;
     }
     double operator*(const Vector &v){
        double ans = 0;
        for(int i=0; i<size; i++){
            ans += a[i] * v.a[i];
        }
        return ans;
     }
     double module() {
            double ans = 0;
            for (int i = 0; i < size; i++) {
                ans += a[i] * a[i];
            }
            return sqrt(ans);
        }

     bool operator!=(const Vector &v){
        if(size != v.size){
            return true;
        }
        for(int i=0; i<size; i++){
            if(a[i] != v.a[i]){
                return true;
            }
        }
        return false;
     }
     Vector& operator++(){
        for(int i=0; i<size; i++){
            ++a[i];
        }
        return *this;
     }
     double length(){
        return size;
     }
     Vector operator+(const Vector& v){
        Vector ans(size);
        for(int i=0; i<size; i++){
            ans.a[i] = a[i] + v.a[i];
        }
        return ans;
     }
     Vector operator-(const Vector& v){
        Vector ans(size);
        for(int i=0; i<size; i++){
            ans.a[i] = a[i] - v.a[i];
        }
        return ans;
     }
     Vector operator*(double res){
        Vector ans(size);
        for(int i=0; i<size; i++){
            ans.a[i] = a[i] * res;
        }
        return ans;
     }
     bool operator==(const Vector& v){
        if(size != v.size){
            return false;
        }
        for(int i=0; i<size; i++){
            if(a[i] != v.a[i]){
                return false;
            }
        }
        return true;
     }
};

signed main(){
    Vector v1(3),v2(3);
    v1.nhap();
    v2.nhap();
    v1.xuat();
    v2.xuat();
    cout << "Tinh vo huong cua hai vecto:" << v1 * v2 << endl;
    cout << "Module cua Vector 1:" << v1.module() << endl;
    cout << "Module cua Vector 2:" <<v2.module() << endl;
    if(v1 != v2){
       cout <<"Hai Vector khong giong nhau." << endl;
    } else{
       cout <<"Hai Vector giong nhau." << endl;
    }

    Vector v4 = v1 - v2;
    cout <<"Vector hieu cua hai vector: ";
    v4.xuat();

    Vector v5 = v1 * 2;
    cout <<"Vector 1 nhan voi 2: ";
    v5.xuat();

    if(v1 == v2){
       cout <<"Hai Vector giong nhau." << endl;
    } else{
       cout <<"Hai Vector khong giong nhau." << endl;
    }

}
