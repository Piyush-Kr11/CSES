#include <bits/stdc++.h>
using namespace std;
vector<int> connected_components;
void dfs(int i,vector<int>adj[],vector<bool>&visited){
    visited[i] = true;
    for(auto x:adj[i]){
        if(!visited[x]){
            dfs(x,adj,visited);
        }
    }
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
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            connected_components.push_back(i);
            dfs(i,adj,visited);
        }
    }
    cout<<connected_components.size() - 1<<"\n";
    for(int i=1;i<connected_components.size();i++){
        cout<<connected_components[i-1]<<" "<<connected_components[i]<<"\n";
    }
    return 0;
}