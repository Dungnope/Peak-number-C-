//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int peakElement(vector<int> &arr) {
        int l = 0;
        int n = arr.size();
        int r = n - 1;
        if(arr[l] > arr[l+1])
        {
            return l;
        }
        else if(arr[r] > arr[r-1]) return r;

        while(r >= l)
        {
            int mid = (l + r) / 2;
            if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
            {
                return mid;
            }
            
            if(arr[mid] < arr[mid + 1])
            {
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int idx = ob.peakElement(a);
        int n = a.size();
        bool f = 0;
        if (idx < 0 && idx >= n)
            cout << "false" << endl;
        else {
            if (n == 1 && idx == 0)
                f = 1;
            else if (idx == 0 && a[0] > a[1])
                f = 1;
            else if (idx == n - 1 && a[n - 1] > a[n - 2])
                f = 1;
            else if (a[idx] > a[idx + 1] && a[idx] > a[idx - 1])
                f = 1;
            else
                f = 0;
            if (f)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends