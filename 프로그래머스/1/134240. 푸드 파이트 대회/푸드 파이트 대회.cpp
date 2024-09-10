#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int cnt = 0;
    
    for(int i = 1; i < food.size(); ++i)
    {
        if(food[i]%2 != 0){ // 홀수일때 -1 작업.
            food[i] -= 1;
        }
    }

    for(int i = 1; i <= food.size()-1; ++i) // 첫번째는 0이니까 무조건, 버리고 1부터 3,4,6 이면 2,4,6이다. cnt/2는 6이나온다.
    {
        for(int j = 0; j < food[i]/2; ++j) // 여기서 1을 넣어주고
        {
            answer += to_string(i);
        }
    }
    
    answer += '0';
    
    for(int i = food.size()-1; i >= 1; --i)
    {
        for(int j = 0; j < food[i]/2; ++j)
        {
            answer += to_string(i);
        }
    }
    
    return answer;
}