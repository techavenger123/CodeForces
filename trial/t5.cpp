//
// Created by MIHIR MITHANI on 22/09/25.
//
#include <stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;

int findcloset(const vi &dist, const vb &fin) {
    int closest = -1, minele = INT_MAX;
    for (int i = 1; i < (int)dist.size(); i++) { // nodes are 1..n
        if (!fin[i] && dist[i] < minele) {
            closest = i;
            minele = dist[i];
        }
    }
    return closest;
}

void dij(unordered_map<int,unordered_map<int,int>> &mp, int src, vb &fin, vi &dist, vi &parent) {
    int n = dist.size() - 1;  // since we use 1..n indexing
    dist[src] = 0;
    parent[src] = -1; // source has no parent

    for (int i = 1; i <= n; i++) {
        int u = findcloset(dist, fin);
        if (u == -1) break; // no more reachable nodes
        fin[u] = true;

        for (auto &p : mp[u]) {
            int v = p.first;
            int w = p.second;
            if (!fin[v] && dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;   // track predecessor
            }
        }
    }

    cout << "Vertex : Distance from source\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        if (dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    cout << "\nShortest Paths from source " << src << ":\n";
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            cout << i << " : no path\n";
            continue;
        }
        vector<int> path;
        for (int v = i; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        cout << i << " : ";
        for (int v : path) cout << v << " ";
        cout << "\n";
    }
}

int main() {
    unordered_map<int,unordered_map<int,int>> mp;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        mp[a][b] = c;
        mp[b][a] = c;
    }
    vb fin(n+1, false);       // 1-based indexing
    vi dist(n+1, INT_MAX);
    vi parent(n+1, -1);
    dij(mp, 1, fin, dist, parent);    // source = 1
    return 0;
}
