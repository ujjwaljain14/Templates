#include <bits/stdc++.h>
using namespace std;

#define ll long long int;

void djikstra(int source, int n, vector<vector<pair<int,ll>>>&edges, vector<ll> &dis){
    dis[source]=0;
    //prioirity queue to navigate to the next smallest node format => pair<distance,node>
    priority_queue<pair<ll,int>,vector<pair<int,ll>>,greater<pair<int,ll>>> pq;
    pq.push({dis[source],source});
    while(!pq.empty()){
        pair<ll,int> curr = pq.top();
        pq.pop();
        if(dis[curr.second]!= curr.first)continue;
        for(auto edge: adj[curr.second]){
            if(dis[edge.first] > curr.first + edge.second){
                dis[edge.first] = curr.first + edge.second;
                pq.push({dis[edge.first],edge.first});
            }
        }
    }

}
