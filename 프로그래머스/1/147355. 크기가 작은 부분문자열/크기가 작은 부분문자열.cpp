#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    int length = p.size();

    for(int i = 0; i < t.size()-length+1; ++i)
    {
        string str = t.substr(i, length);
        if(str <= p)
            answer++;
    }

    return answer;
}