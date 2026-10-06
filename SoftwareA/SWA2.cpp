#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

<<<<<<< HEAD
// 절대 방향: 0(상), 1(우), 2(하), 3(좌)
// 시계 방향 순서로 정의되어 있습니다.
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

// look[d][t] : 현재 로봇이 d 방향을 바라볼 때, t번째 우선순위로 탐색할 절대 방향
// 문제의 탐색 우선순위: 오른쪽(t=0), 앞쪽(t=1), 왼쪽(t=2), 뒤쪽(t=3)
int look[4][4] = {
    {1, 0, 3, 2}, // 현재 '상(0)' 방향 -> 우(1), 상(0), 좌(3), 하(2) 탐색
    {2, 1, 0, 3}, // 현재 '우(1)' 방향 -> 하(2), 우(1), 상(0), 좌(3) 탐색
    {3, 2, 1, 0}, // 현재 '하(2)' 방향 -> 좌(3), 하(2), 우(1), 상(0) 탐색
    {0, 3, 2, 1}  // 현재 '좌(3)' 방향 -> 상(0), 좌(3), 하(2), 우(1) 탐색
};

void solve() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N, M;
        cin >> N >> M;
        
        // 지형 정보 입력 (0: 농지, 1: 산)
        vector<vector<int>> grid(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> grid[i][j];
            }
        }

        int max_harvests = 0;

        // [완전 탐색] 로봇을 놓을 수 있는 모든 시작 위치(sr, sc)와 시작 방향(sd)을 테스트합니다.
        for (int sr = 0; sr < N; ++sr) {
            for (int sc = 0; sc < N; ++sc) {
                // 시작 위치가 산(1)이면 로봇을 놓을 수 없으므로 스킵
                if (grid[sr][sc] == 1) continue; 

                // 4가지 초기 방향에 대해 각각 시뮬레이션 진행
                for (int sd = 0; sd < 4; ++sd) {
                    // 각 칸에 씨를 심은 횟수 (누적될수록 수확까지 오래 걸림)
                    vector<vector<int>> sprout_count(N, vector<int>(N, 0));
                    // 각 칸의 곡식이 수확 가능해지는 날짜 (0이면 빈 땅을 의미)
                    vector<vector<int>> ready_day(N, vector<int>(N, 0));

                    int harvests = 0; // 현재 케이스의 누적 수확 횟수
                    int r = sr, c = sc, d = sd; // 로봇의 현재 위치와 방향

                    // M일 동안의 시뮬레이션 시작
                    for (int day = 1; day <= M; ++day) {
                        
                        // ------------------------------------
                        // [1] 오전 작업: 수확 또는 파종(씨 심기)
                        // ------------------------------------
                        
                        // 조건 A: 현재 땅에 작물이 자랐고, 오늘 날짜가 수확 가능한 날짜 이후라면 수확
                        if (ready_day[r][c] > 0 && day >= ready_day[r][c]) {
                            harvests++;          // 수확 횟수 증가
                            ready_day[r][c] = 0; // 수확 후 다시 빈 농지로 초기화
                        } 
                        // 조건 B: 현재 땅이 빈 땅이라면 씨를 심을지 고민
                        else if (ready_day[r][c] == 0) {
                            
                            bool can_move = false;
                            
                            // "오후에 이동할 곳이 있을 때만 씨를 심는다"는 조건 때문에
                            // 2차원 look 배열을 이용해 미리 4방향을 훑어봅니다.
                            for (int t = 0; t < 4; ++t) {
                                int nd = look[d][t]; // 모듈러 연산 없이 look 배열에서 바로 방향 추출
                                int nr = r + dr[nd];
                                int nc = c + dc[nd];
                                
                                // 지도 밖을 벗어나지 않고, 산(1)이 아니라면 진입 시도 가능
                                if (nr >= 0 && nr < N && nc >= 0 && nc < N && grid[nr][nc] != 1) {
                                    // 진입하려는 곳이 빈 땅이거나, 이미 작물이 다 자란 땅이라면 이동 가능
                                    if (ready_day[nr][nc] == 0 || day >= ready_day[nr][nc]) {
                                        can_move = true;
                                        break; 
                                    }
                                }
                            }
                            
                            // 이동할 수 있는 땅을 확인했다면 현재 위치에 씨를 심습니다.
                            if (can_move) {
                                sprout_count[r][c]++; // 파종 횟수 증가
                                // 수확 가능 날짜 = 현재 날짜 + 싹 트는 데 1일 + 자라는 데 (3 + K)일
                                // 즉, day + K + 4 가 됩니다.
                                ready_day[r][c] = day + sprout_count[r][c] + 4;
                            }
                        }

                        // ------------------------------------
                        // [2] 오후 작업: 방향 전환 및 이동
                        // ------------------------------------
                        
                        // 로봇이 현재 방향(d)을 기준으로 우선순위(우, 앞, 좌, 뒤)에 따라 이동을 시도합니다.
                        for (int t = 0; t < 4; ++t) {
                            int nd = look[d][t]; // 이동 시에도 직관적인 look 배열 사용
                            int nr = r + dr[nd];
                            int nc = c + dc[nd];
                            
                            if (nr >= 0 && nr < N && nc >= 0 && nc < N && grid[nr][nc] != 1) {
                                // 빈 땅이거나 수확 가능한 땅이라면 바로 해당 칸으로 이동
                                if (ready_day[nr][nc] == 0 || day >= ready_day[nr][nc]) {
                                    r = nr;
                                    c = nc;
                                    d = nd; // 로봇의 방향도 이동한 방향으로 갱신
                                    break;  // 한 칸만 이동하므로 즉시 오후 작업 종료
                                }
                            }
                        }
                    }

                    // M일이 끝난 후, 이번 케이스의 수확량이 최대인지 확인 후 갱신
                    if (harvests > max_harvests) {
                        max_harvests = harvests;
                    }
                }
            }
        }
        // 형식에 맞춰 정답 출력
        cout << "#" << tc << " " << max_harvests << "\n";
    }
}

int main() {
    // 입출력 속도 향상을 위한 구문 (코딩테스트 필수)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}