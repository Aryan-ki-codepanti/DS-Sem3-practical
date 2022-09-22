#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
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
    pos = linear_search(arr, n, x);

    if (pos == -1)
        cout << x << " not found in array" << endl;
    else
        cout << x << "  found in array at index " << pos << endl;
    return 0;
}