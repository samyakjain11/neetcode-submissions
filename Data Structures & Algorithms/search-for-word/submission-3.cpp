class Solution {
    using Coordinate = std::pair<std::size_t, std::size_t>;
public:
    bool exist(vector<vector<char>>& board, string word) {
        // heavy back tracking, we need to do so with every cell + its neighbors but we can in fact terminate early & only trigger back tracking while word matches?
        for (std::size_t x = 0; x < board.size(); ++x) {
            for (std::size_t y = 0; y < board[x].size(); ++y) {
                std::size_t index = 0;
                std::string curString;
                std::unordered_set<string> seenCoords;
                if (backtrack(board, curString, std::pair(x, y), word, index, seenCoords)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool backtrack(const std::vector<std::vector<char>>& board, std::string& currentBuiltWord, Coordinate coordinate, std::string& targetWord, std::size_t curIndex, std::unordered_set<string>& seenCoords) {
        const auto [x, y] = coordinate;
        if (x >= board.size() || y >= board[0].size()) return false;
        if (board[x][y] != targetWord[curIndex]) return false;
        std::string coordStr = std::to_string(x) + "#" + std::to_string(y);
        if (board[x][y] == targetWord[curIndex] && !seenCoords.contains(coordStr)) {
            if (curIndex == targetWord.size() - 1) {
                return true;
            }
            seenCoords.insert(coordStr);
            const auto left =   std::pair(x - 1, y);
            const auto right =  std::pair(x + 1, y);
            const auto up =     std::pair(x, y - 1);
            const auto down =   std::pair(x, y + 1);
            currentBuiltWord += board[x][y];

            const bool found =  
                backtrack(board, currentBuiltWord, left, targetWord, curIndex + 1, seenCoords) ||
                backtrack(board, currentBuiltWord, right, targetWord, curIndex + 1, seenCoords) ||
                backtrack(board, currentBuiltWord, up, targetWord, curIndex + 1, seenCoords) ||
                backtrack(board, currentBuiltWord, down, targetWord, curIndex + 1, seenCoords);
            if(found) {
                return true;
            } else {
                seenCoords.erase(coordStr);
                currentBuiltWord.pop_back();
                return false;
            }
        }
        
        return false;

    } 
};
