#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N;

vector<vector<int>> v;

vector<int> t;
int ans = 1e9;
void backtrack(int idx, int s){
    if (idx == N/2){
        int tasteA = 0;
        int tasteB = 0;

        bool isA[20] = {false,};

        for (int i =0; i< t.size(); i++){
            isA[t[i]] = true;
        }

        for (int i = 0; i<N; i++){
            for (int j =0; j<N; j++){
                if (i == j) continue;

                if (isA[i] && isA[j]){
                    tasteA += v[i][j];
                }
                else if (!isA[i] && !isA[j]){
                    tasteB += v[i][j];
                }
            }
        }
        int diff = abs(tasteA - tasteB);
        ans = min(ans,diff);

    }
    else{
        for (int i=s; i<N; i++){
            t.push_back(i);
            backtrack(idx+1,i+1);
            t.pop_back();
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

        v.assign(N, vector<int>(N,0));
        
        for (int i =0 ; i< N; i++){
            for (int j =0; j<N; j++){
                cin >> v[i][j];
            }
        }

        ans = 1e9;
        backtrack(0,0);
    
        cout<< "#" << test_case << " " << ans << "\n";
	}
	return 0;
}