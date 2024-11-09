#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int count = 1;
    set<int>s;
    s.insert(a[0]);
    for(int i=1;i<n;i++){
        bool inserted = false;
        for(auto j:s){
            if(a[i]<j){
                s.erase(j);
                s.insert(a[i]);
                inserted = true;
                break;
            }
        }
        if(!inserted)s.insert(a[i]),count++;
    }
    cout<<count;
}