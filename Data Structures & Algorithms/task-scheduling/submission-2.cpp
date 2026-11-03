class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::priority_queue<int, std::vector<int>> tasksReadyToRun;
        std::queue<pair<int, int>> waitingQueue; // first = which cycle it can run, second = frequency

        // all tasks are ready to run at first
        std::unordered_map<char, int> frequencyDeriver;
        for (const char& task : tasks) {
            ++frequencyDeriver[task];
        }

        for (const auto& [task, frequency]: frequencyDeriver) {
            tasksReadyToRun.emplace(frequency);
        }

        int currentCycle = 0;
        while (!(tasksReadyToRun.empty() && waitingQueue.empty())) {
            if (!waitingQueue.empty()) {
                const auto [eligibleCycle, frequency] = waitingQueue.front();
                if (eligibleCycle <= currentCycle) {
                    waitingQueue.pop();
                    tasksReadyToRun.emplace(frequency);
                }
            }

            if (!tasksReadyToRun.empty()) {
                int frequencyLeft = tasksReadyToRun.top() - 1;
                if (frequencyLeft != 0) {
                    waitingQueue.emplace(currentCycle + n + 1, frequencyLeft);
                }
                tasksReadyToRun.pop();
            }

            ++currentCycle;
        }

        return currentCycle;

    }
};
