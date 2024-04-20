class Solution {
    void explore(vector<vector<int>>& land, int i, int j, int* x, int* y) {
        if(i < 0 || i >= land.size() || j < 0 || j >= land[0].size()) {
            return;
        }

        int a = i, b = j;
        while(a < land.size() && land[a][j]) a++;
        while(b < land[0].size() && land[i][b]) b++;

        *x = a-1;
        *y = b-1;

        for(int p = i; p <= a - 1; p++) {
            for(int q = j; q <= b - 1; q++) {
                land[p][q] = 0;
            }
        }
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;

        int x, y;
        for(int i = 0; i < land.size(); i++) {
            for(int j = 0; j < land[0].size(); j++) {
                if(land[i][j] == 1) {
                    explore(land, i, j, &x, &y);
                    vector<int> a;
                    a.push_back(i);
                    a.push_back(j);
                    a.push_back(x);
                    a.push_back(y);

                    ans.push_back(a);
                }
            }
        }

        return ans;
    }
};