class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto &it : times) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(n+1,1e9);
        vector<bool>vis(n+1,false);
        dis[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [wt,node]=pq.top();
            pq.pop();
            if(vis[node]) continue;
            vis[node]=true;
            for(auto it:adj[node]){
                int adjn=it.first;
                int edw=it.second;
                if(wt+edw<dis[adjn]){
                    dis[adjn]=wt+edw;
                    pq.push({dis[adjn],adjn});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dis[i]==1e9) return -1;
            ans=max(ans,dis[i]);
        }
        return ans;
    }
};