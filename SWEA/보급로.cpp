#include<iostream>
#include<queue>
#include <vector>
#include <string>
using namespace std;


vector<vector<int>> v;
vector<vector<int>> dist;

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};
int N;
struct Node {
  int r;
  int c;
  int weight;

  bool operator < (const Node& n) const{
    return this->weight > n.weight;
  }
};

void dijkstra(){
  priority_queue<Node> pq;
  pq.push({0,0});
  dist[0][0] = 0;

  while(!pq.empty()){
    int cr = pq.top().r;
    int cc = pq.top().c;
    int cd = pq.top().weight;

    pq.pop();

    if (dist[cr][cc] < cd ) continue;

    for (int i =0 ; i<4; i++){
      int nr = cr+ dr[i];
      int nc = cc+ dc[i];

      if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
      
      int nd = cd + v[nr][nc];

      if (dist[nr][nc] > nd){
        dist[nr][nc] = nd;
        pq.push({nr,nc,nd});
      }
    }

  }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> N;

    v.assign(N+1,vector<int>(N+1,0));

    for (int i = 0 ; i< N; i++){
      string s; cin >> s;
      for (int j =0; j<s.size(); j++){
        v[i][j] = s[j]-'0';
      }
    }
    dist.assign(N+1,vector<int>(N+1,1e9));
    dijkstra();

    cout << "#"<< test_case << " " << dist[N-1][N-1] << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}