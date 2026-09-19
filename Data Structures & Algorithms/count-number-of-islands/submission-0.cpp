class Solution {
public:
    

    void bfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&grid) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1}; 

        queue<pair<int,int>>q;
        q.push({row,col});

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && !vis[nr][nc]) {
                    bfs(nr, nc, vis, grid);
                }
            }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    bfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
