//
// Created by MIHIR MITHANI on 22/09/25.
//
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <climits> // For INT_MAX
#include <unordered_map>

using namespace std;

int main() {
    int v, e;
    cin >> v >> e;

    unordered_map<int, list<pair<int, int>>> graph;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    // A vector to store the minimum distance from the source node to all other nodes
    vector<int> dist(v + 1, INT_MAX);

    // A set to act as a min-priority queue. It stores pairs of {distance, node}.
    // The set automatically keeps elements sorted by distance.
    set<pair<int, int>> st;

    // Let's assume the source node is 1. You can take this as input if needed.
    int source_node = 1;
    dist[source_node] = 0;
    st.insert({0, source_node});

    while (!st.empty()) {
        // Get the node with the smallest distance from the set
        auto top = *(st.begin());
        int current_dist = top.first;
        int current_node = top.second;

        // Remove the top element from the set
        st.erase(st.begin());

        // Check for all neighbors of the current_node
        for (auto neighbor_pair : graph[current_node]) {
            int neighbor_node = neighbor_pair.first;
            int weight = neighbor_pair.second;

            // If a shorter path is found to the neighbor
            if (current_dist + weight < dist[neighbor_node]) {
                // If the neighbor is already in the set, remove its old entry
                // before inserting the new one with the shorter distance.
                // This is the core logic of Dijkstra's with a set.
                if (dist[neighbor_node] != INT_MAX) {
                    st.erase({dist[neighbor_node], neighbor_node});
                }

                // Update the distance and insert the new entry into the set
                dist[neighbor_node] = current_dist + weight;
                st.insert({dist[neighbor_node], neighbor_node});
            }
        }
    }

    // Print the distances to all nodes from the source
    cout << "\nShortest distances from source node " << source_node << ":" << endl;
    for (int i = 1; i <= v; i++) {
        cout << "Node " << i << ": " << dist[i] << endl;
    }

    return 0;
}