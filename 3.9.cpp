//baoijaopisu
#include<iostream>
using namespace std;
class MyArray{
private:
    int *a; // con tro tro den mang chua du lieu
    int n; // so phan tu cua mang
public:
	//ham tao
    MyArray(){
    n = 0; a = NULL;
}
    MyArray(int size){
        n = size;a = new int[n];
    }
    MyArray(const MyArray &arr){
        n = arr.n;a = new int[n];
        for (int i = 0; i < n; i++){
            a[i] = arr.a[i];
        }
    }
    // Ham huy
    ~MyArray(){ 
        if (a != NULL)
            delete[] a;
    }
    // ham nhap
    void nhap(){
        cout << "Nhap " << n << " phan tu: ";
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
    }
    // ham xuat du lieu
    void xuat(){
        cout << "Nhap vao so phan tu thu: ";
        for (int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    // toan tu gan =
    MyArray &operator=(const MyArray &arr){
        if (a == arr.a)
            return *this;
        if (a != NULL)
            delete[] a;
        n = arr.n;
        a = new int[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = arr.a[i];
        }
        return *this;
    }
    // toan tu !=
    bool operator!=(const MyArray &arr){
        if (n != arr.n)
            return true;
        for (int i = 0; i < n; i++){  if (a[i] != arr.a[i])
                return true;
        }
        return false;
    }
    // toan tu []
    int &operator[](int i){
        return a[i];
    }
};
signed main(){
    MyArray arr1(5);
    arr1.nhap();
    arr1.xuat();
    
    MyArray arr2 = arr1;
    arr2.xuat();
    
    MyArray arr3(5);
    arr3.nhap();
    arr3.xuat();
    if (arr1 != arr3)
    {
        cout << "mang 1 và mang 3 khac nhau.\n";
    }
    arr1[2] = 100;
    arr1.xuat();
    return 0;
}
/*
baoijaopisu
*/
