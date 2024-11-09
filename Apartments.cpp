#include <bits/stdc++.h>
using namespace std;
bool down(vector<pair<int,int>>&ar,int i,int k){
    
}
bool up(vector<pair<int,int>>&ar,int i,int k){
    
}
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>applicants(n);
    vector<pair<int,int>>apartments(m);
    for(int i=0;i<n;i++)cin>>applicants[i];
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        apartments[i] = {x,0};
    }

    sort(apartments.begin(),apartments.end());
    int count = 0;
    for(auto i:applicants) {
        if(up(apartments,i,k)|| down(apartments,i,k))
        count++;
    }
    cout<<count;
}
// 10 10 1000000000
// 25 80 59 43 67 21 77 5 8 99
// 66 41 62 24 88 55 1 53 50 60