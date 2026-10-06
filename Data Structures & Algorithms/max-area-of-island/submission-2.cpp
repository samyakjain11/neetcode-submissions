class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxAreaSeenSoFar = 0;
        for (size_t x = 0; x < grid.size(); x++) {
            for (size_t y = 0; y < grid[0].size(); y++) {
                if (grid[x][y] == 1) {
                    maxAreaSeenSoFar = max(computeAreaOfIsland(x, y, grid), maxAreaSeenSoFar);

                }
            }
        }
        return maxAreaSeenSoFar;
        

    }

private:
    static int computeAreaOfIsland(size_t x, size_t y, vector<vector<int>>& grid) {
        // if out of bounds, return 0;
        string coordConcat = to_string(x) + '#' + to_string(y); 
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
            return 0;
        } else if (grid[x][y] == 1) { // and not seen already, otherwise we are in inf loop
            grid[x][y] = -1;
            return 1 + 
                computeAreaOfIsland(x-1, y, grid) +
                computeAreaOfIsland(x+1, y, grid) +
                computeAreaOfIsland(x, y-1, grid) +
                computeAreaOfIsland(x, y+1, grid) ;
        } else {
            return 0;
        }
    }
};
