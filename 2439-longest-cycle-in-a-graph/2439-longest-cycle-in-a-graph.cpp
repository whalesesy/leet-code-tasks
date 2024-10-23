class Solution {
public:
    int longestCycle(vector<int>& edges) {
         int n = edges.size();
        vector<int> inDegree(n, 0);

        // Step 1: Compute in-degrees
        for (int i = 0; i < n; ++i) {
            if (edges[i] != -1) {
                inDegree[edges[i]]++;
            }
        }

        // Step 2: Kahn's Algorithm to remove acyclic nodes
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Remove nodes with in-degree zero iteratively
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            int v = edges[u];
            if (v != -1) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Step 3 and 4: Find cycles and compute their lengths
        vector<bool> visited(n, false);
        int ans = -1;

        for (int i = 0; i < n; ++i) {
            if (inDegree[i] > 0 && !visited[i]) {
                int current = i;
                int cycleLength = 0;
                while (!visited[current]) {
                    visited[current] = true;
                    current = edges[current];
                    cycleLength++;
                }
                ans = max(ans, cycleLength);
            }
        }
        return ans;
      
    }
};