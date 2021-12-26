#include <iostream>
using namespace std;
int partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int pIndex = s;

    for (int i = s; i < e; i++)
    {
        if (arr[i] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }

    int temp = arr[e];
    arr[e] = arr[pIndex];
    arr[pIndex] = temp;

    return pIndex;
}

void quickSort(int arr[], int s, int e)
{
    if (s < e)
    {
        int p = partition(arr, s, e);
        quickSort(arr, s, (p - 1)); //recursive call for left side
        quickSort(arr, (p + 1), e); //recursive call for right side
    }
}
int main()
{

    int size = 0;
    cout << "Enter Size of array: " << endl;
    cin >> size;
    int myarray[size];

    cout << "Enter " << size << " integers in any order: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> myarray[i];
    }
    cout << "Before Sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }
    cout << endl;

    quickSort(myarray, 0, (size - 1)); // quick sort called

    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }

    return 0;
}