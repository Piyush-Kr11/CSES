/* Notes
    - Don't Use direct String path construction as appending to string is O(n) operation and will give TLE
    - Instead use a 2-D array to store the parent and then backtrack from destination to source
 */
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

static vector<vector<char>> v(1000, vector<char>(1000));
static vector<vector<bool>> visited(1000, vector<bool>(1000));
static vector<vector<char>> steps(1000, vector<char>(1000));
static pair<ll, ll> src, dest;
static vector<char> ans;
static const vector<pair<ll,ll>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
static const vector<char> direction_chars = {'D', 'U', 'R', 'L'};
bool valid(ll x, ll y) {
    return (x >= 0 && y >= 0 && x < v.size() && y < v[0].size() && !visited[x][y] && v[x][y] != '#');
}

void backtrack(ll x,ll y){
    if (steps[x][y] != 'X') {
        char ch = steps[x][y];
        ans.push_back(ch);
        if (ch == 'U')
            backtrack(x + 1, y);
        else if (ch == 'D')
            backtrack(x - 1, y);
        else if (ch == 'L')
            backtrack(x, y + 1);
        else if (ch == 'R')
            backtrack(x, y - 1);
    }    
}

bool bfs() {
    queue<pair<ll,ll>> q;  
    q.push(src);
    visited[src.first][src.second] = true;
    bool flag = false;
    steps[src.first][src.second] = 'X';
    while (!q.empty()) {
        pair<ll,ll> cur = q.front();
        q.pop();
        if (cur == dest) {
            flag = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            ll nx = cur.first + directions[i].first;
            ll ny = cur.second + directions[i].second;
            if (valid(nx, ny)) {
                visited[nx][ny] = true;
                steps[nx][ny] = direction_chars[i];
                q.push({nx, ny});
            }
        }
    }
    if(flag){
        backtrack(dest.first,dest.second);
        reverse(ans.begin(), ans.end());
        return true;
    }
    return flag;
}

int main() {
    ll h, w;
    cin >> h >> w;    
    v.resize(h, vector<char>(w));
    visited.resize(h, vector<bool>(w, false));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'A') src = {i, j};
            if (v[i][j] == 'B') dest = {i, j};
        }
    }
    
    if (bfs()) {
        cout << "YES\n" << ans.size() << "\n";
        cout << string(ans.begin(), ans.end()) << "\n";
    } else {
        cout << "NO\n";
    }
}
