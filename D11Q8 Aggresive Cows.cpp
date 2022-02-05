#include<bits/stdc++.h>
using namespace std;

bool CanCowPlaced(int A[],int n,int minDist,int cows){
    int cntCows = 1;
    int lastcowPlaced = A[0];
    for(int i=0;i<n;i++){
        if(A[i] - lastcowPlaced >= minDist){
            cntCows++;
            lastcowPlaced = A[i];
        }
    }
    if(cntCows >= cows) return true;
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,cows;
        cin>>n>>cows;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        sort(A,A+n);
        int low = 1;
        int high = A[n-1] - A[0];
        
        while(low<=high){
            int mid = (low+high) >> 1;
            if(CanCowPlaced(A,n,mid,cows)){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    cout << high <<endl;
    }
    return 0;
}

     
