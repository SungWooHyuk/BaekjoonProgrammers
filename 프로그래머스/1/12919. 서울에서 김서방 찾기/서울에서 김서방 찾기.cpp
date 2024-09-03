#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<string> seoul) {
    
    auto f = find(seoul.begin(), seoul.end(), "Kim");
    int pos = -1;
    if(f == seoul.end())
    {
        
    }
    else
    {
        pos = f - seoul.begin();
    }
    
    string answer = "김서방은 ";
    answer.append(to_string(pos));
    answer.append("에 있다");
    
    return answer;
}