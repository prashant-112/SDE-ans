https://www.interviewbit.com/problems/matrix-median/#

TC: log(2^32) * n * logm = 32*n*logm
int smalleequalTomid(vector<int> &row,int mid){
    int l = 0, h = row.size()-1;
    while(l<=h){
        int md = (l+h)/2;
        if(row[md] <= mid) l = md + 1;
        else {
            h = md - 1;
        }
    }
    return l;
}
int Solution::findMedian(vector<vector<int> > &A) {
    int low = 1;
    int hi = 1e9;// our search space [1......     ..1e9]
    int n = A.size();
    int m = A[0].size();
    while(low<=hi){
        int mid = (low+hi)/2;
        int cnt = 0; //this will cnt no. of elements <=mid
        for(int i=0;i<n;i++){
            cnt += smalleequalTomid(A[i],mid);
        }
        if(cnt <= (n*m)/2) low = mid+1;
        else{
            hi = mid-1;
        }
    } 
    return low;
}
