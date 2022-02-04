TC : O(NlogN)
bool wecanAllocate(vector<int> &A,int maxAllocation,int students){
    int cntStud = 0;
    int maxAllocate = 0;
    for(int i=0;i<A.size();i++){
        if(maxAllocate + A[i] > maxAllocation){
            cntStud++;
            maxAllocate = A[i];
            if(maxAllocate > maxAllocation) return false;
        }
        else{
            maxAllocate += A[i];
        }
    }
    if(cntStud < students) return true;
    return false;
}
int Solution::books(vector<int> &A, int B) {
    if(B > A.size()) return -1;
    int low = A[0];
    int high = 0;
    
    for(int i=0;i<A.size();i++){
        high += A[i];
        low = min(low,A[i]);
    }
    int res = -1;
    while(low<=high){
        int mid = (low+high) >> 1;
        if(wecanAllocate(A,mid,B)){
            res = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
     return low;
}


