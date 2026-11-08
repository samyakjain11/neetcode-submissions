class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // n = cooldown
        // tasks, we need to optimize to always have the task that has the most amount left?
        
        std::unordered_map<char, int> taskFreq;
        for (const auto& curChar : tasks) {
            ++taskFreq[curChar];
        }

        // always have the highest frequency task picked, that has cooled down?
        std::priority_queue<int, std::vector<int>> canExecuteTasks; // maxHeap;
        for (const auto [_, frequency] : taskFreq) {
            canExecuteTasks.emplace(frequency);
        }

        std::queue<pair<int, int>> waitingQueue; // {cycleEligibility, frequency}
        // idea is that when we execute from canExecuteTasks, we queue it on qaiting queue
        
        unsigned int currentCpuCycle = 0;
        while (!canExecuteTasks.empty() || !waitingQueue.empty()) {
            if(!waitingQueue.empty()) {
                const auto [cycleEligiblity, curFreq] = waitingQueue.front();
                if (currentCpuCycle >= cycleEligiblity) {
                    canExecuteTasks.emplace(curFreq);
                    waitingQueue.pop();
                }
            }

            if(!canExecuteTasks.empty()) {
                int remainingFrequency = canExecuteTasks.top() - 1;
                if (remainingFrequency != 0) {
                    waitingQueue.emplace(currentCpuCycle + n + 1, remainingFrequency);
                }
                canExecuteTasks.pop();
            }
            ++currentCpuCycle;
        }
        return currentCpuCycle;
    }
};
