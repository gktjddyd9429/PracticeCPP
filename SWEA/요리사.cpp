#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int N;

vector<vector<int>> v;
vector<int> t;
int min_diff;

void backtrack(int idx, int s){
    if (idx == N/2){
        int taste1 = 0;
        int taste2 = 0;

        bool isA[20] = {false,};
        for (int i=0; i< t.size(); i++){
            isA[t[i]] = true;
        }
        
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (i== j) continue;
                if (isA[i] && isA[j]) taste1 += v[i][j];               
                else if (!isA[i] && !isA[j]) taste2 += v[i][j];
            }
        }
    min_diff = min(min_diff, abs(taste1 - taste2));
    return; 
    }

    for (int i= s; i< N; i++){
        t.push_back(i);
        backtrack(idx+1,i+1);
        t.pop_back();
    }
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N; 
        
        v.assign(N, vector<int>(N,0));

        for (int i=0; i< N; i++){
            for(int j=0; j< N; j++){
                cin >> v[i][j];
            }
        }
        min_diff = 1e9;
        t.clear();

        backtrack(0, 0);

        cout << "#" << test_case << " " << min_diff << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}