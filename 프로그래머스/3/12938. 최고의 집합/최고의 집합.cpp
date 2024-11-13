#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(s/n == 0)
    {
        answer.push_back(-1);
        return answer;
    }
    
    if(s%n == 0)
    {
        int k = s/n;
        for(int i = 0; i < n; ++i)
            answer.push_back(k);
    }
    else
    {
        int k = s/n; // 개수
        int remain = s%n; // 남은수 더하기 524
        int num = n - remain; // 나머지
        for(int i = 0; i < n; ++i)
        {
            if(num > 0){
                answer.push_back(k);
                num--;
            }
            else
                answer.push_back(k+1);
        }
    }
    
    return answer;
}