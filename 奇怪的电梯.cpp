#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool is_valid(int cur, int N) {
    if(cur < 1 || cur > N) {
        return false;
    } else {
        return true;
    }
}

// int Dfs(vector<int> &K, vector<int> &visited, int cur, int B, int N, int step) {
//     visited[cur-1] = 1;
//     if(cur == B) {
//         return step;
//     }
//     if(is_valid(cur - K[cur-1], N) && !visited[cur - K[cur-1] - 1]) {
//         return Dfs(K, visited, cur - K[cur-1], B, N, step+1);
//     } else if (is_valid(cur + K[cur-1], N) && !visited[cur + K[cur-1] - 1]) {
//         return Dfs(K, visited, cur + K[cur-1], B, N, step+1);
//     } else {
//         return -1;
//     }
// }

struct State {
    int layer, step;
    State(int l, int s) {
        layer = l, step = s;
    }
} ;

int Bfs(vector<int> &K, vector<int> &visited, int A, int B, int N) {
    queue<State> que;
    que.push(State(A, 0));
    visited[A-1] = 1;
    while(!que.empty()) {
        State cur = que.front();
        que.pop();
        if(cur.layer == B)
            return cur.step;
        if(is_valid(cur.layer-K[cur.layer-1], N) && !visited[cur.layer-K[cur.layer-1]-1]) {
            que.push(State(cur.layer-K[cur.layer-1], cur.step+1));
            visited[cur.layer-K[cur.layer-1]-1] = 1;
        } 
        if(is_valid(cur.layer+K[cur.layer-1], N) && !visited[cur.layer+K[cur.layer-1]-1]) {
            que.push(State(cur.layer+K[cur.layer-1], cur.step+1));
            visited[cur.layer+K[cur.layer-1]-1] = 1;
        } 
    }
    return -1;
}

int main() {
    // freopen("./input", "r", stdin);
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> K;
    vector<int> visited(N, 0);
    int tmp;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        K.push_back(tmp);
    }

    cout << Bfs(K, visited, A, B, N) << endl;

    return 0;
}