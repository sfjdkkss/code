#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

vector<vector<int>> ans;
vector<vector<int>> visited;
const vector<int> dx = {2, 2,-2,-2, 1,-1, 1,-1};
const vector<int> dy = {1,-1, 1,-1, 2, 2,-2,-2};

struct Pos {
    int x, y, step;
    Pos(int tx, int ty, int tstep) {
        x = tx, y = ty, step = tstep;
    }
} ;

bool is_valid_pos(int x, int y, int n, int m) {
    if(x < 0 || x >= n || y < 0 ||y >= m)
        return false;
    else
        return true;
}

void bfs(int x, int y, int n, int m) {
    queue<Pos> que;
    que.push(Pos(x, y, 0));
    ans[x][y] = 0;
    visited[x][y] = 1;
    while(!que.empty()) {
        Pos cur = que.front();
        que.pop();
        for(int i = 0; i < dx.size(); i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nstep = cur.step + 1;
            if(is_valid_pos(nx, ny, n, m) && !visited[nx][ny]) {
                que.push(Pos(nx, ny, nstep));
                ans[nx][ny] = nstep;
                visited[nx][ny] = 1;
            }
        }
    }
}

int main() {
    // freopen("./input", "r", stdin);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    ans = vector<vector<int> >(n, vector<int>(m));
    visited = vector<vector<int> >(n, vector<int>(m));
    for(int i = 0; i < ans.size(); i++) 
        for(int j = 0; j < ans[0].size(); j++) 
            ans[i][j] = -1, visited[i][j] = 0;

    bfs(x-1, y-1, n, m);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[0].size(); j++) {
            printf("%-5d", ans[i][j]);
        }
        cout << endl;
    }

    return 0;
}