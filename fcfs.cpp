#include <iostream>
using namespace std;

int waitingTime(int process[], int execution[], int waiting[],int n)
{
	waiting[0] = 0;
	for (int i = 1; i < n; i++)
	{
		waiting[i] = execution[i - 1] + waiting[i - 1];
	}
	return 0;
}

int turnAroundTime(int process[], int execution[], int waiting[], int tat[],int n)
{
	for (int i = 0; i < n; i++)
	{
		tat[i] = execution[i] + waiting[i];
	}
	return 0;
}


int avgTime(int process[], int execution[],int n)
{
	int waiting[n], tat[n];
	int totalWait = 0, totalturnArr = 0;
	waitingTime(process, execution, waiting,n);
	turnAroundTime(process,execution, waiting, tat,n);
	cout << "Processes "<< " Execution Time "<< " Waiting Time "<< "TurnAroundTime " << "\n";
	for (int i = 0; i < n; i++)
	{
		totalWait = totalWait + waiting[i];
		totalturnArr = totalturnArr + tat[i];
		cout << "P" << i + 1 << "\t\t" << execution[i] << "\t\t " << waiting[i] << "\t\t " << tat[i] << "\n";
	}
	cout << "Hence the Average waiting time = " << (float)totalWait / (float)n<<"\n";
	cout << "Hence the Average turn around time = " << (float)totalturnArr / (float)n<<"\n";
	return 0;
}
int main()
{
	int n;
	cout << "Enter Total Numner of Processes: ";
	cin >> n;
	int process[n], ExecutionTime[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the Arrival time for p"<<i+1<<": ";
		cin >> process[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the Execution time for p"<<i+1<<": ";
		cin >> ExecutionTime[i];
	}
	avgTime(process, ExecutionTime,n);
	return 0;
}