#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>
using namespace std;

string solution(string s) {
    int max_val = INT_MIN; // 최소값으로 초기화
    int min_val = INT_MAX; // 최대값으로 초기화
    int cur = 0;
    int size = s.size();
    
    for(int i = 0; i <= size; ++i)
    {
       if(i==size || s[i] == ' ')
       {
           string str = s.substr(cur, i-cur);
           int num = stoi(str);
            if (num > max_val) max_val = num;
            if (num < min_val) min_val = num;
          
           cur = i+1;
       }
    }
     return to_string(min_val) + " " + to_string(max_val);
}