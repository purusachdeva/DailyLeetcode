class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;

        for(int i = 0; i < s.length(); i++) {
            if(map1.count(s[i]) == 0 && map2.count(t[i]) == 0) {
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            }

            else if (map1[s[i]] == t[i]) continue;

            else return false;
        }

        return true;
    }
};