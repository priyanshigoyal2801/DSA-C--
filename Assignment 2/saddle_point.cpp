#include <iostream>
using namespace std;

void findSaddlePoint(int arr[][100], int n, int m) {
    bool found = false;

    // Loop through each row
    for (int i = 0; i < n; i++) {
        // Step 1: Find the minimum element in the current row
        int minElement = arr[i][0];
        int colIndex = 0;

        for (int j = 1; j < m; j++) {
            if (arr[i][j] <= minElement) {  // Check for smaller or equal
                minElement = arr[i][j];
                colIndex = j;
            }
        }

        // Step 2: Check if this minimum element is the largest in its column
        bool isSaddlePoint = true;
        for (int k = 0; k < n; k++) {
            if (arr[k][colIndex] > minElement) {  // Must be greater than or equal to all in column
                isSaddlePoint = false;
                break;
            }
        }

        // If a saddle point is found, print it and stop
        if (isSaddlePoint) {
            cout << "Saddle point found at (" << i << ", " << colIndex << "): " << minElement << endl;
            found = true;
            break;
        }
    }

    // If no saddle point is found
    if (!found) {
        cout << "No saddle point found in the matrix." << endl;
    }
}

int main() {
    int n = 3, m = 3;

    // Predefined 2D array
    int arr[100][100] = {
        {3, 8, 5},
        {4, 9, 2},
        {6, 7, 1}
    };

    // Display the matrix
    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Find and display saddle point
    findSaddlePoint(arr, n, m);

    return 0;
}
