class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        auto isValidAfterRemoving = [&](int skip) -> bool {
            vector<int> indeg(n + 1, 0);
            vector<vector<int>> graph(n + 1);

            for (int i = 0; i < n; ++i) {
                if (i == skip) continue;

                int u = edges[i][0];
                int v = edges[i][1];

                graph[u].push_back(v);
                indeg[v]++;
            }

            int root = -1;
            int rootCount = 0;

            for (int node = 1; node <= n; ++node) {
                if (indeg[node] == 0) {
                    root = node;
                    rootCount++;
                } else if (indeg[node] != 1) {
                    return false;
                }
            }

            if (rootCount != 1) return false;

            vector<int> visited(n + 1, 0);
            queue<int> q;

            q.push(root);
            visited[root] = 1;

            int count = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                count++;

                for (int nei : graph[node]) {
                    if (!visited[nei]) {
                        visited[nei] = 1;
                        q.push(nei);
                    }
                }
            }

            return count == n;
        };

        for (int i = n - 1; i >= 0; --i) {
            if (isValidAfterRemoving(i)) {
                return edges[i];
            }
        }

        return {};
    }
};