// iterative
// #include <iostream>
// using namespace std;
// int BS(int arr[], int n, int element)
// {
//     int low = 0;
//     int high = n - 1;

//     while (low <= high)
//     {
//         int mid = (low + high) / 2;
//         if (arr[mid] == element)
//         {
//             return mid;
//         }
//         else if (arr[mid] > element)
//         {
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     return -1;
// }
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int c = BS(arr, n, 6);
//     if (c == -1)
//     {
//         cout << "element not found";
//     }
//     else
//     {
//         cout << "element found at " << c;
//     }
// }

//recursive
#include <iostream>
using namespace std;
int BS(int arr[], int n, int element, int l, int r)
{
    

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] > element)
        {
           return BS(arr,n,element,l,mid-1);
        }
        else
        {
           return BS(arr,n,element,mid+1,r);
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int c = BS(arr, n, 1,0,n-1);
    if (c == -1)
    {
        cout << "element not found";
    }
    else
    {
        cout << "element found at " << c;
    }
}

