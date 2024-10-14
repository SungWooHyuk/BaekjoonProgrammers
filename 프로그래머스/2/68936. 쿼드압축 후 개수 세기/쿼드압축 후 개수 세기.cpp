#include <vector>
#include <string>
using namespace std;

int result[2] = {0, 0}; // 결과를 저장할 배열: 0의 개수와 1의 개수

// 주어진 구역이 모두 동일한 값으로 이루어졌는지 확인하는 함수
bool isSameValue(const vector<vector<int>>& arr, int x, int y, int size) {
    int value = arr[x][y];
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (arr[i][j] != value)
                return false; // 다른 값이 있으면 false 반환
        }
    }
    return true; // 모든 값이 같으면 true 반환
}

// 분할 정복 알고리즘으로 배열을 재귀적으로 쪼개는 함수
void divide(const vector<vector<int>>& arr, int x, int y, int size) {
    if (isSameValue(arr, x, y, size)) {
        // 구역 내 모든 값이 동일할 경우 해당 값을 카운트
        result[arr[x][y]]++;
    } else {
        // 배열을 4개로 분할하여 재귀적으로 처리
        int newSize = size / 2;
        divide(arr, x, y, newSize); // 좌측 상단
        divide(arr, x + newSize, y, newSize); // 우측 상단
        divide(arr, x, y + newSize, newSize); // 좌측 하단
        divide(arr, x + newSize, y + newSize, newSize); // 우측 하단
    }
}

// 주어진 2차원 배열에서 0과 1의 개수를 반환하는 함수
vector<int> solution(vector<vector<int>> arr) {
    int n = arr.size(); // 배열의 크기
    divide(arr, 0, 0, n); // (0, 0)에서 시작해 전체 배열을 탐색
    return {result[0], result[1]}; // 0의 개수와 1의 개수를 반환
}
