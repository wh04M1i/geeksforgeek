//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int left = 0;
        int count = 0;
        long long product = 1;

        for (int right = 0; right < n; right++) {
            product *= a[right];
            
            while (product >= k && left <= right) {
                product /= a[left];
                left++;
            }
            
            count += (right - left + 1);
        }

        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends