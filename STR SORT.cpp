#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;

    // Input number of strings
    cout << "Enter the number of strings: ";
    cin >> n;

    // Clear the input buffer
    cin.ignore();

    string strArray[n];

    // Input the strings
    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; i++) {
        getline(cin, strArray[i]);
    }

    // Sorting the strings using a simple bubble sort
    for (int i = n-1; i >0; i--) {
        for (int j = 0; j <= i-1; j++) {
            if (strArray[j] > strArray[j+1]) {
                // Swap if the current string is greater than the next string
                string temp = strArray[j];
                strArray[j] = strArray[j+1];
                strArray[j+1] = temp;
            }
        }
    }

    // Output the sorted strings
    cout << "Strings in alphabetical order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << strArray[i] << endl;
    }

    return 0;
}

