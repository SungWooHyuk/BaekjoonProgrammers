#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    map<int,int> hash;
    
    for(int i = 0; i < numbers.size(); ++i)
    {
        for(int j = 0; j < numbers.size(); ++j)
        {
            if(i==j)
                continue;
            hash[numbers[i]+numbers[j]]++;
        }
    }
    
    for(auto n : hash)
        if(n.second != 0)
            answer.push_back(n.first);
    
    return answer;
}