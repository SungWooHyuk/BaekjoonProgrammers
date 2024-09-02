#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    if(num%2 == 0 || num == 0)
        return "Even";
    else
        return "Odd";
}