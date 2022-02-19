class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
        queue<pair<int,int>> rotten;  //stores rotten oranges              
        int m = grid.size() , n = grid[0].size() , totalorange=0 , cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0) totalorange++; //count total oranges present in grid
                if(grid[i][j]==2) rotten.push({i,j});
            }
        }
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k;
            while(k--){
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();
                for(int i=0;i<4;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];    // this nx ny tells where wew are moving(up,down,right,left)
                    //check if it is inside the boundary
                    if(nx<0 || ny<0|| nx>=m || ny>=n || grid[nx][ny]!=1) continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx,ny});
                }
            }
            if(!rotten.empty()) minutes++;
        }
        return totalorange==cnt?minutes:-1;
    }
};
