#include<iostream>
#include<string>

using namespace std;

class Clock {
    protected:
        int hour;
        int minute;
        int second;
        string meridian;
    public:
        Clock (int h, int m, int s, string me) {
            hour = h;
            minute = m;
            second = s;
            meridian = me;
        };
        void display (void) {
            cout << hour << ":" << minute << ":" << second << " " << meridian << endl;
        }
};

class StandardClock : Clock {
    public:
        StandardClock (int h, int m, int s, string me) : Clock(h, m, s, me) {
            hour = h;
            minute = m;
            second = s;
            meridian = me;
        };
        void display (void) {
            if (meridian[0] == 'A') {
                cout << "上午 " << hour << ":" << minute << ":" << second << endl;
            } else if (meridian[0] == 'P') {
                cout << "下午 " << hour << ":" << minute << ":" << second << endl;
            }
        }
};

class MilitaryClock : Clock {
    public:
        MilitaryClock (int h, int m, int s, string me) : Clock(h, m, s, me) {
            minute = m;
            second = s;
            if (me == "PM") {
                hour += 12;
            }
        };
        void display (void) {
            cout << hour << ":" << minute << ":" << second << endl;
        }
};

int main() {
    Clock cc(10, 25, 43, "AM");
    StandardClock sc(10, 25, 43, "AM");
    MilitaryClock mc(10, 25, 43, "PM");

    cc.display();
    sc.display();
    mc.display();

    return 0;
}
