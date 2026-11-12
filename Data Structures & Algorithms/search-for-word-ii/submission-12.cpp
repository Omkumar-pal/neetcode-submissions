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

class PrefixTrie {
   public:
    TrieNode* root;
    PrefixTrie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (curr->child[i] == nullptr) {
                curr->child[i] = new TrieNode();
            }
            curr = curr->child[i];
        }
        curr->isTerminal = true;
        return;
    }
};

class Solution {
   public:
    bool startWith(TrieNode* root, string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (curr->child[i] == nullptr) {
                return false;
            }
            curr = curr->child[i];
        }
        return true;
    }
    bool search(TrieNode* root, string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (curr->child[i] == nullptr) {
                return false;
            }
            curr = curr->child[i];
        }
        return curr->isTerminal;
    }
    TrieNode* buildTrie(vector<string> words) {
        PrefixTrie trie;
        for (const string& s : words) {
            trie.insert(s);
        }
        return trie.root;
    }

    void findWord(vector<vector<char>>& board, vector<string>& ans, TrieNode* curr, int i, int j,
                  int n, int m, string &s) {
        if ((i < 0 || i >= n) || (j < 0 || j >= m)) {
            return;
        }
        // preventing resuse of same visited cell, Since '#' - 'a' is negative, accessing child[idx] is invalid.
        if (board[i][j] == '#') return;
        int idx = board[i][j] - 'a';
        if (curr->child[idx] != nullptr) {
            // move to next pointer
            curr = curr->child[idx];
            // update s
            s.push_back(board[i][j]);
            // storing temp for wrong back traverse
            char temp = board[i][j];
            board[i][j] = '#';
            // if my final answer is found i will remove the isTerminal to false;
            if (curr->isTerminal) {
                ans.push_back(s);
                curr->isTerminal = false;
            }
            findWord(board, ans, curr, i + 1, j, n, m, s);
            findWord(board, ans, curr, i - 1, j, n, m, s);
            findWord(board, ans, curr, i, j + 1, n, m, s);
            findWord(board, ans, curr, i, j - 1, n, m, s);
            board[i][j] = temp;
            s.pop_back();
        }
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // if invalid size are given
        if (board.empty() || board[0].empty() || words.empty()) return {};
        int n = board.size();
        int m = board[0].size();
        vector<string> ans;
        TrieNode* root = buildTrie(words);
        string s = "";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                    findWord(board, ans, root, i, j, n, m, s);
            }
        }
        return ans;
    }
};
