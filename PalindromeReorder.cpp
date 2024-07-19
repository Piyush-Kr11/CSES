#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }
    string ans = "";
    int oddFreq = 0;
    bool flag = true;
    for (auto i : mp)
    {
        if (i.second & 1)
        {
            if (oddFreq != 0)
            {
                cout << "NO SOLUTION";
                flag = false;
                break;
            }
            else
                ans = ans.substr(0, ans.length() / 2) + "" + string(i.second, i.first) + "" + ans.substr(ans.length() / 2), oddFreq = 1;
        }
        else
        {
            char ch = i.first;
            int count = i.second;
            ans = string(count / 2, ch) + "" + ans + "" +string(count / 2, ch);
        }
    }
    if(flag)
    cout<<ans;
}