#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void dijkstra(vector<pair<ll,ll>> adj[],ll n){
    vector<ll> dist(n+1,LLONG_MAX);
    dist[1] = 0;
    set<pair<ll,ll>> s;
    s.insert({0,1});
    while(!s.empty()){
        ll d = s.begin()->first;
        ll u = s.begin()->second;
        s.erase(s.begin());
        for(auto x:adj[u]){

            if(dist[x.first] > d + x.second){
                if(dist[x.first] != LLONG_MAX) 
                s.erase({dist[x.first], x.first}); 
                dist[x.first] = d + x.second;
                s.insert({dist[x.first],x.first});
            }
        }
    }
    for(ll i=1;i<=n;i++) cout<<dist[i]<<" ";
}
 
int main(){
    ll n,m,a,b,c;
    cin>>n>>m;
    vector<pair<ll,ll>> adj[n+1];
    for(ll i=0;i<m;i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    dijkstra(adj,n);
}