#include<bits/stdc++.h>
using namespace std;
// array should be sorted!!
bool Jump_Search(int a[], int n, int key)
{
    int jump = sqrt(n);

    int previous_position = 0;
    while(a[min(jump,n) - 1] < key)
    {
        previous_position = jump;
        jump += sqrt(n);
        if(previous_position >= n)
            return false;
    }

    while(a[previous_position] < key)
    {
        previous_position++;
        if(previous_position == min(jump, n))
            return false;
        
        if(a[previous_position] == key)
            return true;
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
    cin >> key;

    if(Jump_Search(a, n, key))
    {
        cout << "Key -->" << key <<" found"<<"\n";
    }
    else
    {
        cout << "Key -->" << key <<" not found"<<"\n";
    }

}
