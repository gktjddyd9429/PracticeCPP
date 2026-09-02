#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
bool success = false;

void dfs(int v){
  if (v == 99) { success = true; return;}
  for (int i=0; i< adj[v].size(); i++){
    if (!visited[adj[v][i]]){
      dfs(adj[v][i]);
    }
  }

}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	T= 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int n, edge;
    cin >> n >> edge;

    success = false;

    adj.assign(100,vector<int>());
    visited.assign(100,false);

    for (int i=0; i< edge; i++){
      int start, end;
      cin >> start >> end;
      adj[start].push_back(end);
    }
    
    dfs(0);
    
    if (success) cout << "#" << test_case << " " << 1 << "\n";
    else cout << "#" << test_case << " " << 0 << "\n";
	}
	return 0;
}