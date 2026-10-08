class Solution {
    using coordinates = std::pair<size_t, size_t>;
    using coordinatesMinutePassed = std::pair<coordinates, int>;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const size_t rows = grid.size();
        if (rows == 0) return 0;
        const size_t cols = grid[0].size();

        constexpr int ROTTEN = 2;
        constexpr int FRESH = 1;

        std::queue<coordinatesMinutePassed> rottenFruit;
        int fresh = 0;

        for (size_t x = 0; x < rows; x++) {
            for (size_t y = 0; y < cols; y++) {
                if (grid[x][y] == ROTTEN) rottenFruit.push({{x, y}, 0});
                else if (grid[x][y] == FRESH) ++fresh;
            }
        }

        // check and mark at push time so each cell is queued once
        auto infect = [&](size_t x, size_t y, int minute) {
            if (x >= rows || y >= cols || grid[x][y] != FRESH) return;
            grid[x][y] = ROTTEN;
            --fresh;
            rottenFruit.push({{x, y}, minute});
        };

        int maxMinutes = 0;
        while (!rottenFruit.empty()) {
            const auto [coord, minute] = rottenFruit.front();
            const auto [x, y] = coord;
            rottenFruit.pop();

            maxMinutes = std::max(maxMinutes, minute);

            infect(x + 1, y, minute + 1);
            infect(x - 1, y, minute + 1);
            infect(x, y + 1, minute + 1);
            infect(x, y - 1, minute + 1);
        }

        return fresh == 0 ? maxMinutes : -1;
    }
};