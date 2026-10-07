#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Matrix
{
  int r, c;
};

int main(int argc, char **argv)
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case)
  {
    int N;
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        cin >> grid[i][j];
      }
    }

    vector<Matrix> matrices;
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (grid[i][j] != 0 && !visited[i][j])
        {
          int r_end = i;
          int c_end = j;

          while (c_end + 1 < N && grid[i][c_end + 1] != 0)
          {
            c_end++;
          }
          while (r_end + 1 < N && grid[r_end + 1][j] != 0)
          {
            r_end++;
          }

          for (int r = i; r <= r_end; r++)
          {
            for (int c = j; c <= c_end; c++)
            {
              visited[r][c] = true;
            }
          }

          int rows = r_end - i + 1;
          int cols = c_end - j + 1;
          matrices.push_back({rows, cols});
        }
      }
    }

    int m_count = matrices.size();

    vector<Matrix> sorted_matrices;
    int start_idx = -1;

   
    for (int i = 0; i < m_count; i++)
    {
      bool is_start = true;
      for (int j = 0; j < m_count; j++)
      {
        if (i == j) continue;
        if (matrices[i].r == matrices[j].c)
        {
          is_start = false;
          break;
        }
      }
      if (is_start)
      {
        start_idx = i;
        break;
      }
    }


    int curr_idx = start_idx;
    while (curr_idx != -1)
    {
      sorted_matrices.push_back(matrices[curr_idx]);
      int next_idx = -1;
      for (int j = 0; j < m_count; j++)
      {
        if (matrices[curr_idx].c == matrices[j].r)
        {
          next_idx = j;
          break;
        }
      }
      curr_idx = next_idx;
    }


    vector<int> d(m_count + 1);
    d[0] = sorted_matrices[0].r;
    for (int i = 0; i < m_count; i++)
    {
      d[i + 1] = sorted_matrices[i].c;
    }

    vector<vector<int>> M(m_count + 1, vector<int>(m_count + 1, 0));

    for (int diagonal = 1; diagonal <= m_count - 1; diagonal++)
    {
      for (int i = 1; i <= m_count - diagonal; i++)
      {
        int j = i + diagonal;
        M[i][j] = 1e9; 

        for (int k = i; k <= j - 1; k++)
        {
          int cost = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
          M[i][j] = min(M[i][j], cost);
        }
      }
    }

    cout << "#" << test_case << " " << M[1][m_count] << "\n";
  }

  return 0;
}