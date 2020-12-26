#include<bits/stdc++.h>
using namespace std;
// Probe position formula
bool interpolation_search(int a[], int r, int key)
{
    int low = 0, high = r;
    while(low <= high && key >= a[low] && key <= a[high])  
    {
        if(low == high)
        {
            if(a[low] == key)
                return true;
            return false;
        }

        // probing the position with keeping uniform distribution in mind
        int pos = low + (((double) (high - low) / (a[high] - a[low])) * (key - a[low]));

        if(a[pos] == key)
            return true;

        if(a[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
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

    if(interpolation_search(a, n - 1, key))
    {
        cout << "found" << "\n";
    }
    else
    {
        cout << "Not found" << "\n";
    }
    
    return 0;
}
