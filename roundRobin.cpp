#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct job
{
    int processid;
    int arrivaltime;
    int executiontime;
    int completionTime;
    int WaitingTime;
    int turnAround;
    int start_time;
    int bt_remaining;
} process[100];

bool compareProcessID(struct job p1, struct job p2)
{
    int x = p1.processid;
    int y = p2.processid;
    return x < y;
}
bool compareArrivalTime(struct job p1, struct job p2)
{
    int x = p1.arrivaltime;
    int y = p2.arrivaltime;
    return x < y;
}

int main()
{
    int n, position;
    queue<int> que;
    bool reached[100] = {false};
    bool isFirst = true;
    int cuurentTime = 0;
    int maxCompletionTime;
    int completed = 0, timeQuantum;
    int totalVacantTime = 0, lengthOfCycle;
    cout << "Enter total number of processes: ";
    cin >> n;
    float sum_tat = 0, sum_waiting = 0;

    cout << fixed << setprecision(2);
    cout << "Enter Quantum Time: ";
    cin >> timeQuantum;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Arrival Time for P"<<i+1<<": ";
        cin >> process[i].arrivaltime;
        process[i].processid = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Execution Time for P"<<i+1<<": ";
        cin >> process[i].executiontime;
        process[i].bt_remaining = process[i].executiontime;
    }

    sort(process, process + n, compareArrivalTime);

    que.push(0);
    reached[0] = true;

    while (completed != n)
    {
        position = que.front();
        que.pop();

        if (process[position].bt_remaining == process[position].executiontime)
        {
            process[position].start_time = max(cuurentTime, process[position].arrivaltime);
            totalVacantTime += (isFirst == true) ? 0 : process[position].start_time - cuurentTime;
            cuurentTime = process[position].start_time;
            isFirst = false;
        }

        if (process[position].bt_remaining - timeQuantum > 0)
        {
            process[position].bt_remaining -= timeQuantum;
            cuurentTime += timeQuantum;
        }
        else
        {
            cuurentTime += process[position].bt_remaining;
            process[position].bt_remaining = 0;
            completed++;

            process[position].completionTime = cuurentTime;
            process[position].turnAround = process[position].completionTime - process[position].arrivaltime;
            process[position].WaitingTime = process[position].turnAround - process[position].executiontime;

            sum_tat += process[position].turnAround;
            sum_waiting += process[position].WaitingTime;
        }

        for (int i = 1; i < n; i++)
        {
            if (process[i].bt_remaining > 0 && process[i].arrivaltime <= cuurentTime && reached[i] == false)
            {
                que.push(i);
                reached[i] = true;
            }
        }
        if (process[position].bt_remaining > 0)
            que.push(position);
        if (que.empty())
        {
            for (int i = 1; i < n; i++)
            {
                if (process[i].bt_remaining > 0)
                {
                    que.push(i);
                    reached[i] = true;
                    break;
                }
            }
        }
    }

    cout << "\nProcessId\tArrivalTime\tExecution Time\tCompletionTime\tTurnAroundTime\tWaitingTime\n";
    for (int i = 0; i < n; i++)
        cout << "P" << i + 1 << "\t\t" << process[i].arrivaltime << "\t\t" << process[i].executiontime << "\t\t" << process[i].completionTime << "\t\t" << process[i].turnAround << "\t\t" << process[i].WaitingTime << "\t\t"
             << "\n";

    cout << "Hence the Average Waiting Time= " << (float)sum_waiting / n;
    cout << "\nHence the Average Turn Around time= " << (float)sum_tat / n;
    return 0;
}
