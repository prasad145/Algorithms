#include<bits/stdc++.h>
using namespace std;
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

    if(binary_search(a, 0, n - 1, key))
    {
        cout << "found" << "\n";
    }
    else
    {
        cout << "Not found" << "\n";
    }
    
    return 0;
}
