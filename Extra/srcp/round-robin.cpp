#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Process
{
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
};

int main()
{
    int n, tq;
    cout << "Enter the number of processes";
    cin >> n;

    Process p[n];

    for (int i = 0; i < n; i++)
    {
        p[i].id = i;
        cout << "Enter AT and BT for p" << i << ": ";
        cin >> p[i].at >> p[i].bt;
        // initially remaining = burst
        p[i].rt = p[i].bt;
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    queue<int> q;
    int time = 0;
    int completed = 0;
    vector<bool> visited(n, false);

    while (completed < n)
    {

        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= time && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }

        if (q.empty())
        {
            time++;
            continue;
        }

        int idx = q.front();
        q.pop();

        if (p[idx].rt > tq)
        {
            time += tq;
            p[idx].rt -= tq;
        }
        else
        {
            time += p[idx].rt;
            p[idx].rt = 0;
            p[idx].ct = time;
            completed++;
        }

        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= time && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }

        if (p[idx].rt > 0)
        {
            q.push(idx);
        }
    }

    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }

    cout << "\np\tAt\tBt\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << endl;
    }

    return 0;
}
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cout << "Enter total number of processes: ";
    cin >> n;

    int pid[20], at[20], bt[20], pr[20];
    int rem_bt[20], ct[20], tat[20], wt[20];
    bool done[20] = {false};

    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        cout << "\nProcess P" << pid[i] << endl;
        cout << "Enter Arrival Time: ";
        cin >> at[i];
        cout << "Enter Burst Time: ";
        cin >> bt[i];
        cout << "Enter Priority (higher number = higher priority): ";
        cin >> pr[i];
        rem_bt[i] = bt[i];
    }

    int time = 0, completed = 0;

    while (completed < n)
    {
        int idx = -1;
        int bestPriority = INT_MIN;
        int earliestAT = INT_MAX;

        // Select highest priority process
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && !done[i])
            {
                if (pr[i] > bestPriority ||
                    (pr[i] == bestPriority && at[i] < earliestAT))
                {
                    bestPriority = pr[i];
                    earliestAT = at[i];
                    idx = i;
                }
            }
        }

        // CPU idle
        if (idx == -1)
        {
            time++;
            continue;
        }

        // Execute for 1 unit time
        rem_bt[idx]--;
        time++;

        if (rem_bt[idx] == 0)
        {
            done[idx] = true;
            ct[idx] = time;
            completed++;
        }
    }

    // Calculate TAT and WT
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout << "\nPROCESS\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << pr[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << endl;
    }

    float avgWT = 0, avgTAT = 0;
    for (int i = 0; i < n; i++)
    {
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    cout << "\nAverage Waiting Time = " << avgWT / n;
    cout << "\nAverage Turnaround Time = " << avgTAT / n;

    return 0;
}