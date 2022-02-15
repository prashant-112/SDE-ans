class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        list<int> list;
        int i=0,j=0;
        int n = nums.size();
        while(j<n){
            //calculation
            if(list.empty()) list.push_back(nums[j]);
            else{
            while(!list.empty() && list.back()<nums[j])
                //removing all previous smaller element from the list
                list.pop_back();
            list.push_back(nums[j]);
            }
            //settling the given window size
            if(j-i+1 < k) j++;
            else if(j-i+1==k){
                ans.push_back(list.front());
                //sliding window & removing the recently slided element
                if(nums[i]==list.front()){
                    list.pop_front();
            }
                    i++;
                    j++;
            }
        }
        return ans;
        
    }
};
