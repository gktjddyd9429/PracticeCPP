#include<iostream>
#include<vector>
using namespace std;

struct Node{
  int left=0;
  int right=0;
};



int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

  int N, E, node1, node2;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
    int N, E, node1, node2;
    cin >> N >> E >> node1 >> node2;


    vector<Node> n;
    n.resize(N+1);

    for (int i=0; i < E; i++){
      int value, node;
      cin >> value >> node;

      if (n[value].left == 0){
        n[value].left= node;
      }
      else{
        n[value].right= node;
      }
    }





	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}