#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int> &arr, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}
void heapsort(vector<int> &arr, int size)
{
    int n = size;
    while (n > 1)
    {
        swap(arr[0], arr[n - 1]);
        n--;
        heapify(arr, n, 0);
    }
}
int heap_max(vector<int> arr)  //O(1)
{
    return arr[0];
}
int extract_max(vector<int> &arr, int size) //O(log(n))
{
    if (arr.size() < 1)
    {
        cout << "priority queue underflow";
    }
    int max = arr[0];
    arr[0] = arr[size - 1];
    size--;
    arr.pop_back();
    heapify(arr, size, 0);
    return max;
}
void increase_key(vector<int> &arr, int i, int key) //O(Log(n))
{  
    if (key < arr[i])
    {
        cout << "new key smaller";
        return;
    }
    arr[i] = key;
    while (i > 0 && arr[(i - 1) / 2] < arr[i])
    {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void insertion(vector<int> &arr, int value, int &size)
{
    arr.push_back(value);
    size++;
    int index = size - 1;
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (arr[parent] < arr[index])
        {
            swap(arr[parent], arr[index]);
            index = parent;
        }
        else
            return;
    }
}
void deletion(vector<int> &arr, int &size)
{
    if (size == 0)
        return;
    arr[0] = arr[size - 1];
    size--;
    arr.pop_back();
    heapify(arr, size, 0);
}
int main()
{
    vector<int> arr = {0, 2, 10, 3, 9};
    int n = 5;
    for (int i = (n / 2 - 1); i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    // for(int i =0;i<arr.size();i++){
    //     cout<<arr[i]<<" ";
    // }
    // insertion(arr,12,n);
    // // for(int i =0;i<arr.size();i++){
    // //     cout<<arr[i]<<" "<<endl;
    // // }
    // deletion(arr,n);
    //  for(int i =0;i<arr.size();i++){
    //     cout<<arr[i]<<" "<<endl;
    // }
    // deletion(arr,n);
    //  for(int i =0;i<arr.size();i++){
    //     cout<<arr[i]<<" "<<endl;
    // }
    // int max=heap_max(arr);
    // cout<<max<<endl;
    // int max = extract_max(arr,n);
    // cout<<max<<endl;
    heapsort(arr, n);
    cout << "array after heap sort" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    // increase_key(arr,3,88);
    // for(int i =0;i<arr.size();i++){
    //     cout<<arr[i]<<" ";
    // }
}