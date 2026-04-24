#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);

        for (auto &edge : edges) {
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<vector<int>> timeTaken(n + 1, vector<int>(2, INT_MAX));
        
        queue<vector<int>> q;
        timeTaken[1][0] = 0;
        q.push({1, 0});

        while (!q.empty()) {
            auto element = q.front();
            q.pop();

            int node = element[0];
            int curTime = element[1];

            if (node == n && timeTaken[node][1] != INT_MAX) {
                return timeTaken[node][1];
            }

            // Traffic signal handling
            if ((curTime / change) % 2 != 0) {
                int waitTime = change - (curTime % change);
                curTime += waitTime;
            }
            curTime += time;

            for (int neighbour : adj[node]) {
                if (timeTaken[neighbour][0] == INT_MAX) {
                    timeTaken[neighbour][0] = curTime;
                    q.push({neighbour, curTime});
                }
                else if (timeTaken[neighbour][1] == INT_MAX && curTime > timeTaken[neighbour][0]) {
                    timeTaken[neighbour][1] = curTime;
                    q.push({neighbour, curTime});
                }
            }
        }

        return -1;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int time, change;
    cin >> time >> change;

    Solution sol;
    cout << sol.secondMinimum(n, edges, time, change);

    return 0;
}