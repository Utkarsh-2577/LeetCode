class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n, vector<int>());
        for(auto &p : invocations){
            adj[p[0]].push_back(p[1]);
        }

        vector<bool> isSus(n, 0);
        queue<int> q;
        q.push(k);
        isSus[k] = 1;

        while(!q.empty()){
            int par = q.front();
            q.pop();

            for(auto &ch : adj[par]){
                if(!isSus[ch]){
                    isSus[ch] = 1;
                    q.push(ch);
                }
            }
        }

        bool can_remove = true;
        for(auto &p : invocations){
            if(!isSus[p[0]] && isSus[p[1]]){
                can_remove = false;
                break;
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!can_remove || !isSus[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};