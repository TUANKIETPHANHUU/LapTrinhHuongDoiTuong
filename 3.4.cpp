#include <iostream>
using namespace std;

class Array {
    int* arr;
    int n;
public:
    Array() {
        arr = nullptr;
        n = 0;
    }
    ~Array() {
        delete[] arr;
    }
    void nhap() {
        cout << "Nhap so luong phan tu cua mang: ";
        cin >> n;
        arr = new int[n];
        cout << "Nhap " << n << " phan tu: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    Array operator+(const Array& a) {
        Array ans;
        ans.n = n > a.n ? n : a.n;
        ans.arr = new int[ans.n];
        for (int i = 0; i < ans.n; i++) {
            int value1 = i < n ? arr[i] : 0;
            int value2 = i < a.n ? a.arr[i] : 0;
            ans.arr[i] = value1 + value2;
        }
        return ans;
    }

    Array operator++() {
        Array ans;
        ans.n = n + 1;
        ans.arr = new int[ans.n];
        for (int i = 0; i < n; i++) {
            ans.arr[i] = arr[i];
        }
        ans.arr[n] = 0; 
        return ans;
    }

    bool operator==(const Array& a) {
        if (n != a.n) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] != a.arr[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Array a1, a2;
    a1.nhap();
    a2.nhap();
    cout << "a1: ";
    a1.display();
    cout << "a2: ";
    a2.display();
    Array a3 = a1 + a2;
    cout << "a1 + a2: ";
    a3.display();
    Array a4 = ++a1;
    cout << "++a1: ";
    a4.display();
    if (a1 == a2) {
        cout << "a1 == a2" << endl;
    }
    else {
        cout << "a1 != a2" << endl;
    }

    return 0;
}
