#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, R, C, L;
//상하좌우
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

int opp_pipe[4] = { 1,0,3,2 };

int pipe[8][4]{
    {0,0,0,0},
    {1,1,1,1},
    {1,1,0,0},
    {0,0,1,1},
    {1,0,0,1},
    {0,1,0,1},
    {0,1,1,0},
    {1,0,1,0}
};

vector<vector<int>> v;
vector<vector<bool>> visited;

struct Grid {
    int r;
    int c;
    int time;
};

int bfs(int r, int c) {
    queue<Grid> q;
    q.push({ r,c,1 });
    visited[r][c] = true;

    int total_num = 1;

    while (!q.empty()) {
        int cr = q.front().r;
        int cc = q.front().c;
        int ctime = q.front().time;

        q.pop();

        int grid_num = v[cr][cc];

        if (ctime >= L) break;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            int ntime = ctime + 1;

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (!v[nr][nc]) continue;

            if (!visited[nr][nc] && pipe[grid_num][i] == 1 && pipe[v[nr][nc]][opp_pipe[i]] == 1) {
                visited[nr][nc] = true;
                q.push({ nr, nc, ntime });
                total_num++;
            }
        }

    }
    return total_num;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> M >> R >> C >> L;

        v.assign(N, vector<int>(M, 0));
        visited.assign(N, vector<bool>(M, false));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> v[i][j];
            }
        }

        int ans = bfs(R, C);
        cout << "#" << test_case << " " << ans << "\n";

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
