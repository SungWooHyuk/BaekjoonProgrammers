#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for (long long i = left; i <= right; ++i) {
        int row = i / n;  // 행
        int col = i % n;  // 열
        answer.push_back(max(row + 1, col + 1));
    }
    return answer;
}