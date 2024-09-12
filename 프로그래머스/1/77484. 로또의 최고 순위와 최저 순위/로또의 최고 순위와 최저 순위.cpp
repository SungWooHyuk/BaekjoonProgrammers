#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int rank[7] = {6, 6, 5, 4, 3, 2, 1};  // 0부터 6까지 배열, rank[0]은 사용하지 않음
    vector<int> answer;
    int zero = 0;
    int cnt = 0;

    // 0의 개수와 맞춘 번호 개수 세기
    for(int n : lottos) {
        if(n == 0) {
            zero++;
        } else if(find(win_nums.begin(), win_nums.end(), n) != win_nums.end()) {
            cnt++;
        }
    }
    
    // 최대 순위와 최소 순위 계산
    int max_rank = rank[cnt + zero];  // 최고 순위
    int min_rank = rank[cnt];         // 최저 순위

    answer.push_back(max_rank);
    answer.push_back(min_rank);
    
    return answer;
}