class Solution {
    using coordinates = std::pair<size_t, size_t>; 
    using treasureChestCoordinateLength = std::pair<coordinates, int>;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        // we must implement a multisource bfs
        size_t rows = grid.size(); 
        if (rows == 0) return;
        size_t cols = grid[0].size();

        std::queue<treasureChestCoordinateLength> queue;

        for (size_t x = 0; x < rows; x++) {
            for (size_t y = 0; y < cols; y++) {
                if (grid[x][y] == 0) {
                    queue.push({{x, y}, 0});
                }
            }
        }

        while (queue.size() != 0) {
            const auto [coord, dist] = queue.front();
            const auto [x, y] = coord;
            queue.pop();

            if (x >= rows || y >= cols) continue;
            if (dist > 0 && grid[x][y] != std::numeric_limits<int>::max()) continue;

            grid[x][y] = dist;
            queue.push({{x + 1, y}, dist + 1});
            queue.push({{x - 1, y}, dist + 1});
            queue.push({{x, y + 1}, dist + 1});
            queue.push({{x, y - 1}, dist + 1});

        }
    }


};
