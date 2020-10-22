#include<iostream>
using namespace std;

int main()
{
    int n, i, j, temp;
    cout << "Enter the number of elements" << endl;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << " th element";
        cin >> arr[i];
    }

    for (i = n; i > 0; i--)
    {
        for (j = 0; j < i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "\nSorted Elements are\n";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
