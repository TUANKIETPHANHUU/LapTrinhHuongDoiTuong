#include<iostream>
using namespace std;
class Date{
    private:
        int day, month, year;
    public:
        void nhap(){
            cout<<"Nhap ngay: ";
            cin>>day;
            cout<<"Nhap thang: ";
            cin>>month;
            cout<<"Nhap nam: ";
            cin>>year;
            cout<<"\n";
        }
        // Kiem tra nam cua doi tuong Date co phai nam nhuan hay khong
        bool check(){
            if(year%400==0 || (year%4==0 && year%100!=0))
                return true;
            else
                return false;
        }
         // Tra ve so ngay trong thang cua doi tuong Date
        int songay(){
            if(month==2){
                if(check())
                    return 29;
                else
                    return 28;
            }
            else if(month==4 || month==6 || month==9 || month==11)
                return 30;
            else    
                return 31;
        }
        // Nap chong toan tu++ de tang doi tuong DATE len nagy va toan tu < de so sanh hai doi tuong Date
        void operator++(){
            day++;
            if(day > songay()){
                day = 1;
                month++;
                if(month > 12){
                    month = 1;
                    year++;
                }
            }
        }
        bool operator<(Date d){
            if(year<d.year)
                return true;
            else if(year>d.year)
                return false;
            else{
                if(month<d.month)
                    return true;
                else if(month>d.month)
                    return false;
                else{
                    if(day<d.day)
                        return true;
                    else
                        return false;   
                }
            }
        }
        void display(){
            cout<<day<<"/"<<month<<"/"<<year<<"\n";
        }
};

signed main(){
    Date d1, d2;
    d1.nhap();
    d2.nhap();
    if(d1.check())
        cout<<"Nam d1 la nam nhuan\n";
    else
        cout<<"Nam d1 khong phai la nam nhuan\n";
    cout<<"So ngay trong tháng d1: "<<d1.songay()<<"\n";
    if(d1<d2)
        cout<<"d1 som hon d2\n";
    else
        cout<<"d1 muon hon hoac bang d2\n";

    ++d1;
    cout<<"Sau khi tang d1 them mot ngay, no so tro thanh: ";
    d1.display();

    return 0;
}