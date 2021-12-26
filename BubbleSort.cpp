#include <iostream>
using namespace std;

//optimized bubble sort with booleans
void bubbleSort(int a[])
{
    int rounds = 0;
    for (int i = 0; i < 5; i++)
    {
        rounds++;
        bool flag = false;
        for (int j = 0; j < (5 - i - 1); j++)
        {
            if (a[j] > a[j + 1])
            {
                flag = true;
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
    cout << "Number of rounds: " << rounds << endl;
}

int main()
{
    int myarray[5];
    int size;
    cout << "Enter 5 integers in any order: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> myarray[i];
    }
    cout << "Before Sorting" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << myarray[i] << " ";
    }

    bubbleSort(myarray); // sorting

    cout << endl
         << "After Sorting" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << myarray[i] << " ";
    }

    return 0;
}