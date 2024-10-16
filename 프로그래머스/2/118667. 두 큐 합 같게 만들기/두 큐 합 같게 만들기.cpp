#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> q1;
    queue<int> q2;
    long long sum = 0;
    int limit = (queue1.size() + queue2.size())*2; 
    for(int i = 0; i < queue1.size(); ++i)
    {
        q1.push(queue1[i]);
        sum += queue1[i];
    }
    long long qu1 = sum;
    for(int i = 0; i < queue2.size(); ++i)
    {
        q2.push(queue2[i]);
        sum += queue2[i];
    }
    long long qu2 = sum - qu1;
    if(sum % 2 != 0)
        return -1;
    
    int cnt = 0;
    bool valid = true;
    
    if(qu1 == qu2)
        return 0;
    
    while(qu1 != qu2)
    {
        if(qu1 >= qu2)
        {
            int k = q1.front();
            qu1 -= k;
            q1.pop();
            q2.push(k);
            qu2 += k;
        }
        else
        {
            int k = q2.front();
            qu2 -= k;
            q2.pop();
            q1.push(k);
            qu1 += k;
        }
        
        cnt++;
        
        if(cnt > limit){
            valid = false;
            break;
        }
            
    }
    if(valid)
        return cnt;
    else
        return -1;
    

}