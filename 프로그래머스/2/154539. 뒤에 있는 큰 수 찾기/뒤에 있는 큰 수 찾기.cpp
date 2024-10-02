#include <string>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

vector<int> solution(vector<int> numbers) {
    
    vector<int> answer(numbers.size(), -1);
    stack<pair<int,int>> s;
    
    for(int i = 0; i < numbers.size(); ++i)
    {
        pair<int,int> temp_p = make_pair(numbers[i], i);
        
        while(!s.empty())
        {
            pair<int,int> s_t = s.top();
            if(s_t.first < temp_p.first){
                s.pop();
                answer[s_t.second] = temp_p.first;
            }
            else
            {
                s.push(temp_p);
                break;
            }
        }
        if(s.empty())
            s.push(temp_p);
    }
    return answer;
}