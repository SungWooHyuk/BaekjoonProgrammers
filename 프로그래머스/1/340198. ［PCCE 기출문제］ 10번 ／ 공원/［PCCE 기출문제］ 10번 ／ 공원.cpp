#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlaceMat(int size, int x, int y, const vector<vector<string>>& park) {
    // 돗자리가 공원 경계를 벗어나는지 확인
    if (x + size > park.size() || y + size > park[0].size()) {
        return false;
    }
    
    // 지정된 영역이 모두 빈자리('-1')인지 확인
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (park[i][j] != "-1") {
                return false; // 빈자리가 아니면 돗자리 못 놓음
            }
        }
    }
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    // 큰 돗자리부터 시도하기 위해 내림차순 정렬
    sort(mats.rbegin(), mats.rend());
    
    // 공원에 가장 큰 돗자리를 놓을 수 있는지 확인
    for (int size : mats) {
        for (int i = 0; i < park.size(); ++i) {
            for (int j = 0; j < park[i].size(); ++j) {
                if (canPlaceMat(size, i, j, park)) {
                    return size; // 가장 큰 돗자리 크기 반환
                }
            }
        }
    }
    
    // 아무 돗자리도 놓을 수 없는 경우
    return -1;
}