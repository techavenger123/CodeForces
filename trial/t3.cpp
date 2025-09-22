//
// Created by MIHIR MITHANI on 22/09/25.
//
#include <stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;

int findcloset(vi &dist, vb &fin) {
    int closest = -1, minele = INT_MAX;
    cout<<"Entered : "<<endl;
    for (int i = 0; i < dist.size(); i++) {
        cout<<"Entered loop : "<<endl;
        if (!fin[i] && dist[i] < minele) {
            closest = i;
            minele = dist[i];
        }
    }
    return closest;
}

void dij(unordered_map<int,unordered_map<int,int>> &mp, int src,vb &fin,vi &dist) {
    int n=dist.size();
    dist[src] = 0;
    for (int i = 0; i < n; i++) {
        int closet = findcloset(dist, fin);
        fin[closet] = true;
        for (pair<int,int> p : mp[closet]) {
            int nei = p.first;
            int weight = p.second;
            if (!fin[nei] && dist[closet] != INT_MAX && dist[closet] + weight < dist[nei]) {
                dist[nei] = dist[closet] + weight;
                fin[nei] = true;
            }
        }
    }

    cout << "Distances:\n";
    for (int i = 0; i < n; i++) {
        cout<<i<<" ";
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
    vb fin(n+1, false);
    vi dist(n+1, INT_MAX);
    dij(mp, 1,fin,dist);
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
