#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer{0, 1000000};
    int p1 =0, p2 =0, sum = 0;
    
    for(int i = 0; i < sequence.size(); ++i)
    {
        sum += sequence[p1++];
        if(sum > k)
        {
            while(sum - sequence[p2] >= k)
            {
                sum -= sequence[p2++];
            }
        }
        
        if(sum == k)
            if(answer[1]-answer[0] > p1 - 1 - p2)
                answer = {p2, p1-1};
    }
    
    
    return answer;
}