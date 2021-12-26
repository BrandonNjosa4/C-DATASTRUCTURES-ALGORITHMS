#include <iostream>
using namespace std;
void merge(int arr[], int l, int m, int r, int size)
{
    int i = l;
    int j = m + 1;
    int k = l;
    //create temp array
    int temp[size];
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {

            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    //copy remaining elements in first half if any
    while (i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // copy remaining elements in second half if any
    while (j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    //copy temp array to original
    for (int p = l; p <= r; p++)
    {
        arr[p] = temp[p];
    }
}

void mergeSort(int arr[], int l, int r, int size)
{
    if (l < r)
    {
        //find midpoint
        int m = (l + r) / 2;
        //recursive mergesort first and second halves
        mergeSort(arr, l, m, size);
        mergeSort(arr, m + 1, r, size);
        //merge
        merge(arr, l, m, r, size);
    }
}
int main()
{
    cout << "Enter size of array: " << endl;
    int size;
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
    mergeSort(myarray, 0, (size - 1), size); // mergesort(arr,left,right, size) called

    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }

    return 0;
}