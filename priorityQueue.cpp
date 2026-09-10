#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


// ==============================
// Node1 : sort 전용
// ==============================
struct Node1 {
    int score;
    int age;
    int id;

    bool operator<(const Node1& other) const {

        // 1순위: score 큰 값이 앞
        if (score != other.score) {
            return score > other.score;
        }

        // 2순위: age 작은 값이 앞
        if (age != other.age) {
            return age < other.age;
        }

        // 3순위: id 작은 값이 앞
        return id < other.id;
    }
};


// ==============================
// Node2 : priority_queue 전용
// ==============================
struct Node2 {
    int score;
    int age;
    int id;

    bool operator<(const Node2& other) const {

        // 1순위: score 큰 값이 top
        if (score != other.score) {
            return score < other.score;
        }

        // 2순위: age 작은 값이 top
        if (age != other.age) {
            return age > other.age;
        }

        // 3순위: id 작은 값이 top
        return id > other.id;
    }
};


int main() {

    // ==============================
    // 1. sort
    // ==============================

    vector<Node1> v = {
        {90, 23, 3},
        {100, 25, 1},
        {90, 21, 5},
        {90, 21, 2},
        {80, 20, 4}
    };

    // operator< 자동 사용
    sort(v.begin(), v.end());

    cout << "sort 결과\n";

    for (Node1 cur : v) {
        cout << cur.score << " "
             << cur.age << " "
             << cur.id << '\n';
    }


    cout << "\n";


    // ==============================
    // 2. priority_queue
    // ==============================

    priority_queue<Node2> pq;

    pq.push({90, 23, 3});
    pq.push({100, 25, 1});
    pq.push({90, 21, 5});
    pq.push({90, 21, 2});
    pq.push({80, 20, 4});

    cout << "priority_queue 결과\n";

    while (!pq.empty()) {

        Node2 cur = pq.top();
        pq.pop();

        cout << cur.score << " "
             << cur.age << " "
             << cur.id << '\n';
    }

    return 0;
}