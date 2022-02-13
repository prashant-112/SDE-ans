2 pass solution:

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int leftsmall[n],rightsmall[n];
        stack<int> st;
        //compute the left small boundary
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) leftsmall[i] = 0;
            else leftsmall[i] = st.top()+1;
            st.push(i);
        }
        //dont create another stack just reuse it
        while(!st.empty()) st.pop();
        
        //compute for right small boundary
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) rightsmall[i] = n - 1;
            else rightsmall[i] = st.top()-1;
            st.push(i);
        }
        //now computing max area
        int MaxArea=0;
        for(int i=0;i<n;i++){
            MaxArea = max(MaxArea,((rightsmall[i] - leftsmall[i] + 1)*heights[i]));
        }
        return MaxArea;
    }
};


//one pass soln

class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        int maxA = 0;
        for(int i=0;i<=n;i++){ //iterate till n so that area of remaining element in stack can be computed
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1; //(RS-LS-1)
                maxA = max(maxA,height*width);
            }
            st.push(i);
        }
        return maxA;
    }
};
