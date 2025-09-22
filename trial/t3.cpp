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

void dij(unordered_map<int,unordered_map<int,int>> &mp, int src, vb &fin, vi &dist) {
    int n = dist.size() - 1;
    dist[src] = 0;
    for (int i = 1; i <= n; i++) {
        int closet = findcloset(dist, fin);
        if (closet == -1) break; // no more reachable nodes
        fin[closet] = true;

        for (auto &p : mp[closet]) {
            int nei = p.first;
            int weight = p.second;
            if (!fin[nei] && dist[closet] != INT_MAX && dist[closet] + weight < dist[nei]) {
                dist[nei] = dist[closet] + weight;
                // don't mark fin[nei] here!
            }
        }
    }

    cout << "Vertex : Distance from source\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        if (dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
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
    dij(mp, 1, fin, dist);    // source = 1
    return 0;
}

/*
Input:
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
*/