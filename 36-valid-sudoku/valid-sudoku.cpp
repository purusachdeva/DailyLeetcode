class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Horizontal
        for(auto i : board) {
            unordered_map<char, bool> mp; 
            for(auto j : i) {
                if(j == '.') continue;
                if(mp[j]) return false;
                mp[j] = true;
            }
        }

        // Vertical
        for(int i = 0; i < board.size(); i++) {
            unordered_map<char, bool> mp;
            for(int j = 0; j < board.size(); j++) {
                if(board[j][i] == '.') continue;
                if(mp[board[j][i]]) return false;
                mp[board[j][i]] = true;    
            }
        }

        // Box
        vector<pair<int, int>> startPoints;

        for(int i = 0; i < board.size(); i+=3) {
            for(int j = 0; j < board.size(); j+=3) {
                unordered_map<char, int> mp;
                for(int a = 0; a < 3; a++) {
                    for(int b = 0; b < 3; b++) {
                        if(board[i + a][j + b] == '.') continue;
                        if(mp[board[i + a][j + b]]) return false;
                        mp[board[i + a][j + b]] = true;
                    }
                }
            }
        }

        return true;
    }
};