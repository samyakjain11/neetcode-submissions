class Solution {
public:
    static int accessUsingRawIndex(const vector<vector<int>> & matrix, const size_t& rawIndex) {
        int n = matrix[0].size();
        return matrix[rawIndex / n][rawIndex % n];
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix[0].size() * matrix.size() - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            int currentElement = accessUsingRawIndex(matrix, middle);
            if (currentElement == target) {
                return true;
            } else if (currentElement > target) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return false;

    }
};
