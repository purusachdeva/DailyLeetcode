

class Solution {
public:
     static bool comp(vector<int> &a, vector<int> &b)
     {
          if (a[0] == b[0])
          {
               return a[1] > b[1];
          }
          return a[0] < b[0];
     }
     
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int weaklings = 0;

        sort(properties.begin(), properties.end(), comp);

        int maxDefense = INT_MIN;

        for(int i = properties.size() - 1; i >= 0; i--) {
            if(properties[i][1] < maxDefense) {
                weaklings++;
            }

            maxDefense = max(maxDefense, properties[i][1]);
        }

        return weaklings;
    }
};