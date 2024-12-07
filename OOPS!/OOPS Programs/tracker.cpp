#include <iostream>
using namespace std;

class Tracker {
private:
    int personId;      // Person ID
    int step_count;    // Step count
    int stair_count;   // Stair count
    static int trackerCount; // Static member to track the number of Tracker objects

public:
Tracker(){}
    // Parameterized constructor with default arguments
    Tracker(int id, int steps = 0, int stairs = 0) : personId(id), step_count(steps), stair_count(stairs) {
        trackerCount++; // Increment the static tracker count
    }

    // Destructor to decrement the tracker count when an object is destroyed
    ~Tracker() {
        trackerCount--;
    }

    // Member function to increment step_count and stair_count
    void incrementCount(int n);

    // Function to display the person ID and updated step_count
    void displayCount() {
        cout << "Person ID: " << personId << ", Total Steps: " << step_count << endl;
    }

    // Static function to get the current tracker count
    static int getTrackerCount() {
        return trackerCount;
    }

    // Friend function to convert stair_count to step_count
    friend void convertStep(Tracker& t);
};

// Definition of the static member
int Tracker::trackerCount = 0;

// Definition of the incrementCount function
void Tracker::incrementCount(int n) {
    step_count += n;
    stair_count += n;
}

// Non-member function to convert stair_count to step_count
void convertStep(Tracker& t) {
    t.step_count += t.stair_count * 2; // 1 stair_count = 2 step_count
    t.stair_count = 0; // Reset stair_count to 0 after conversion
}

int main() {
    int n;
    cout << "Enter the number of users to track: ";
    cin >> n;

    // Create an array of Tracker objects
    Tracker* trackers = new Tracker[n];
    for (int i = 0; i < n; i++) {
        int id, steps, stairs;
        cout << "\nEnter details for User " << i + 1 << ":\n";
        cout << "Person ID: ";
        cin >> id;
        cout << "Initial steps (or 0): ";
        cin >> steps;
        cout << "Initial stairs (or 0): ";
        cin >> stairs;
        trackers[i] = Tracker(id, steps, stairs);
    }

    // Increment counts for all users
    for (int i = 0; i < n; i++) {
        int increment;
        cout << "\nEnter the number of steps to increment for User " << i + 1 << ": ";
        cin >> increment;
        trackers[i].incrementCount(increment);
    }

    // Convert stair_count to step_count for all users
    for (int i = 0; i < n; i++) {
        convertStep(trackers[i]);
    }

    // Display the details for all users
    cout << "\nUpdated details for all users:\n";
    for (int i = 0; i < n; i++) {
        trackers[i].displayCount();
    }

    // Display the total number of Tracker objects created
    cout << "\nTotal number of Tracker objects created: " << Tracker::getTrackerCount() << endl;

    // Clean up dynamically allocated memory
    delete[] trackers;

    // Display tracker count after cleanup
    cout << "Total number of Tracker objects after deletion: " << Tracker::getTrackerCount() << endl;

    return 0;
}
