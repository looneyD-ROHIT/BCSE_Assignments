#include <bits/stdc++.h>
using namespace std;
void RoundRobin(unordered_map<int,vector<int>> m, int timeSlice){
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
    queue<pair<int,int>> q;
    while(!pq.empty()){
        auto it  = pq.top();
        pq.pop();
        // int arrivalTime = it.first;
        int jobID = it.second;
        int burstTime = m[it.second][2];
        if(burstTime <= timeSlice){
            int arrivalTime = it.first;
            // int burstTime = m[it.second][2];
            int completionTime = time + burstTime;
            time = completionTime;
            int tat = completionTime - arrivalTime;
            int wt = tat - burstTime;
            cout<<"JOB ID completed: "<<it.second<<" "<<"Turnaround Time: "<<tat<<" "<<"Waiting Time: "<<wt<<endl;
        }
        else{
            time += timeSlice;
            m[it.second][2] -= timeSlice;
            q.push({burstTime, jobID});
        }
    }
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int leftburstTime = m[it.second][2];
        if(leftburstTime <= timeSlice){
            int completionTime = time + leftburstTime;
            time = completionTime;
            int tat = completionTime - m[it.second][1];
            int wt = tat - leftburstTime;
            cout<<"JOB ID completed: "<<it.second<<" "<<"Turnaround Time: "<<tat<<" "<<"Waiting Time: "<<wt<<endl;
        }
        else{
            time += timeSlice;
            m[it.second][2] -= timeSlice;
            q.push({it.first,it.second});
        }
    }

}