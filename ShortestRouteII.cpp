#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void FloydWarshall(ll n,vector<vector<ll>> &mat){
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if(mat[i][k] != LLONG_MAX && mat[k][j] != LLONG_MAX)
                mat[i][j] = min(mat[i][j],mat[i][k] + mat[k][j]);
            }
        }
    }
}
 
int main(){
    ll n,m,q,a,b,c;
    cin>>n>>m>>q;
    vector<vector<ll>> mat(n+1,vector<ll>(n+1,LLONG_MAX));
    for(ll i=0;i<m;i++){
        cin>>a>>b>>c;
        mat[a][b] = min(mat[a][b],c);
        mat[b][a] = mat[a][b];
    }
    for(ll i=1;i<=n;i++) mat[i][i] = 0;
    FloydWarshall(n,mat);
    while(q--){
        cin>>a>>b;
        if(mat[a][b] == LLONG_MAX) cout<<-1<<endl;
        else
        cout<<mat[a][b]<<endl;
    }
}