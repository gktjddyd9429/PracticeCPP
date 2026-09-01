#include <iostream>
using namespace std;
int main()
{
    // 특정한 합을 가지는 부분 연속 수열 찾기.
    // 일부분의 데이터를 가지는 수열.
    // 1. 시작점과 끝점 첫 번째 원소의 인덱스(0)을 가리키도록 한다.
    // 2. 현재 부분 합이 M과 같으면, 카운트한다.
    // 3. 현재 부분 합이 M보다 작다면, end를 1 증가시킨다.
    // 4. 현재 부분 합이 M보다 크거나 같다면, start를 1 증가시킨다.
    // 5. 모든 경우를 확인할 때까지 2번부터 4번까지의 과정을 반복한다.

    int n = 5;
    int m = 5;
    int arr[] = {1, 2, 3, 4, 5};

    int cnt = 0, intervalSum = 0, end = 0;
    for (int start = 0; start < n; start++)
    {
        while (intervalSum < m && end < n)
        {
            intervalSum += arr[end];
            end += 1;
        }
        if (intervalSum == 5)
        {
            cnt += 1;
        }
        intervalSum -= arr[start];
    }
    cout << cnt << '\n';
}