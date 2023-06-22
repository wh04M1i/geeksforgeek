//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool lemonadeChange(int n, vector<int> &arr) {
        // code here
        int s=0;
        int h[21]={0};
        for(int i=0; i<n; i++){
            if(arr[i]==10){
                if(h[arr[i]-5]<=0)return false;
                else{
                    h[arr[i]-5]--;
                }
            }
            else if(arr[i]==20){
                if(h[arr[i]-10]<=0){
                    if(h[arr[i]-15]<3){
                        return false;
                    }else{
                        h[arr[i]-15]=h[arr[i]-15]-3;
                    }
                }
                else if(h[arr[i]-15]<=0){
                    return false;
                }
                else{
                    h[arr[i]-10]--;
                    h[arr[i]-15]--;
                }
            }
            h[arr[i]]++;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
