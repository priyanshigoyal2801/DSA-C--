#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int begin, int end) {
    int mid = begin + (end - begin) / 2;
    int pivot = arr[mid];
    int left = begin;
    int right = end;

    while (left <= right) {
        while (arr[left] < pivot) {
            left++;
        }
        while (arr[right] > pivot) {
            right--;
        }
        if (left <= right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    return left;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int par = partition(arr, low, high);
        quickSort(arr, low, par - 1);
        quickSort(arr, par, high);
    }
}

int main() {
    vector<int> arr = {6, 3, 9, 1, 8};
    quickSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
