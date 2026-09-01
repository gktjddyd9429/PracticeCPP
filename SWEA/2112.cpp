#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> v;
int D, W, K;

int min_ans= 1e9;

bool isValid(){
    for (int c =0; c < W; c++){
        int current_streak = 1;
        bool pass = false;

        for (int r = 1; r < D; r++){
            if (v[r][c] == v[r-1][c]){
                current_streak++;
            }
            else {
                current_streak = 1;
            }
            if (current_streak >= K){
                pass = true;
                break;
            }
        }

        if(!pass) return false;
    }
    return true;
}

void backtrack(int idx, int inject_Cnt) {
    if (inject_Cnt >= min_ans) return; 

    if (idx == D) {
        if (isValid()) {
            min_ans = min(min_ans, inject_Cnt);
        }
        return;
    }

    vector<int> backup = v[idx];

    backtrack(idx + 1, inject_Cnt);

    for (int i = 0; i < W; i++) {
        v[idx][i] = 0;
    }
    backtrack(idx + 1, inject_Cnt + 1);

    for (int i = 0; i < W; i++) {
        v[idx][i] = 1;
    }
    backtrack(idx + 1, inject_Cnt + 1);
    
    v[idx] = backup;
}

int main(int argc, char** argv) {
    int test_case, T;
    cin >> T;

    for(test_case = 1; test_case <= T; ++test_case) {
        cin >> D >> W >> K;
        v.assign(D, vector<int>(W, 0));
        
        min_ans = K; 

        for (int i = 0; i < D; i++){
            for (int j = 0; j < W; j++){
                cin >> v[i][j];
            }
        }

        backtrack(0, 0);

        cout << "#" << test_case << " " << min_ans << "\n";
    }
    return 0;
}

