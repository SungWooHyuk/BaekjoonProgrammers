#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> check;
    for(int i = 0; i < score.size(); ++i)
    {
        if(check.size() < k)
            check.push_back(score[i]);
        else
        {
            if(check[0] < score[i])
                check[0] = score[i];
        }
        
        sort(check.begin(), check.end());
        answer.push_back(check[0]);
    }
    return answer;
}