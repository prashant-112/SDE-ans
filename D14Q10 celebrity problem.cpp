O(N^2) soln:

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int in[n]={0}; // total persons who knows that element
        int out[n]={0}; //total person whom that element knew
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(M[i][j]==1){ //i knows j
                    in[j]++; //j is known & it might be a celebrity
                    out[i]++; //i is not a celebrity
                } 
            }
        }
        for(int j=0;j<n;j++){
            if(in[j]==n-1 && out[j]==0){ //j dont know anybody and everybody knows him
                return j; //celebrity
            }
        } 
        return -1;
    }
};

O(N) soln:

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int c=0; //celebrity
        for(int i=0;i<n;i++){
            if(M[c][i]==1){ //C knows i thus C is not celebrity
                c=i; //lets check if i is celebrity or not
            }
        }
        for(int i=0;i<n;i++){
            if(i!=c && (M[c][i]==1||M[i][c]==0)){ //checking if c is our celebrity or not
                return -1;
            }
        }
        return c;
    }
};
