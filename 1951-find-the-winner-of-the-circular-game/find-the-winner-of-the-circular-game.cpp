class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n == 1) return 1;
        int i = 0;

        vector<int> vec(n);
        iota(vec.begin(), vec.end(), 1);

        int lost = 0;
        while(1) {
            // cout << "before count: " << i + 1 << endl;
            i = i % n;
            int count = 1;
            while(count < k) {
                if(vec[i] == -1) {
                    i++;
                    i = i % n;
                    continue;
                } else {
                    count++;
                    i++;
                    i = i % n;
                }
            }

            while(vec[i] == -1) {
                i++;
                i = i%n;
            }

            // cout << "after count: " << i + 1 << endl;

            // cout << "OUT: " << vec[i] << endl;
            vec[i] = -1;
            lost++;

            // cout << "Starting from: " << i + 1 << endl;


            // for(auto num : vec) {
            //     cout << num << " ";
            // }
            // cout << "\n\n";

            if(lost == n-1) break;


        }

        for(auto num : vec) {
            // cout << num << " ";
            if(num != -1) return num;
        }

        return -1;
    }
};