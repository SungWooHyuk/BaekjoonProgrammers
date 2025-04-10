#include <vector>
#include <algorithm>
using namespace std;

bool canCross(const vector<int>& stones, int k, int mid) {
    int count = 0;
    for (int stone : stones) {
        if (stone - mid <= 0) {
            count++;
            if (count >= k) return false;  // 연속 k개 이상 못 밟는 돌
        } else {
            count = 0;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int left = 1;
    int right = *max_element(stones.begin(), stones.end());
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (canCross(stones, k, mid)) {
            answer = mid;           // mid명은 건널 수 있음 → 더 많은 사람 시도
            left = mid + 1;
        } else {
            right = mid - 1;        // mid명은 못 건너므로 줄임
        }
    }
    return left;
}
