#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    int i, j;
    int arrTime[n], executionTime[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter the arrival time for process "<< "p" << i + 1 << ": ";
        cin >> arrTime[i];
    }
    for (i = 0; i < n; i++)
    {
        cout << "Enter the execution time for process "<< "p" << i + 1 << ": ";
        cin >> executionTime[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (executionTime[i] > executionTime[j])
            {
                swap(arrTime[i], arrTime[j]);
                swap(executionTime[i], executionTime[j]);
            }
        }
    }

    int d;
    int minTime = arrTime[0];
    for (i = 0; i < n; i++)
    {
        if (minTime > arrTime[i])
        {
            minTime = arrTime[i];
            d = i;
        }
    }

    int total_time;
    int exe[n];
    exe[d] = minTime+ executionTime[d];
    total_time = exe[d];
    for (i = 0; i < n; i++)
    {
        if (arrTime[i] != minTime)
        {
            exe[i] = executionTime[i] + total_time;
            total_time = exe[i];
        }
    }
    int tat[n], wt[n];
    float totalTAT = 0, totalWT = 0;
    for (i = 0; i < n; i++)
    {
        tat[i] = exe[i] - arrTime[i];
        totalTAT = totalTAT + tat[i];
        wt[i] = tat[i] - executionTime[i];
        totalWT = totalWT + wt[i];
    }
    
    float avgTAT = 0, avgWT = 0;
    avgTAT = totalTAT / n;
    avgWT = totalWT / n;

    cout << "ProcessID\tArrivalTime\tExecutionTime\tWaitingTime\tTurnAroundTime "<< "\n";
    for (i = 0; i < n; i++)
    {
        cout <<"P:"<<i + 1 << "\t\t " << arrTime[i] << "\t\t " << executionTime[i] << "\t\t" << wt[i] << "\t\t " << tat[i] << "\n";
    }
    cout << "Hence the Average waiting time is " << avgWT << "\n";
    cout << " Hence the Average turn around time is " << avgTAT;

    return 0;
}