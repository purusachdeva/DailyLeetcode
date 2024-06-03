class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_index = 0, t_index = 0;

        while(s_index < s.size() && t_index < t.size()) {
            if(s[s_index] == t[t_index]) {
                t_index++;
            }
            s_index++;
        }

        return t.size() - t_index;
    }
};