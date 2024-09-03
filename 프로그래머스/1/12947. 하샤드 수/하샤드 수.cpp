#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(int x) {
    string str_num = to_string(x);
    int num = 0;
    
    for(auto c : str_num)
        num += c - '0';
    
    if(x%num == 0)
        return true;
    else
        return false;
    
}