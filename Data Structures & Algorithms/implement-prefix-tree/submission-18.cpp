
// implementing Trie
class TrieNode {
   public:
    char data;
    vector<TrieNode*> child;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        child = vector<TrieNode*>(26, nullptr);
        isTerminal = false;
    }
};

class PrefixTree {
   private:
    TrieNode* root;
    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int idx = word[0] - 'a';
        TrieNode* child;

        // if root->child[idx] exist or not
        // if it exist then move child to the root->child[idx];
        // if not then creat child node and set root->child[idx] = child;
        if (root->child[idx] != nullptr) {
            child = root->child[idx];
        } else {
            child = new TrieNode(word[0]);
            root->child[idx] = child;
        }

        insertUtil(child, word.substr(1));
    }

    bool searchUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int idx = word[0] - 'a';
        TrieNode* child;
        if (root->child[idx] != nullptr) {
            child = root->child[idx];
        } else {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool startWithUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            return true;
        }

        int idx = word[0]-'a';
        TrieNode* child;

        if (root->child[idx] != nullptr) {
            child = root->child[idx];
        } else {
            return false;
        }

        return startWithUtil(child, word.substr(1));
    }

   public:
    PrefixTree() { root = new TrieNode('\0'); }
    void insert(string word) {
        insertUtil(root, word);
        return;
    }

    bool search(string word) { return searchUtil(root, word); }

    bool startsWith(string prefix) { return startWithUtil(root, prefix); }
};
