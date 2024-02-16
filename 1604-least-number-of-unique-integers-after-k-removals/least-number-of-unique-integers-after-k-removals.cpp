bool comparator(const pair<int,int> &one, 
                    const pair<int, int> &two) 
    {
        return one.second < two.second;
    }

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        map<int, int> mp;
        for(auto i : arr) {
            mp[i]++;
        }

        vector<pair<int, int>> vec;

        for(auto p : mp) {
            vec.push_back(p);
        }

        sort(vec.begin(), vec.end(), comparator);

        int count = 0;
        int unique = mp.size();
        for(auto p : vec) {
            while(mp[p.first] > 0) {
                if(count == k)
                    break;

                mp[p.first]--;
                count++;

                if(mp[p.first] == 0)
                    unique--;
            }
        }

        return unique;
    }
};