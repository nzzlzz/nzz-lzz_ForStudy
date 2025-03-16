#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 计算当前数组的非零段数量
int countNonZeroSegments(const vector<int>& A) {
    int count = 0;
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        if (A[i] > 0 && (i == 0 || A[i - 1] == 0)) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    set<int, greater<int>> unique_values; // 存储唯一值，并降序排序
    
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        unique_values.insert(A[i]);
    }
    
    int maxSegments = countNonZeroSegments(A); // 初始情况下的非零段数量
    
    for (int p : unique_values) {
        vector<int> modifiedA(n);
        for (int i = 0; i < n; ++i) {
            modifiedA[i] = (A[i] < p) ? 0 : A[i];
        }
        int segments = countNonZeroSegments(modifiedA);
        if (segments > maxSegments) {
            maxSegments = segments;
        } else {
            break; // 当段数不再增加时，终止遍历
        }
    }
    
    cout << maxSegments << endl;
    return 0;
}