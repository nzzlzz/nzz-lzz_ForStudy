#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // 记录每个非零值对应的所有位置
    map<int, vector<int>, greater<int>> value_positions;
    for (int i = 0; i < n; ++i) {
        if (A[i] > 0) {
            value_positions[A[i]].push_back(i);
        }
    }

    vector<bool> activated(n, false);
    int current_cnt = 0;
    int max_cnt = 0;

    // 按值从大到小处理每个值
    for (auto &entry : value_positions) {
        int v = entry.first;
        vector<int> &positions = entry.second;

        // 处理所有等于v的位置
        for (int i : positions) {
            bool left = (i > 0) && activated[i - 1];
            bool right = (i < n - 1) && activated[i + 1];
            if (!left && !right) {
                current_cnt += 1;
            } else if (left && right) {
                current_cnt -= 1;
            }
            activated[i] = true;
        }

        // 更新最大值
        if (current_cnt > max_cnt) {
            max_cnt = current_cnt;
        }
    }

    // 处理原数组的非零段数目（当p=1时的结果）
    int original_cnt = 0;
    bool in_segment = false;
    for (int num : A) {
        if (num > 0) {
            if (!in_segment) {
                original_cnt++;
                in_segment = true;
            }
        } else {
            in_segment = false;
        }
    }
    max_cnt = max(max_cnt, original_cnt);

    cout << max_cnt << endl;

    return 0;
}