#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solution(int storey) {
    string str = to_string(storey);
    reverse(str.begin(), str.end());
    
    bool plus = false;
    int answer = 0;
    
    for (int i = 0; i < str.size(); ++i) {
        int k = str[i] - '0';
        
        // 이전 자리에서 올림이 발생했을 경우
        if (plus) {
            k += 1;
            plus = false;
        }

        // 현재 자리 수가 5보다 작으면 그대로 더함
        if (k < 5) {
            answer += k;
        }
        // 현재 자리 수가 5와 같으면, 다음 자리 수를 고려해야 함
        else if (k == 5) {
            // 마지막 자리가 아닌 경우, 올림 여부를 판단해야 함
            if (i + 1 < str.size() && str[i + 1] >= '5') {
                // 다음 자리가 5 이상이면 올림
                plus = true;
            }
            answer += k;
        }
        // 현재 자리 수가 6 이상이면 올림을 수행
        else {
            answer += (10 - k);
            plus = true;
        }
    }
    
    // 마지막 자리에서 올림이 발생한 경우 추가
    if (plus) {
        answer += 1;
    }
    
    return answer;
}
