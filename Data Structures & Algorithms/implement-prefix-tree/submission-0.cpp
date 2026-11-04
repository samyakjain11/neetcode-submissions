struct TrieNode {
    std::unordered_map<char, std::unique_ptr<TrieNode>> children;
    bool isEndOfWord = false;
};

class PrefixTree {
public:
    void insert(const std::string& word) {
        TrieNode* node = &root;
        for (char c : word) {
            auto& child = node->children[c];          // inserts null if missing
            if (!child) child = std::make_unique<TrieNode>();
            node = child.get();
        }
        node->isEndOfWord = true;
    }

    bool search(const std::string& word) const {
        const TrieNode* node = walk(word);
        return node && node->isEndOfWord;
    }

    bool startsWith(const std::string& prefix) const {
        return walk(prefix) != nullptr;
    }

private:
    // Follow the path; nullptr if it breaks off.
    const TrieNode* walk(const std::string& s) const {
        const TrieNode* node = &root;
        for (char c : s) {
            auto it = node->children.find(c);
            if (it == node->children.end()) return nullptr;
            node = it->second.get();
        }
        return node;
    }

    TrieNode root;
};