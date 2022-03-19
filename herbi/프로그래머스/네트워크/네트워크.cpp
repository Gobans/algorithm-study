#include <string>
#include <vector>
#include <queue>
#define VMAX 200
using namespace std;
int findFirstValue(bool visit[], int n){
    for(int i=0; i<n; i++){
        if(visit[i] == false)
            return i;
    }
    return -1;
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int searched = 0;
    bool visit[VMAX] = {0};
    queue<int> q;
    
    while(searched < n){
        int first = findFirstValue(visit,n);
        if(first < 0)
            break;
        answer += 1;
        q.push(first);
        
        while(!q.empty()){
            int topval = q.front();
            q.pop();
            if(visit[topval] == true)
                continue;
            
            visit[topval] = true;
            // printf("topval: %d ,visit: ",topval);
            for(int i=0; i<n; i++) printf("%d ",visit[i]);
            // printf(", qSize: %d",q.size());
            // printf("\n");
            for(int i=0; i<computers[topval].size(); i++){
                if(computers[topval][i] == 1 && i != topval)
                    q.push(i);
            }
            // printf("qSize: %d\n",q.size());
        }
        // for(int i=0; i<n; i++) printf("%d ",visit[i]);
        // printf("\n");
    }
    return answer;
}