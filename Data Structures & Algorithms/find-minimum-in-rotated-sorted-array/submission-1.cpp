class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int minimumElement = nums[0];

        while (left <= right) {
            
            if (nums[left] < nums[right]) {
                minimumElement = min(minimumElement, nums[left]);
                break;
            } 
            int middle = (left + right) / 2;
            minimumElement = min(nums[middle], minimumElement);
            if (nums[middle] >= nums[left]) {
                left = middle + 1;
                minimumElement = min(nums[middle], minimumElement);
            } else {
                right = middle - 1;
            }
        }

        return minimumElement;
    }
};
