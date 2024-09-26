#include <string>
#include <vector>

using namespace std;
int GCD(int a, int b)
{
    while(b != 0)
    {
        int temp = a%b;
        a = b;
        b = temp;
    }
    
    return a;
}

int LCM(int a, int b)
{
    return a*b / GCD(a,b);
}
int solution(vector<int> arr) {

    int answer = arr[0];
    
    for(int i = 1; i < arr.size(); ++i)
        answer = LCM(answer, arr[i]);
    
    return answer;
}