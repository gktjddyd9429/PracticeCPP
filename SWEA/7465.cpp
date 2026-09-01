#include<iostream>
#include<vector>
#include<set> 

using namespace std;

struct Edge{
	int Node[2];
    
    Edge (int start, int end){
    	this ->Node[0] = start;
        this ->Node[1] = end;
    }
};

vector<Edge> adj;
vector<int> parent;
vector<int> ranked;

int find (int v){
	if (parent[v] != v) parent[v] = find(parent[v]);
    return parent[v];
}

void union_sets(int a, int b){
	a = find(a);
    b = find(b);
    
    if ( ranked[a] < ranked[b] ) swap(a,b);
    parent[b] = a;
    if (ranked[a] == ranked[b]) ranked[a]++;
} 

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
        cin >> N >> M;
        
        adj.clear();
        
        for (int i=0; i<M; i++){
        	int start, end; cin >> start >> end;
            adj.push_back({start, end });
        }
        parent.assign(N+1, 0);
        ranked.assign(N+1,0);
        
        for (int i=1; i<=N; i++){
        	parent[i] = i;
            ranked[i] = 0;
        }
		
        for(Edge e : adj){
        	if (find (e.Node[0]) != find(e.Node[1])){
            	union_sets(e.Node[0], e.Node[1]);
            }
        }
       set<int> s;
        for (int i =1; i<=N; i++){
        	s.insert(find(i));
        }
		cout << "#" << test_case <<" "<< s.size() << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}