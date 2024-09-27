#include <string>
#include <vector>
#include <set>
#include <iostream>
// 79114 를 예시로 들면 nPc
using namespace std;

int solution(vector<int> elements) {
    set<int> s;
    int size = elements.size();
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            int sum = 0;
            for(int k = j; k <= j+i; ++k) 
                sum += elements[k%elements.size()];
            
            s.insert(sum);
        }
    }
   
    return s.size();
}