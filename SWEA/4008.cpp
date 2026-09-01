#include <iostream>
#include <vector>
using namespace std;

vector<int> num;
vector<int> op_num;

int N;

int max_num = -1e9;
int min_num = 1e9;
void backtrackMin(int idx, int n)
{
    // if (n > min_num) return; 뺄셈 나눗셈도 있으니 삭제.

    if (idx >= N)
    {
        min_num = min(min_num, n);
        max_num = max(max_num, n);
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (op_num[i] > 0)
            {
                if (i == 0)
                {
                    op_num[i] -= 1;
                    int total = 0;
                    total = num[idx] + n;
                    backtrackMin(idx + 1, total);
                    op_num[i] += 1;
                }
                if (i == 1)
                {
                    op_num[i] -= 1;
                    int total = 0;
                    total = n - num[idx];
                    backtrackMin(idx + 1, total);
                    op_num[i] += 1;
                }
                if (i == 2)
                {
                    op_num[i] -= 1;
                    int total = 0;
                    total = num[idx] * n;
                    backtrackMin(idx + 1, total);
                    op_num[i] += 1;
                }
                if (i == 3)
                {
                    op_num[i] -= 1;
                    int total = 0;
                    total = n / num[idx];
                    backtrackMin(idx + 1, total);
                    op_num[i] += 1;
                }
            }
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        num.assign(N, 0);
        op_num.assign(4, 0);

        max_num = -1e9;
        min_num = 1e9;

        for (int i = 0; i < 4; i++)
        {
            cin >> op_num[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> num[i];
        }

        backtrackMin(1, num[0]);
        cout << "#" << test_case << " " << max_num-min_num << "\n";
    }

    return 0;
}