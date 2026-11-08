class RandomizedSet {
private:
    std::vector<int> noPushTimeComplexityVector;
    std::unordered_map<int, int> valueIndexMapper;
    unsigned int containerSize;

public:
    RandomizedSet() {
        containerSize = 0;
    }
    
    bool insert(int val) {
        if (valueIndexMapper.find(val) != valueIndexMapper.end()) {
            return false;
        }
        if (containerSize == noPushTimeComplexityVector.size()) {
            noPushTimeComplexityVector.emplace_back(val); // we assume this is O(1);
        } else {
            noPushTimeComplexityVector[containerSize] = val;
        }

        valueIndexMapper[val] = containerSize;
        ++containerSize;
        return true;
    }
    
    bool remove(int val) {
        if (valueIndexMapper.find(val) == valueIndexMapper.end()) {
            return false;
        }
        
        unsigned int toRemoveIndex = valueIndexMapper[val];
        unsigned int fromSwapIndex = containerSize - 1;
        noPushTimeComplexityVector[toRemoveIndex] = noPushTimeComplexityVector[fromSwapIndex];
        valueIndexMapper[noPushTimeComplexityVector[toRemoveIndex]] = toRemoveIndex;
        valueIndexMapper.erase(val);
        --containerSize;
        return true;
    }
    
    int getRandom() {
        std::mt19937 rng(std::random_device{}());
        unsigned int randomIndex = std::uniform_int_distribution<unsigned int>(0, containerSize - 1)(rng);
        return noPushTimeComplexityVector[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */