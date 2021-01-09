#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int n)
{
    int mini;
    for(int i = 0; i < n - 1; i++)
    {
        mini = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        swap(&arr[mini], &arr[i]); 
    }
} 

void print_array(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr, n);
    print_array(arr, n);
    return 0;
}
