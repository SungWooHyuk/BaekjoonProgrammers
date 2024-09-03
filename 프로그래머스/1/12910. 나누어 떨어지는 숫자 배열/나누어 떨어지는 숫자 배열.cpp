#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    sort(arr.begin(), arr.end());    
    
    for(auto n : arr)
        if(n%divisor == 0)
            answer.push_back(n);
    
    if(answer.size() <= 0)
        answer.push_back(-1);
    
    return answer;
}