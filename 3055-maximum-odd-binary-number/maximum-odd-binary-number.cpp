class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count0 = 0, count1 = 0;
        for(auto i : s) {
            if(i == '0') count0++;
            else count1++;
        }
        
        s[s.size()-1] = '1';
        count1--;

        int i = 0;
        while(count1 > 0) {
            s[i] = '1';
            count1--;
            i++;
        }

        while(count0 > 0) {
            s[i] = '0';
            count0--;
            i++;
        }

        return s;
    }
};