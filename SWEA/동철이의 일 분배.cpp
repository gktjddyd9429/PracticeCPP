#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

double v[20][20];
bool visited[20] = {false,};


int N; 
double total_num = -1 ;
void backtrack(int idx, double sum){

  if (sum <= total_num) return;
  if (idx == N){
    total_num = max(sum,total_num);
    return;
  }
  else{
    for (int i =0; i<N; i++){
      if (visited[i]) continue;
      if (v[idx][i] == 0) continue;
      
      visited[i] = true;
      backtrack(idx+1, sum * v[idx][i]);
      visited[i] = false;
      
    }
  }
}

int main(int argc, char** argv)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> N;


    total_num = -1 ;

    for (int i=0; i<N; i++){
      for (int j=0; j<N; j++){
        cin >> v[i][j];
        v[i][j] *=0.01;
      }
    }

    fill(visited,visited+20,false);

    backtrack(0,1);


    cout << "#" <<test_case<< " "<< fixed << setprecision(6) << 100 * total_num << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}