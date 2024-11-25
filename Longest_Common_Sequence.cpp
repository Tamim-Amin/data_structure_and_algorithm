#include <bits/stdc++.h>
using namespace std;

// Function to calculate the length of Longest Common Subsequence (LCS)
int LCS(string s1, string s2, int x, int y, int c[100][100])
{
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)//PRESIDENT   PROVIDENCE
        {
            if (s1[i - 1] == s2[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i][j - 1], c[i - 1][j]);
        }
    }
    return c[x][y];
}

// Function to reconstruct the Longest Common Subsequence (LCS) string
string getLCS(string s1, string s2, int x, int y, int c[100][100])
{
    string lcs = "";
    int i = x, j = y;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs = s1[i - 1] + lcs;
            i--;
            j--;
        }
        else if (c[i - 1][j] >= c[i][j - 1])
            i--;
        else
            j--;
    }
    return lcs;
}

// Function to display the DP table
void printTable(int c[100][100], int x, int y)
{
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    string s1, s2;

    // Take user input for the two strings
    cout << "Enter the first string: ";
    cin >> s1;

    cout << "Enter the second string: ";
    cin >> s2;

    int x = s1.size();
    int y = s2.size();

    int c[100][100] = {0};

    // Calculate the length of LCS and fill the table
    int lcs_length = LCS(s1, s2, x, y, c);

    // Display the DP table
    cout << "DP Table: " << endl;
    printTable(c, x, y);
    cout << endl;

    // Get the actual LCS string
    string lcs = getLCS(s1, s2, x, y, c);

    // Display the LCS length and the LCS string
    cout << "Length of LCS: " << lcs_length << endl;
    cout << "LCS: " << lcs << endl;

    return 0;
}
