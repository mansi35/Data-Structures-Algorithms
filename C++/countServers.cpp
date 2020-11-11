class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int numServers = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }   
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 and (row[i] >= 2 or col[j] >= 2)) {
                    numServers++;
                }   
            }
        }
        return numServers;
    }
};
