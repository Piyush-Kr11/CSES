#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void dfs(vector<vector<char>>&v,vector<vector<bool>>&visited,ll i,ll j){
    if(i<0 || j<0 || i>=v.size() || j>=v[0].size() || visited[i][j] || v[i][j]=='#') return;
    visited[i][j] = true;
    dfs(v,visited,i+1,j);
    dfs(v,visited,i-1,j);
    dfs(v,visited,i,j+1);
    dfs(v,visited,i,j-1);
}
    
int main(){
    ll h,w;
    cin>>h>>w;
    vector<vector<char>>v(h,vector<char>(w));
	for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)
        cin>>v[i][j];
    }
    vector<vector<bool>>visited(h,vector<bool>(w,false));
    ll rooms = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(v[i][j]=='.' && !visited[i][j]) rooms++,dfs(v,visited,i,j);
        }
    }	
    cout<<rooms;
}