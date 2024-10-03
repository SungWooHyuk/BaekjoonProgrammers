#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
// 1. skill에 없는 알파벳은 싹 제거.
// 2. queue를 활용하면 어때?
// 예를들어서 skill을 하나씩 떼서 queue에 push를해주는거야
// queue랑 map같이스면 되겟다
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char, int> m;
    queue<char> q_skill;
    for(int i = 0; i < 26; ++i)
        m['A'+i] = -1; // 처음에 모든 알파벳 -1로세팅
    
    for(auto s :skill){
        m[s] = 1; // 존재하면 map 1과 queue push
        q_skill.push(s);
    }
    
    for(int i = 0; i < skill_trees.size(); ++i)
    {
        queue<char> q = q_skill;
        bool valid = true;
        for(int j = 0; j < skill_trees[i].size(); ++j)
        {
            if(m[skill_trees[i][j]] != -1) //존재
            {
                char ch = q.front();
                if(ch != skill_trees[i][j]){ // 스킬트리가 잘못됐다.
                    valid = false;
                    break;
                }
                else // 일치?
                    q.pop();
            }
            // 존재안하면스킵
        }
        if(valid)
            answer++;
    }
    
    
    return answer;
}