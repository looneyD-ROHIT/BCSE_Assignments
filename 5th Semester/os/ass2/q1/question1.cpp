#include <bits/stdc++.h>
#include "FCFS.h"
#include "RoundRobin.h"
// #include "PreemtivePriority.h"
#include <fstream>
using namespace std;

int main()
{

    string ans = "";
    string b = "";
    ifstream fin;

    // by default open mode = ios::in mode
    fin.open("JobProfile.txt");

    // Execute a loop until EOF (End of File)
    while (fin)
    {

        // Read a Line from File
        getline(fin, ans);

        // Print line in Console
        // cout << ans << endl;
    }

    // Close the file
    fin.close();
    int n = ans.length();
    int jobProfIndex = 0;
    int bsum = 0;
    int cnt = 0;
    string temp = "";
    unordered_map<int, vector<int>> umap;
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == '-' and ans[i + 1] == '1')
        {
            umap[jobProfIndex].push_back(bsum);
            // jobProfIndex++;
            cnt = 0;
            bsum = 0;
            i += 2;
        }
        else
        {
            if (isdigit(ans[i]))
            {
                temp.push_back(ans[i]);
                // cout<<1;
            }
            else if (ans[i] = ' ')
            {
                cnt++;
                // cout<<temp<<" ";
                int x = stoi(temp);
                temp = "";
                if (cnt == 1)
                    jobProfIndex = x;
                if (cnt <= 3 and cnt > 1)
                {
                    umap[jobProfIndex].push_back(x);
                }
                if (cnt > 3)
                {
                    bsum += x;
                }
            }
        }
    }
    cout << "THE JOB TABLE-----------------------\n";
    for (auto c : umap)
    {
        cout << c.first << " ";
        for (auto t : c.second)
        {
            cout << t << " ";
        }
        cout << endl;
    }

    umap[2] = {3, 0, 330};
    umap[1] = {1, 4, 70};
    cout << "STATISTICS OF ROUND FCFS-----------------" << endl;
    FCFS(umap);
    cout << "STATISTICS OF ROUND ROBIN PROCESS-----------------" << endl;
    RoundRobin(umap, 3);
    // cout << "STATISTICS OF PRIORITY PREEMTIVE PROCESS-----------------" << endl;
    // PreemtivePriority(umap);
}