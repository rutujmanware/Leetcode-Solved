//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string s="";
        while(n>0){
            int c = (n-1)%26;
            // cout<<c<<endl;
            s = char(c+'A') + s;
            // cout<<s<<endl;
            n = (n-1)/26;
        }
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends