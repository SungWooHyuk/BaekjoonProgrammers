#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    vector<vector<int>> v;
    
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int camera_position = -30001;
    
    for (auto n : routes) {
        int s = n[0];
        int e = n[1];

        if (camera_position < s) {
            camera_position = e;  
            v.push_back({s, e});  
        }
    }
    
    return v.size();  
}
