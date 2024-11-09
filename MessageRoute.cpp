#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<int> adj[],vector<int> &parent){
    int n = parent.size() - 1;
    vector<int> dist(n+1,INT_MAX);
    dist[1] = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(1);
    while(!pq.empty()){
        int u = pq.top();
        pq.pop();
        for(auto x:adj[u]){
            if(dist[x] > dist[u] + 1){
                dist[x] = dist[u] + 1;
                parent[x] = u;
                pq.push(x);
            }
        }
    }
    if(dist[n] == INT_MAX){
        cout<<"IMPOSSIBLE";
        return;
    }
    // for(auto x:dist) cout<<x<<" ";
    // cout<<"\n";
    vector<int> path;
    int i = n;
    while(i != -1){
        path.push_back(i);
        i = parent[i];
    }
    reverse(path.begin(),path.end());
    cout<<path.size()<<"\n";
    for(auto x:path) cout<<x<<" ";
}

int main(){
    int n,m,a,b;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> parent(n+1,-1);
    dijkstra(adj,parent);
}