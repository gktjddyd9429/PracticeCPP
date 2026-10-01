
#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct Node{
 int node[2];
 
 Node (int s1, int s2){
  this-> node[0] = s1;
  this-> node[1] = s2;
 }
};

vector<int> parent;

int find(int v){
  if (parent[v] != v) parent[v] = find(parent[v]);
  return parent[v];
}

void union_find(int a, int b){
  a = find(a);
  b = find(b);

  if (a!=b){
    parent[b] = a;
  }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
    int N; cin >> N;
    int M; cin >> M;
    vector<Node> v;
    
    v.assign(M+1,{0,0});
    parent.assign(N+1,0);

    for (int i =0 ; i < M; i++){
      int start, end;
      cin >> start >> end;
      v[i].node[0] = start;
      v[i].node[1] = end;
    }

    for (int i =0; i<= N; i++){
      parent[i] = i;
    }

    int cnt=0;
    for (int i=0; i < M; i++){
      int a = v[i].node[0];
      int b = v[i].node[1];

      if (find(a) != find(b)){
        union_find(a,b);
      }
    }

    set<int> setV;
    for (int i = 1; i <= N; i++){
      setV.insert(find(i));
      //cout << ":"<<parent[i] << ":";
    }
    cnt = setV.size();

    cout << "#" << test_case << " " << cnt << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}