#include <iostream>
#define baojiapisu
using namespace std;
class Vecto {
private:
    int n;
    int *data;
public:
// Ham tao
    Vecto() : n(0), data(NULL) {}
    Vecto(int _n) : n(_n) {
        data = new int[n];
    }
    Vecto(const Vecto& v) : n(v.n) {
        data = new int[n];
        for (int i = 0; i < n; i++) {
            data[i] = v.data[i];
        }
    }
    // Ham Huy
    ~Vecto() {
        delete[] data;
    }
 // toan tu tai boi >>
    friend istream& operator>>(istream& is, Vecto& v) {
        cout << "Nhap so chieu cua vecto: ";
        is >> v.n;
        v.data = new int[v.n];
        for (int i = 0; i < v.n; i++) {
            cout << "Nhap toa do thu:" << i+1 << ": ";
            is >> v.data[i];
        }
        return is;
    }
// toan tu tai boi <<
    friend ostream& operator<<(ostream& os, const Vecto& v) {
        os << "(";
        for (int i = 0; i < v.n-1; i++) {
            os << v.data[i] << ", ";
        }
        os << v.data[v.n-1] << ")";
        return os;
    }
// toan tu ==
    bool operator==(const Vecto& v) const {
        if (n != v.n) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (data[i] != v.data[i]) {
                return false;
            }
        }
        return true;
    }
// toan tu cong 2 vecto
    Vecto operator+(const Vecto& v) const {
        if (n != v.n) {
            cout << "Hai vecto khong cung so chieu" << endl;
            return *this;
        }
        Vecto res(n);
        for (int i = 0; i < n; i++) {
            res.data[i] = data[i] + v.data[i];
        }
        return res;
    }
// toan tu nhan 2 vecto
    Vecto operator*(const int& k) const {
        Vecto res(n);
        for (int i = 0; i < n; i++) {
            res.data[i] = data[i]*k;
        }
        return res;
    }
};
 main() {
    Vecto v1, v2, v3;
    cin>>v1;
    cout << "Nhap v1:" << endl;
    cin>>v2;
    cout << "Nhap v2:" << endl;
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    if (v1 == v2) {
        cout << "v1 va v2 bang nhau" << endl;
    } else {
        cout << "v1 va v2 khac nhau" << endl;
    }
    v3 = v1 + v2;
    cout << "v1 + v2 = " << v3 << endl;

    v3 = v1*3;
    cout << "v1*3 = " << v3 << endl;

    return 0;
}
