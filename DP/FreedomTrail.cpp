class Solution {
public:
    int countSteps(int ringIndex, int i, int n) {
        int dist = abs(i - ringIndex);
        int wrap_around = (n - dist);
        return min(dist, wrap_around);
    }

    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();

        unordered_map<char, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            char ch = ring[i];
            adj[ch].push_back(i);
        }

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {0, 0}});
        set<pair<int, int>> visited;

        int totalSteps;
        while (!pq.empty()) {
            totalSteps = pq.top().first;
            int ri = pq.top().second.first;
            int ki = pq.top().second.second;
            pq.pop();
            char curr = key[ki];

            if (ki == m) {
                break;
            }

            if (visited.count({ri, ki}))
                continue;

            visited.insert({ri, ki});

            for (int j = 0; j < adj[curr].size(); j++) {
                int steps = countSteps(ri, adj[curr][j], n) + totalSteps;
                pq.push({steps, {adj[curr][j], ki + 1}});
            }
        }

        return totalSteps + m;
    }
};