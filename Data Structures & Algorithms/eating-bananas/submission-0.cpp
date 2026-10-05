class Solution {
public:
    bool doesSpeedSuffice(const vector<int>& piles, int h, int speed) {
        long hoursTaken = 0;
        for (const double& numBananas : piles) {
            hoursTaken += ceil(numBananas / speed);
            if (hoursTaken > h) return false; 
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int ceilingSpeed = 0;
        for (const auto& pileNum : piles) {
            ceilingSpeed = max(ceilingSpeed, pileNum);
        }

        int left = 1;
        int right = ceilingSpeed;
        int derivedMinSpeed = right;
        while (left <= right) {
            int k = (left + right) / 2;
            if (doesSpeedSuffice(piles, h, k)){
                // go down
                derivedMinSpeed = k;
                right = k - 1;
            } else {
                // go up
                left = k + 1;
            }
        }
        return derivedMinSpeed;
    }
};
