#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    for (int i = 0; i < section.size(); ++i) {
        // 현재 구간에서 칠할 수 있는 최대 구간의 끝
        int k = section[i] + m - 1;
        answer++;
        
        // k 안에 포함된 다음 섹션들은 모두 건너뜀
        while (i + 1 < section.size() && section[i + 1] <= k) {
            i++;
        }
        
        // 만약 현재 구간이 n을 넘으면 바로 리턴
        if (k >= n) {
            return answer;
        }
    }
    
    return answer;
}