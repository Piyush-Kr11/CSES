#include <bits/stdc++.h>
using namespace std;
vector<string> solve(string s,int ind,set<string>&unique){
    if(ind==s.length()-1){
        vector<string>ans;
        string temp = string(1,s[ind]);
        ans.push_back(temp);
        unique.insert(temp);
        return ans;
    }

    vector<string> small = solve(s,ind+1,unique);
    int noOfStrings = small.size();
    int sizeOfStrings = small[0].size();
    vector<string>finalAns;
    for(int i=0;i<noOfStrings;i++){
        for(int j=0;j<=sizeOfStrings;j++){
            string temp = small[i].substr(0,j) + string(1,s[ind]) + small[i].substr(j);
            if(unique.find(temp) == unique.end())
            finalAns.push_back(temp), unique.insert(temp);
        }
    }
    return finalAns;
}
int main() {
    string s;
    cin>>s;
    set<string>unique;
    vector<string>ans = solve(s,0,unique);
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(auto i:ans)
    cout<<i<<endl;
}