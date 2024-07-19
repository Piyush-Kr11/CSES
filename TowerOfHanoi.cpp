#include <bits/stdc++.h>
using namespace std;
void solve(int n,vector<pair<int,int>>&moves,int a,int b,int c){
    if(n == 0)return ;
    solve(n-1,moves,a,c,b);
    moves.push_back({a,c});
    solve(n-1,moves,b,a,c);
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>moves;
    solve(n,moves,1,2,3);
    cout<<moves.size()<<endl;
    for(auto i:moves)
    cout<<i.first<<" "<<i.second<<endl;
}