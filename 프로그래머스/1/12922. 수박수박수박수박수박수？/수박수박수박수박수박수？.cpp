#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int cnt = 0;
    while(n > cnt)
    {
        if(cnt%2 == 0)
            answer.append("수");
        else
            answer.append("박");
        cnt++;
    }
    return answer;
}