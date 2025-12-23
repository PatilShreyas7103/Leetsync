#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26] = {nullptr};
    string completeWord = "";
};

class Solution {
private:
    TrieNode* root;

    void insertWord(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!current->children[idx]) {
                current->children[idx] = new TrieNode();
            }
            current = current->children[idx];
        }
        current->completeWord = word;
    }

    void dfs(int row, int col,
             vector<vector<char>>& board,
             TrieNode* currentNode,
             vector<string>& result) {

        char ch = board[row][col];
        if (ch == '#') return;

        int idx = ch - 'a';
        if (!currentNode->children[idx]) return;

        currentNode = currentNode->children[idx];

        if (!currentNode->completeWord.empty()) {
            result.push_back(currentNode->completeWord);
            currentNode->completeWord.clear();
        }

        board[row][col] = '#';

        if (row > 0) dfs(row - 1, col, board, currentNode, result);
        if (col > 0) dfs(row, col - 1, board, currentNode, result);
        if (row + 1 < board.size()) dfs(row + 1, col, board, currentNode, result);
        if (col + 1 < board[0].size()) dfs(row, col + 1, board, currentNode, result);

        board[row][col] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();

        for (const string& word : words) {
            insertWord(word);
        }

        vector<string> result;
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(r, c, board, root, result);
            }
        }

        return result;
    }
};