#include<bits/stdc++.h>
using namespace std;
bool linear_search(int a[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            return true;
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

    if(linear_search(a, n, key))
    {
        cout << "found" << "\n";
    }
    else
    {
        cout << "Not found" << "\n";
    }
    
    return 0;
}
