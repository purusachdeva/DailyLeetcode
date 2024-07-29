class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        vector<int> s1Map(26, 0);
        vector<int> s2Map(26, 0);

        for (char c : s1) s1Map[c - 'a']++;
        
        int windowSize = s1.size();
        
        for (int i = 0; i < windowSize; i++) {
            s2Map[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1Map[i] == s2Map[i]) matches++;
        }

        for (int i = 0, j = windowSize; j < s2.size(); i++, j++) {
            if (matches == 26) return true;

            int leftCharIdx = s2[i] - 'a';
            int rightCharIdx = s2[j] - 'a';

            s2Map[rightCharIdx]++;
            if (s2Map[rightCharIdx] == s1Map[rightCharIdx]) {
                matches++;
            } else if (s2Map[rightCharIdx] == s1Map[rightCharIdx] + 1) {
                matches--;
            }

            s2Map[leftCharIdx]--;
            if (s2Map[leftCharIdx] == s1Map[leftCharIdx]) {
                matches++;
            } else if (s2Map[leftCharIdx] == s1Map[leftCharIdx] - 1) {
                matches--;
            }
        }

        return matches == 26;
    }
};
