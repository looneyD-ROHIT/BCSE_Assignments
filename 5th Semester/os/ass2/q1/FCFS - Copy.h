
#include <bits/stdc++.h>
using namespace std;
void FCFS(unordered_map<int,vector<int>> m){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // vector<int> ans;
    
    int time = 0;
    for(auto c : m){
        int jobID = c.first;
        int arrivaltime = c.second[1];
        int priority = c.second[0];
        int burstTime = c.second[2];
        pq.push({arrivaltime,jobID});
    }
    time = pq.top().first;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int arrivalTime = it.first;
        int burstTime = m[it.second][2];
        int completionTime = time + burstTime;
        time = completionTime;
        int tat = completionTime - arrivalTime;
        int wt = tat - burstTime;
        cout<<"JOB ID: "<<it.second<<" "<<"Turnaround Time: "<<tat<<" "<<"Waiting Time: "<<wt<<endl;

    }

}