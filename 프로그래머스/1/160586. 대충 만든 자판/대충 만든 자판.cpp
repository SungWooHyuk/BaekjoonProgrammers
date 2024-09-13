#include <string>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

// 같은 문자가 여러 번 할당 또는 하나에 같은 문자가 여러 번 할당 OK 없을 수도
// 못만들면 -1
// keymap이 몇개인지는 모르겠지만, 최소의 알파벳을 keymap으로 만들수있어야하는게 포인트
// 즉, A~Z까지의 배열을 만들어서 각자 최소로 만들수있는 값들을 넣어놓고
// targets를 하나씩 까서 알파벳을 하나씩 까면서 파악 후 값을 answer에 하나씩 넣어서 마무리

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    vector<pair<char, int>> alpha;
    int i = 0;
    while(alpha.size() < 26)
    {
        char a = 'A' + i;
        alpha.push_back(make_pair(a, 0));
        i++;
    }
    
    for(int i = 0; i < keymap.size(); ++i)
    {
        int cnt = 1;
        for(auto ch : keymap[i])
        {
            int k = ch - 'A';
            if(alpha[k].second > 0)
            {
                if(alpha[k].second > cnt)
                    alpha[k].second = cnt;
            }
            else
                alpha[k].second = cnt;
            
            cnt++;
        }
    }
    
    for(int i = 0; i < targets.size(); ++i)
    {
        int sum = 0;
        for(auto n : targets[i])
        {
            int k = n - 'A';
            if(alpha[k].second == 0){
                answer.push_back(-1);
                sum = -1;
                break;
            }
            else
                sum += alpha[k].second;
        }
        if(sum != -1)
            answer.push_back(sum);
    }
    return answer;
}