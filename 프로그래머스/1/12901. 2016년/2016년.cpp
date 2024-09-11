#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<int> month;
    
    for(int i = 1; i <= 12; ++i)
    {
        if(i < 8)
        {
            if(i == 2)
                month.push_back(29);
            else if(i % 2 != 0)
                month.push_back(31);
            else
                month.push_back(30);
        }
        else
        {
            if(i%2 == 0)
                month.push_back(31);
            else
                month.push_back(30);
        }
    }
    int cal = 0;
    for(int i = 0; i < a-1; ++i)
    {
        cal += month[i];
    }
    
    string str[7] = {"FRI", "SAT" , "SUN", "MON", "TUE", "WED", "THU" };
    int s = ((cal+b)-1)%7;
    return str[s];
   
}