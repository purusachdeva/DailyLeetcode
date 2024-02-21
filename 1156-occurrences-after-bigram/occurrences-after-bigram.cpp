class Solution {
public:


vector<string> convertToVector(const std::string& text) {
    vector<string> words;
    string word;

    for (char c : text) {
        if (c == ' ') { 
            if (!word.empty()) { 
                words.push_back(word);
                word = "";
            }
        } else {
            word += c;
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}


    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        vector<string> temp = convertToVector(text);

        for(int i = 2; i < temp.size(); i++) {
            if(temp[i-2] == first && temp[i-1] == second) {
                ans.push_back(temp[i]);
            }
        }

        return ans;
    }
};