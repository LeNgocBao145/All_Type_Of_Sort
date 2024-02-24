#include <iostream>
#include <fstream>
#include <cstring>

#include <vector>
//#include <algorithm>

using namespace std;

void merge(int s[], int l, int m, int r);

void merge(int s[], int l, int m, int r);

void selectionSort(int arr[], int n);

void insertionSort(int arr[], int n);

void countingSort(int arr[], int n);

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[index] > arr[j])
            {
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }

    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        int pos = i - 1;
        while (pos >= 0 && x < arr[pos])
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = x;
    }

    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
}

void countingSort(int arr[], int n)
{
    int count[100001]{};
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
        m = max(m, arr[i]);
    }

    for (int i = 0; i <= m; i++)
    {
        if (count[i] != 0)
        {
            for (int j = 0; j < count[i]; j++)
            {
                cout << i << " ";
            }
        }
    }


}

void mergeSort(int s[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = (l + r) / 2;
    mergeSort(s, l, m);
    mergeSort(s, m + 1, r);
    merge(s, l, m, r);
}
void merge(int s[], int l, int m, int r)
{
    vector<int> x(s + l, s + m + 1);
    vector<int> y(s + m + 1, s + r + 1);
    int i = 0;
    int j = 0;

    while (i < x.size() && j < y.size())
    {
        if (x[i] < y[j])
        {
            s[l] = x[i];
            l++;
            i++;
        }
        else
        {
            s[l] = y[j];
            j++;
            l++;
        }
    }

    while (i < x.size())
    {
        s[l] = x[i];
        l++;
        i++;
    }

    while (j < y.size())
    {
        s[l] = y[j];
        l++;
        j++;
    }

}

int main() {
    int numbers[20];
    int n;
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        cin >> numbers[j];
    }
    mergeSort(numbers, 0, 9);
    for (int j = 0; j < n; j++)
    {
        cout << numbers[j] << " ";
    }
    return 0;
}
