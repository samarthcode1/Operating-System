#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Total Number of Processes: ";
    cin >> n;
    int Arrival[10], execution[10], priority[10];
    int i, j;
    for (i = 0; i < n; i++)
    {
        cout << "Enter the arrival time for process "<< "p" << i + 1 << ": ";
        cin >> Arrival[i];
    }

    for (i = 0; i < n; i++)
    {
        cout << "Enter the execution time for process "<< "p" << i + 1 << ": ";
        cin >> execution[i];
    }
    
    for (i = 0; i < n; i++)
    {
        cout << "Enter the Priority for process "<< "p" << i + 1 << ": ";
        cin >> priority[i];
    }
    
    int temp[10];
    
    for (i = 0; i < n; i++)
    {
        temp[i] = execution[i];
    }
    
    int Waiting[10], TurnAround[10], completion[10];
    double avg = 0, tat = 0, end;
    priority[9] = -1;
    int count = 0;

    for (int time = 0; count != n; time++)
    {
        int smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (Arrival[i] <= time && priority[i] > priority[smallest] && execution[i] > 0)
                smallest = i;
        }
        execution[smallest]--;

        if (execution[smallest] == 0)
        {
            count++;
            end = time + 1;
            completion[smallest] = end;
            Waiting[smallest] = end - Arrival[smallest] - temp[smallest];
            TurnAround[smallest] = end - Arrival[smallest];
        }
    }

    cout << "ProcessID"<< "\t"<<"Arrival-time"<<"\t"<< "Execution-time"<< "\t"<< "Priority"<< "Waiting-time"<< "\t"<< "TurnAround-time"<< "\t"<< "completion-time"<< "\t"<< "\n";

    for (i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t\t" << Arrival[i] << "\t\t"<<temp[i]  << "\t\t"<< priority[i] <<"\t\t"<<  Waiting[i] << "\t\t" << TurnAround[i] << "\t\t" << completion[i] << "\n";
        avg = avg + Waiting[i];
        tat = tat + TurnAround[i];
    }

    cout << "Hence the Average Waiting time is =" << avg / n;
    cout << "\nHence the Average Turnaround time =" << tat / n << "\n";
}
