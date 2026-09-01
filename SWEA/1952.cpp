#include<iostream>
#include<vector>
using namespace std;

vector<int> v;
vector<int> plan;

int min_cost = 1e9;

void backtrack(int idx, int num){
    if (num >= min_cost) return ;

    if (idx > 12){
        if (num < min_cost) min_cost = num;
        return;
    } 
    else {
         //4번쨰 방법.
        if (idx == 0) backtrack(idx+13, num + plan[3]);
        //2, 3 번째방법
        if (v[idx] > 0) {
            backtrack(idx+3, num+plan[2]);
            backtrack(idx+1, num+plan[1]);
        }
        // 1일권.
        backtrack(idx+1, num+ (plan[0] * v[idx]));
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

        v.assign(13,0);
        plan.assign(13,0);

        min_cost = 1e9;
        for (int i=0; i<4; i++){
            cin >> plan[i];
        }

        for (int i=1; i <= 12; i++){
            cin >> v[i];
        }

        backtrack(0,0);
        cout << "#" <<test_case << " " << min_cost << "\n";

	}
	return 0;
}