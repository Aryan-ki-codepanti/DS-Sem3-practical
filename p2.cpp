#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int x)
{
    int left, right, mid;
    left = 0;
    right = n - 1;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (arr[mid] == x)
            return mid;

        else if (arr[mid] > x) // search in left half
            right = mid - 1;

        else
            left = mid + 1;
    }

    return -1;
}



int main()
{
    int n, x, pos;
    cout << "Enter number of elements : " << endl;
    cin >> n;
    int arr[n];

    cout << "Enter elements of array" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to be searched" << endl;
    cin >> x;
    pos = binary_search(arr, n, x);

    if (pos == -1)
        cout << x << " not found in array" << endl;
    else
        cout << x << "  found in array at index " << pos << endl;
    return 0;
}