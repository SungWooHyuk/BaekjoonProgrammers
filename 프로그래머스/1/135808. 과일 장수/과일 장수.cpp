#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), greater<>());
    int cnt = 0;
    for(int i = 0; i < score.size(); ++i)
    {
        cnt++;
        if(cnt == m)
        {
            cnt = 0;
            answer += score[i]*m;
        }
    }
    return answer;
}