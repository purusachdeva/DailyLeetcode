class Solution {
    vector<string> map1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> map2 = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> map3 = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string ans = "";

        vector<string> v;
        int loop1 = 0;
        string temp = "";

        while (num) {
            temp = "";

            int ones = num % 10;
            int tens = num % 100;
            tens /= 10;
            int hundreds = num % 1000;
            hundreds /= 100;

            if (hundreds)
                temp += map1[hundreds] + " Hundred";

            if (tens == 1) {
                if (hundreds) temp += " ";
                temp += map3[ones];
            }

            else {
                if (tens) {
                    if (hundreds) temp += " ";
                    temp += map2[tens];
                    if (ones) temp += " " + map1[ones];
                }
                else if (ones) {
                    if (hundreds) temp += " ";
                    temp += map1[ones];
                }
            }

            if (temp != "") {
                if (loop1 > 0) {
                    if (loop1 % 3 == 0) temp += " Billion";
                    else if (loop1 % 2 == 0) temp += " Million";
                    else if (loop1 % 1 == 0) temp += " Thousand";
                }
            }

            loop1++;
            v.push_back(temp);
            num /= 1000;
        }

        for (int i = v.size() - 1; i >= 0; i--) {
            ans += v[i];
            if (ans[ans.size() - 1] != ' ') ans += " ";
        }

        int extra = 0;
        for (int i = ans.size() - 1; i >= 0; i--) {
            if (ans[i] == ' ') extra++;
            else break;
        }


        return ans.substr(0, ans.size() - extra);
    }
};