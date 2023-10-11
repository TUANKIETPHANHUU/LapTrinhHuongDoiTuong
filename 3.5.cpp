#include<iostream>
#include<cmath>
using namespace std;

class Complex{
    double real,img; // phan thuc phan ao 
    public:
         Complex(){
            real = 0;
            img = 0;
         }
         Complex(double r, double i){
            real = r;
            img = i;
         }
         void Real(double r){
            real = r;
         }
         void Imag(double i){
              img = i;
         }
         double getReal(){
            return real;
         }
         double getImag(){
            return img;
         }
         void nhap(){
            cout << "Enter Real part:";
            cin>>real;
            cout << "Enter Imag part:";
            cin>>img;
         }
         void display(){
            if(img < 0)
             cout << real << img << "i" << endl;
            else
             cout << real << '+' << img << "i" << endl;
         }
         Complex operator*(Complex c){
            Complex tmp;
            tmp.real = real*c.real - img*c.img;
            tmp.img = real*c.img + img*c.real; // corrected the formula
            return tmp;
         }
         Complex operator/(Complex c){
            Complex tmp;
            tmp.real = (real*c.real + img*c.img)/(c.real*c.real + c.img*c.img);
            tmp.img = (img*c.real - real*c.img)/(c.real*c.real + c.img*c.img);
            return tmp;
        }

        double mod(){
            return sqrt(real * real + img * img);
        }

    friend Complex operator+(Complex c, int n); 
    friend Complex operator+(int n, Complex c);
};

Complex operator+(Complex c, int n){ 
    Complex temp;
    temp.real = c.getReal() + n; 
    temp.img = c.getImag(); 
    return temp;
}

Complex operator+(int n, Complex c){ 
    Complex temp;
    temp.real = c.getReal() + n; 
    temp.img = c.getImag(); 
    return temp;
}

int main(){
    Complex c1;
    cout<<"Enter the first Complex number:"<<endl;
    c1.nhap();

    Complex c2;
    cout<<"Enter the second Complex number:"<<endl;
    c2.nhap();

    cout<<"The two Complex numbers entered are:"<<endl;
    c1.display();
    c2.display();

    cout<<"The product of the two Complex numbers is:"<<endl;
    Complex c3 = c1*c2;
    c3.display();

    cout<<"The quotient of the two Complex numbers is:"<<endl;
    Complex c4 = c1/c2;
    c4.display();

    cout<<"The modulus of the first Complex number is:"<<c1.mod()<<endl;

    Complex c5 = c1 + 2;
    cout<<"The sum of first Complex number and integer 2 is:";
    c5.display();

    c5 = 2 + c1;
    cout<<"The sum of integer 2 and first Complex number is:";
    c5.display();

    return 0;
}
