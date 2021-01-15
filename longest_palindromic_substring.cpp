#include<iostream>
using namespace std;
void printString(string s, int l, int r)
{
    for(int i = l; i <= r; i++)
    {
        cout <<s[i];
    }
    cout<< "\n";
}

int LongestPalindromicSubstring(string s)
{
    int n = s.length();
    bool dp[n + 1][n + 1];

    //filling dp table for string of length 1 (palindrome)
    for(int i = 0; i < n; i++)
    {
        dp[i][i] =  true; 
    }
    
    int start, maxLength;
    //string of length palindrome only if they are equal to each other
    for(int i = 0; i < n - 1; i++)
    {
        if(s[i] == s[i + 1])
        {
            dp[i][i+1] = true;
            start = i;
            maxLength = 2; 
        }
    }

    //for string of length greater than 2 
    for(int k = 3; k <= n; k++)
    {
        //starting index of a string
        for(int i = 0; i < n - k + 1; i++)
        {
            //ending index of a string 
            int j = i + k - 1;
            if(s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
                if(k > maxLength)
                {
                    maxLength = k;
                    start = i;
                }
            }
            
        }
    }
    printString(s, start, start + maxLength - 1);
    return maxLength;
}

int main()
{
    string s;
    cin >> s;
    cout << LongestPalindromicSubstring(s) << "\n";
    return 0;
}
