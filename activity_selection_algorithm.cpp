#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;


    int s[n], f[n];


    cout << "Enter start times for each activity:\n";
    for (int i = 0; i < n; i++) {
            cin>>s[i];
    }
    cout << "Enter finish times for each activity:\n";
    for (int i = 0; i < n; i++) {
            cin>>f[i];
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(f[i]>f[j])
            {
                swap(f[i],f[j]);
                swap(s[i],s[j]);
            }

        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<" ";

    }
    for(int i=0;i<n;i++)
    {
        cout<<f[i]<<" ";

    }






    cout << "Selected activities: ";
    cout << 0 << " ";

    int k = 0;

    for (int i = 1; i < n; i++) {
        if (f[k]<=s[i]) {
            cout << i << " ";
            k = i;
        }
    }
    cout << endl;

    return 0;
}
