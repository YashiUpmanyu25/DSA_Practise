class disjointset{
    public:
    vector<int>rank,parent;
    disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findpar(int node){
        if(parent[node]==node){
            return node;

        }
        return parent[node]=findpar(parent[node]);
    }
    bool unionr(int u,int v){
        int ul_u=findpar(u);
        int ul_v=findpar(v);
        if(ul_u==ul_v) return false;
        if(rank[ul_u]<rank[ul_v]){
            parent[ul_u]=ul_v;
        }else if(rank[ul_v]<rank[ul_u]){
            parent[ul_v]=ul_u;
        }
        else{
            parent[ul_v]=ul_u;
            rank[ul_u]++;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        disjointset d (edges.size());
        for(auto edge:edges){
            if(!d.unionr(edge[0],edge[1])){
                return {edge[0],edge[1]};
            }
        }
        return {-1,-1};
    }
};