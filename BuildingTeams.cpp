#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[],vector<int> &vis,vector<int> &p,int i,int cnt = 1){
    vis[i] = 1;
    for(auto x:adj[i]){
        if(vis[x] == -1){
            p[x] = i;
            dfs(adj,vis,p,x,cnt+1); 
        }
        else if(p[i] != x){
            if(cnt >= 3){
                int j = i;
                cout<< x << " " <<j<< " ";
                while(j != x && j != -1){
                    cout<<p[j]<<" ";
                    j = p[j];
                }
                cout<<"\n";
                return true;
            }
        }
    }
    return false;
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
    vector<int>vis(n+1,-1);
    vector<int>parent(n+1,-1);
    for(int i=1;i<=n;i++){
        if(vis[i] == -1)
            if(dfs(adj,vis,parent,i)) return 0;
    }
}