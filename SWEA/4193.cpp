#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adj;
vector<vector<bool>> visited;

// 하 상 우 좌 (y, x)
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int N;
int startX, startY, endX, endY;

struct Node {
    int x;
    int y;
    int time;
};

int bfs(int startX, int startY) {
    queue<Node> q;
    
    visited[startY][startX] = true;
    q.push({startX, startY, 0});

    while(!q.empty()){
        Node curr = q.front();
        q.pop();


        if (curr.x == endX && curr.y == endY) {
            return curr.time;
        }

        bool need_wait = false;

        for (int i = 0; i < 4; i++){
            int nx = curr.x + dc[i];
            int ny = curr.y + dr[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (adj[ny][nx] == 1) continue;
            

            if (visited[ny][nx]) continue;

            // 1. 일반 바다(0)인 경우 -> 바로 이동
            if (adj[ny][nx] == 0) {
                visited[ny][nx] = true;
                q.push({nx, ny, curr.time + 1});
            }
            else if (adj[ny][nx] == 2) {
                if (curr.time % 3 == 2) {
                    visited[ny][nx] = true;
                    q.push({nx, ny, curr.time + 1});
                } else {
                    need_wait = true;
                }
            }
        }
        
        if (need_wait) {
            q.push({curr.x, curr.y, curr.time + 1});
        }
    }
    return -1;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    int T;
    
    cin >> T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;

        adj.assign(N, vector<int>(N, 0));
        visited.assign(N, vector<bool>(N, false));

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                cin >> adj[i][j];
            }
        }
        
        cin >> startY >> startX >> endY >> endX;
        
        int ans = bfs(startX, startY);

        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;
}