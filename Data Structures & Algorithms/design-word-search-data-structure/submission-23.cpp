class TrieNode {
   public:
    TrieNode* child[26];
    bool isTerminal;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        isTerminal = false;
    }
};
class WordDictionary {
   public:
    TrieNode* root;
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (curr->child[i] == nullptr) {
                curr->child[i] = new TrieNode();
            }
            curr = curr->child[i];
        }
        curr->isTerminal = true;
    }
    bool dfs(int j, string word, TrieNode* root) {
        TrieNode* curr = root;
        for (int i = j; i < word.size(); i++) {
            if (word[i] == '.') {
                for (TrieNode* node : curr->child) {
                    if (node != nullptr && dfs(i + 1, word, node)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (curr->child[word[i] - 'a'] == nullptr) {
                    return false;
                }
                curr = curr->child[word[i] - 'a'];
            }
        }

        return curr->isTerminal;
    }
    bool search(string word) { return dfs(0, word, root); }
};
