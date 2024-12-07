#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    // Constructor to initialize hours and minutes
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    // Member function to input time
    void input() {
        cout << "Enter hours: ";
        cin >> hours;
        cout << "Enter minutes: ";
        cin >> minutes;
    }

    // Friend function to overload equality (==) operator
    friend bool operator==(const Time& t1, const Time& t2);

    // Friend function to overload not equal (!=) operator
    friend bool operator!=(const Time& t1, const Time& t2);

    // Function to display time
    void display() const {
        cout << hours << " hours and " << minutes << " minutes";
    }
};

// Overload equality operator
bool operator==(const Time& t1, const Time& t2) {
    return (t1.hours == t2.hours && t1.minutes == t2.minutes);
}

// Overload not equal operator
bool operator!=(const Time& t1, const Time& t2) {
    return !(t1 == t2); // Use the overloaded == operator
}

int main() {
    Time time1, time2;

    cout << "Enter the first time:\n";
    time1.input();

    cout << "\nEnter the second time:\n";
    time2.input();

    cout << "\nComparing times:\n";
    cout << "Time 1: ";
    time1.display();
    cout << "\nTime 2: ";
    time2.display();

    cout << "\n\nAre the times equal? ";
    if (time1 == time2)
        cout << "Yes\n";
    else
        cout << "No\n";

    cout << "Are the times not equal? ";
    if (time1 != time2)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
