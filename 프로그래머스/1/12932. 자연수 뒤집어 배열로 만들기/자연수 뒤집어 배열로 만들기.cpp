#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(long long n) {
    string str_num = to_string(n);
    vector<int> answer;
    for(auto c : str_num)
    {
        answer.push_back(c - '0');
    }
    reverse(answer.begin(), answer.end());
    return answer;
}