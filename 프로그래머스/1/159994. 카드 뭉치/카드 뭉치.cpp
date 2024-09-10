#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int one = 0;
    int two = 0;
    
    for(int i = 0; i < goal.size(); ++i)
    {
        if(cards1[one] == goal[i])
            one++;
        else if(cards2[two] == goal[i])
            two++;
        else
            return "No";
    }
    return "Yes";
}