#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void floydWarshall(int n, vector<vector<ll>> &cost, vector<vector<ll>> adj){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }   
    }
}

void sol(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> cost(n+1,vector<ll>(n+1,LONG_LONG_MAX));
    vector<vector<ll>> adj(n+1);
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cost[a][b]=min(c,cost[a][b]);
        cost[b][a]=min(c,cost[b][a]);
    }
    for(int i=1;i<=n;i++)cost[i][i]=0;
    floydWarshall(n,cost,adj);

}

int main(){
    sol();
    return 0;
}
