class Solution {
public:
    int bfs(int row, int col,vector<vector<int>>&vis, vector<vector<int>>&grid) {
        int cnt = 0;
        queue<pair<int,int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        int n = grid.size();
        int m = grid[0].size();



        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            cnt++;
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }

        }
        return cnt;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int area = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0;j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    area = max(area, bfs(i,j,vis,grid));
                }
            }
        }
        return area;
    }
};
