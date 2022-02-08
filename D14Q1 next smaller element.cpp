class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        vector<int> nse(n,-1);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            if(!s.empty() && s.top() < arr[i]){
                nse[i] = s.top();
            }
            else if(!s.empty() && s.top() >= arr[i]){   // pop the element till we find the smaller element into our stack
                while(!s.empty() && s.top() >= arr[i]){
                        s.pop();
                }
                if(!s.empty()){
                    nse[i] = s.top();
                }
            }
            s.push(arr[i]);
        }
        return nse;
    } 
};
