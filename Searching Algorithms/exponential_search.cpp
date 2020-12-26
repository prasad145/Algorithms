#include<bits/stdc++.h>
using namespace std;
/*
The idea is to start with subarray size 1, compare its last element with x, then try size 2, then 4 and so on until last element of a subarray is not greater. 
Once we find an index i (after repeated doubling of i), we know that the element must be present between i/2 and i (Why i/2? because we could not find a greater value in previous iteration)
Given below are the implementations of above steps.
*/
bool binary_search(int a[], int, int, int);

bool exponential_search(int a[], int r, int key)
{
    if(a[0] == key)
        return true;
    
    int i = 1;
    while(i < r && a[i] <= key)
    {
        i *= 2;
    }

    return binary_search(a, i/2, min(i, r), key);
}

bool binary_search(int a[], int l, int r, int key)
{
    if(r >= l)
    {
        int mid = l + (r - l)/2;
        
        
        if(a[mid] == key)
        {    
        return true;
        }
        else
        {
            if(a[mid] > key)
            {
                return binary_search(a, l, mid - 1, key);
            }
            else
            {
                return binary_search(a, mid + 1, r, key);
            }
            
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int key;
    scanf("%d", &key);

    if(exponential_search(a, n - 1, key))
    {
        cout << "found" << "\n";
    }
    else
    {
        cout << "Not found" << "\n";
    }
    
    return 0;
}
