//
// Created by MIHIR MITHANI on 22/09/25.
//
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<list<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1, 0);
    set<pair<int, int>> pq;

    dist[1] = 0;
    pq.insert({0, 1});

    while (!pq.empty()) {
        int current_dist = pq.begin()->first;
        int u = pq.begin()->second;
        pq.erase(pq.begin());
        if (current_dist > dist[u]) {
            continue;
        }
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                if (dist[v] != INT_MAX) {
                    pq.erase({dist[v], v});
                }
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.insert({dist[v], v});
            }
        }
    }

    if (dist[n] == INT_MAX) {
        cout << -1 << endl;
    } else {
        vector<int> path;
        int current_node = n;
        while (current_node != 0) {
            path.push_back(current_node);
            current_node = parent[current_node];
        }
        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}