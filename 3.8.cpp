#include<iostream>
using namespace std;

class MyTime{
    private:
        int hour;
        int minute;
        int second;
    public:
        MyTime(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s){
            normalizeTime();
        }
        void enterTime(){
            cout << "Enter hour: ";
            cin >> hour;
            cout << "Enter minute: ";
            cin >> minute;
            cout << "Enter second: ";
            cin >> second;
        normalizeTime();
        }
        void displayTime() const {
        std::cout << "Time: " << hour << ":" << minute << ":" << second << std::endl;
    }
        void normalizeTime(){
            while(second >= 60){
                second -= 60;
                minute++;
            }
            while(minute >= 60){
                minute -= 60;
                hour++;
            }
            hour %= 24;
        }
        bool operator<(const MyTime& other) const{
            if(hour < other.hour)
                return true;
            else if(hour == other.hour){
                if(minute < other.minute)
                    return true;
                else if(minute == other.minute)
                    return second < other.second;
            }
            return false;
        }
        MyTime& operator+=(int seconds){
            second += seconds;
            normalizeTime();
            return *this;
        }
        int operator-(const MyTime& other) const{
            int thisTimeInSeconds = hour * 3600 + minute * 60 + second;
            int otherTimeInSeconds = other.hour * 3600 + other.minute * 60 + other.second;
            return thisTimeInSeconds - otherTimeInSeconds;
        }
};

int main(){
    MyTime Time01;
    MyTime Time02;
    //Input
    cout<<"Enter data for Time01: \n";
    Time01.enterTime();
    cout<<"Enter data for Time02: \n";
    Time02.enterTime();
    //Display times
    cout<<"Time 01: ";
    Time01.displayTime();
    cout<<"Time 02: ";
    Time02.displayTime();
    //Compare times
    if(Time01 < Time02){
        cout<<"Time01 is earlier than Time02"<<endl;
        cout<<"Time01 is not earlier than Time02"<<endl;
    }
    //Ddding seconds to Time01
    int secondsToAdd;
    cout << "Enter seconds to add to Time01: ";
    cin >> secondsToAdd;
    Time01 += secondsToAdd;
    // Display updated Time01
    std::cout << "Updated Time01: ";
    Time01.displayTime();
    // Calculate time difference
    int timeDifference = Time01 - Time02;
    std::cout << "Time difference: " << timeDifference << " seconds" << std::endl;

    return 0;
}
