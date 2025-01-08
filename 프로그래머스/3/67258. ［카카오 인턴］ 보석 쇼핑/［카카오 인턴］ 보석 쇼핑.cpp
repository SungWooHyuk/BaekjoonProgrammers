#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    unordered_map<string, int> gem_count; // 보석의 개수를 저장
    set<string> gem_types(gems.begin(), gems.end()); // 보석 종류
    int total_types = gem_types.size(); // 모든 보석 종류의 개수

    int s = 0, e = 0; // 시작과 끝 포인터
    int min_length = gems.size() + 1; // 최소 길이 초기화

    while (e < gems.size()) {
        // 오른쪽 포인터로 보석 추가
        gem_count[gems[e]]++;
        e++;

        // 모든 종류의 보석이 포함될 때
        while (gem_count.size() == total_types) {
            // 최소 길이 갱신
            if (e - s < min_length) {
                min_length = e - s;
                answer[0] = s + 1; // 1-based index
                answer[1] = e;     // 1-based index
            }

            // 왼쪽 포인터로 보석 제거
            gem_count[gems[s]]--;
            if (gem_count[gems[s]] == 0) {
                gem_count.erase(gems[s]); // 종류 제거
            }
            s++;
        }
    }

    return answer;
}