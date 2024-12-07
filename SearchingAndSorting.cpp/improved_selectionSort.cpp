#include <iostream>
using namespace std;

// Function to implement the improved selection sort
void improvedSelectionSort(int arr[], int n) {
    int start = 0;  // Start of the unsorted portion
    int end = n - 1;  // End of the unsorted portion

    // Perform sorting till the start and end overlap
    while (start < end) {
        int minIndex = start;
        int maxIndex = start;

        // Find the minimum and maximum in the current unsorted portion
        for (int i = start; i <= end; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        // Swap the minimum element with the start element
        if (minIndex != start) {
            swap(arr[minIndex], arr[start]);
        }

        // Adjust maxIndex if it was swapped with the start element
        if (maxIndex == start) {
            maxIndex = minIndex;  // Update maxIndex if it got swapped
        }

        // Swap the maximum element with the end element
        if (maxIndex != end) {
            swap(arr[maxIndex], arr[end]);
        }

        // Move the boundaries inward
        start++;
        end--;
    }
}

// Function to display the array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Driver function
int main() {
    int arr[] = {29, 10, 14, 37, 13, 8, 19, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    displayArray(arr, n);

    improvedSelectionSort(arr, n);

    cout << "Sorted array: ";
    displayArray(arr, n);

    return 0;
}

