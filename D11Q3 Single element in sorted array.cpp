As we are using binary search our TC: O(logN)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-2; //second last index
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid]==nums[mid^1]) //checking if it is left or right half
                lo = mid+1;
            else
                hi = mid-1;
        }
        return nums[lo];
    }
};
/* checking for left instance :
the 1st appearnce of the number should be on even index & the 2nd appearance should be on odd index;  if it is not then we are in right half */
