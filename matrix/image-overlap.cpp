class Solution{
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2){
        int n = img1.size();
        vector<pair<int, int>> v1, v2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1) v1.push_back({i, j});
                if(img2[i][j] == 1) v2.push_back({i, j});
            }
        }
        
        int count[67][67] = {0};
        int ans = 0;
        for(auto& p1 : v1){
            for(auto& p2 : v2){
                int dr = p2.first-p1.first+30;
                int dc = p2.second-p1.second+30;
                count[dr][dc]++;
                ans = max(ans, count[dr][dc]);
            }
        }

        return ans;
    }
};