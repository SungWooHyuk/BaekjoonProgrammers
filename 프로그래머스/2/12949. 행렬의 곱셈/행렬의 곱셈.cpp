#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 2 -3 2    5 4 3
// 4 -2 4    2 4 1
// 3 -1 4    3 1 1

// -1 4      3 3
// 3 2      3 3
// 4 1
// 3 * 2 2 * 2 = 3*2 행렬
// arr1의 가로 arr2의 세로 arr1의 j arr1의 i
// m * p p * n = m * n의 행렬이나오죠
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int m = arr1.size(); 
    int p = arr1[0].size(); 
    int n = arr2[0].size();
    
    for(int i = 0; i < m; ++i)
    {
        vector<int> vec;
        for(int j = 0; j < n; ++j)
        {
            int num = 0;
            for(int k = 0; k < p; ++k)
            {
                num += arr1[i][k] * arr2[k][j];
            }
            vec.push_back(num);
        }
        answer.push_back(vec);
    }
    return answer;
}