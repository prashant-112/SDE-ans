class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int n = nums1.size();
        int m = nums2.size();
        int lo = 0; int hi = n;
        
        while(lo <= hi){
            int partition1 = (lo+hi) >> 1; //partitioning the 1st array
            int partition2 = (n+m+1)/2 - partition1; //taking remaining element from 2nd array
            
            int left1 = partition1==0?INT_MIN:nums1[partition1-1];
            int left2 = partition2==0?INT_MIN:nums2[partition2-1];
            
            int right1 = partition1==n?INT_MAX:nums1[partition1];
            int right2 = partition2==m?INT_MAX:nums2[partition2];
            
            if(left1<=right2 && left2<=right1){
                if((n+m)%2==0) //if total size is 0
                    return (min(right1,right2) + max(left1,left2))/2.0;
                else
                    return max(left1,left2);
            }
            else if(left1 > right2)
                hi = partition1-1;
            else
                lo = partition1+1;
        }
        return 0;
    }   
};
