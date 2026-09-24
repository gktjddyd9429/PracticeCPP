#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int N, M;
vector<vector<int>> v;
vector<vector<int>> sum;

int getsum(int r1, int r2, int c1, int c2){
    return sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1];
}

int main(){
    cin >> N >> M;
    v.assign(N+1, vector<int>(M+1));
    sum.assign(N + 1, vector<int>(M + 1, 0));

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> v[i][j];
        }
    }

    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + v[i][j];
        }
    }

    int max_min_polulation = 0;
    for (int r1=1; r1 <= N - 2; r1++){
        for (int r2 = r1 + 1; r2 <= N - 1; r2++){
            for (int c1 = 1; c1 <= M - 2; c1++){
                for (int c2 = c1+1; c2 <= M - 1; c2++){
                    int a1 = getsum(1,r1,1,c1);
                    int a2 = getsum(1,r1,c1+1,c2);
                    int a3 = getsum(1,r1,c2+1,M);

                    int a4 = getsum(r1+1,r2,1,c1);
                    int a5 = getsum(r1+1,r2,c1+1,c2);
                    int a6 = getsum(r1+1,r2,c2+1,M);

                    int a7 = getsum(r2+1,N, 1, c1);
                    int a8 = getsum(r2+1,N, c1+1, c2);
                    int a9 = getsum(r2+1,N, c2+1, M);

                    int min_pop = min({a1,a2,a3,a4,a5,a6,a7,a8,a9});

                    max_min_polulation = max(max_min_polulation,min_pop);
                }
            }
        }
    }

    cout << max_min_polulation << endl;
}