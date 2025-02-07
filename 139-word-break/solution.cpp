class Solution {
  public:
      bool findSegment(string s, vector<string>& wordDict, int start, vector<int>& dp) {
          if (start == s.size()) return true;
  
          if (dp[start] != -1) {
              if (dp[start] == 0) return false;
              else return true;
          }
  
          for (const string& word : wordDict) {
              int wordLen = word.size();
              if (start + wordLen <= s.size() && s.substr(start, wordLen) == word) {
                  if (findSegment(s, wordDict, start + wordLen, dp)) {
                      dp[start] = 1;
                      return true;
                  }
              }
          }
  
          dp[start] = 0;
          return false;
      }
  
      bool wordBreak(string s, vector<string>& wordDict) {
          int n = s.size();
          vector<int> dp(n + 1, -1);
          return findSegment(s, wordDict, 0, dp);
      }
  };