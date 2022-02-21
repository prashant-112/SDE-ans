// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
      stack<int> st;
      vector<int>ans(n);
    for(int i = 0;i<=n;i++) {
           while(!st.empty() && (i==n || arr[st.top()] >= arr[i])) {
               int height = arr[st.top()];
               st.pop(); 
               int width; 
               if(st.empty()) width = i-1; 
               else width = i - st.top() - 2; 
               
                ans[width]=max(ans[width],height);
           }
           st.push(i); 
       }
      for(int i=n-2;i>=0;i--){ans[i]=max(ans[i],ans[i+1]);}
      return ans;
  }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
