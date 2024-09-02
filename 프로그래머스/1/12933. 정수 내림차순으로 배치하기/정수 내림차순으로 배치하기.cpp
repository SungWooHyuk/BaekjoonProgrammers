#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    string answer = "";
    string strNum = to_string(n);
    vector<int> number;
    while(n != 0)
    {
        int num = n%10;
        number.push_back(num);       
        n = n/10;
    }
    
    sort(number.begin(), number.end(), greater<>());
    
    for(auto n : number)
        answer.append(to_string(n));
    
    return stol(answer);
}