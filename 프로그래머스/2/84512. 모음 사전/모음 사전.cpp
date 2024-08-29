#include <string>
#include <vector>
#include <map>

using namespace std;
// 가중치 풀이 ..
int solution(string word) {
    int answer = 0;
    map<char, int> alp;
    int next_word[5] = { 781, 156, 31, 6, 1 };
    
    alp.insert({'A', 0});
    alp.insert({'E', 1});
    alp.insert({'I', 2});
    alp.insert({'O', 3});
    alp.insert({'U', 4});
    
    int i = 0;
    for (const auto& w : word) {
        answer += 1 + alp[w] * next_word[i];
        i++;
    }
    
    return answer;
}
