//
// Created by MIHIR MITHANI on 22/09/25.
//
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <set>

using namespace std;



int main() {
    int v,e;
    cin>>v>>e;
    cout<<endl;
    unordered_map<int,list<pair<int,int>>> graph;
    for(int i=0;i<e;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    vector<int> dist(v+1);
    for(int i=1;i<=v;i++) {
        dist[i]=INT_MAX;
    }
    set<pair<int,int>> st;
    dist[0]=1;
    st.insert(make_pair(0,1));
    while(st.size()!=0) {
        auto top=*(st.begin());
        int nodedist=top.first;
        int topnode=top.second;
        st.erase(top);
        for (pair<int,int> neigh:graph[topnode]) {
            if (nodedist+neigh.second < dist[neigh.first]) {
                auto record=st.find(make_pair(dist[neigh.first],neigh.first));
                if (record!=st.end()) {
                    st.erase(record);
                    dist[neigh.first]=nodedist+neigh.second;
                    st.insert(make_pair(dist[neigh.first],neigh.first));
                }
            }
        }
    }
    for (int i:dist) {
        cout<<i<<" ";
    }
}