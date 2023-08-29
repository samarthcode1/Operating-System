// // FIRSTFIT Segmention
// // #include <iostream>
// // #include <bits/stdc++.h>
// // using namespace std;
// // void firstFit(int blockSize[], int m, int processSize[], int N)
// // {
// //     int allocation[N];
// //     memset(allocation, -1, sizeof(allocation));
// //     for (int i = 0; i < N; i++)
// //     {
// //         for (int j = 0; j < m; j++)
// //         {
// //             if (blockSize[j] >= processSize[i])
// //             {
// //                 allocation[i] = j;
// //                 blockSize[j] -= processSize[i];
// //                 break;
// //             }
// //         }
// //     }
// //     cout << "\N Process \t Process Size \t Block No.\N";
// //     for (int i = 0; i < N; i++)
// //     {
// //         cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
// //         if (allocation[i] != -1)
// //         {
// //             cout << allocation[i] + 1;
// //         }
// //         else
// //         {
// //             cout << "not Allocated";
// //         }
// //         cout << "\N";
// //     }
// // }
// // int main()
// // {
// //     int m;
// //     cout << "Enter the total number of Blocks\N";
// //     cin >> m;
// //     int blockSize[m];
// //     for (int i = 0; i < m; i++)
// //     {
// //         cin >> blockSize[i];
// //     }
// //     int N;
// //     cout << "Enter the total number of processes\N";
// //     cin >> N;
// //     int processSize[N];
// //     for (int i = 0; i < N; i++)
// //     {
// //         cin >> processSize[i];
// //     }
// //     firstFit(blockSize, m, processSize, N);
// //     return 0;
// // }

// // BESTFIT Segmentation
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// void bestFit(int blockSize[],int m,int processSize[],int N){
//     int allocation[N];
//     memset(allocation ,-1,sizeof(allocation));
//     for(int i=0;i<m;i++){
//         int bestIndex=-1;
//         for(int j=0;j<m;j++){
//             if(blockSize[j]>=processSize[i]){
//                 if(bestIndex==-1){
//                     bestIndex=j;
//                 }
//                 else if(blockSize[bestIndex]>blockSize[j]){
//                     bestIndex=j;
//                 }
//             }
//         }
//         if(bestIndex!=-1){
//             allocation[i]=bestIndex;
//             blockSize[bestIndex]-=processSize[i];
//         }
//     }
//     cout << "\nProcess No.\tProcess Size\tBlock no.\N";
//     for (int i = 0; i < N; i++)
//     {
//         cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
//         if (allocation[i] != -1)
//             cout << allocation[i] + 1;
//         else
//             cout << "Not Allocated";
//         cout << endl;
//     }
// }

// int main()
// {
//     int m;
//     cout << "Enter the total number of Blocks\N";
//     cin >> m;
//     int blockSize[m];
//     for (int i = 0; i < m; i++)
//     {
//         cin >> blockSize[i];
//     }
//     int N;
//     cout << "Enter the total number of processes\N";
//     cin >> N;
//     int processSize[N];
//     for (int i = 0; i < N; i++)
//     {
//         cin >> processSize[i];
//     }
//     bestFit(blockSize, m, processSize, N);
//     return 0;
// }

// // WorstFit Segmentation

// // #include <bits/stdc++.h>
// // using namespace std;
// // void WorstFit(int blockSize[],int m,int processSize[],int N){
// //     int allocation[N];
// //     memset(allocation,-1,sizeof(allocation));
// //     for(int i=0;i<N;i++){
// //         int worstIndex=-1;
// //         for(int j=0;j<m;j++){
// //             if(blockSize[j]>=processSize[i]){
// //                 if(worstIndex==-1){
// //                     worstIndex=j;
// //                 }
// //                 else if(blockSize[worstIndex]<blockSize[j]){
// //                     worstIndex=j;
// //                 }
// //             }
// //         }
// //         if(worstIndex!=-1){
// //             allocation[i]=worstIndex;
// //             blockSize[worstIndex]-=processSize[i];
// //         }
// //     }
// //     cout<<"\N Process \t Process Size \t Block Size \N";
// //     for(int i=0;i<N;i++){
// //         cout<<" "<<i+1<<"\t\t"<<processSize[i]<<"\t\t";
// //         if(allocation[i]!=-1){
// //             cout<<allocation[i]+1;
// //         }
// //         else{
// //             cout<<"Not Allocated";
// //         }
// //         cout<<"\N";
// //     }
// // }
// // int main(){
// //     int m;
// //     cout<<"Enter total number of Blocks\N";
// //     cin>>m;
// //     int blockSize[m];
// //     for(int i=0;i<m;i++){
// //         cin>>blockSize[i];
// //     }
// //     int N;
// //     cout<<"Enter total number of processes\N";
// //     cin>>N;
// //     int processSize[N];
// //     for(int i=0;i<N;i++){
// //         cin>>processSize[i];
// //     }
// //     WorstFit(blockSize, m, processSize, N);
// //     return 0;
// // }

// // BankerAlgorithm
// //  #include <bits/stdc++.h>
// //  using namespace std;
// //  int main()
// //  {
// //      int processes, resources, i, j, k;
// //      cout << "Enter the Number of processes\N";
// //      cin >> processes;
// //      cout << "Enter the number of resources\N";
// //      cin >> resources;
// //      int allocation[processes][resources];
// //      cout << "Enter the allocation\N";
// //      for (int i = 0; i < processes; i++)
// //      {
// //          for (int j = 0; j < resources; j++)
// //          {
// //              cin >> allocation[i][j];
// //          }
// //      }
// //      cout << "Enter Max allocation\N";
// //      int maximum[processes][resources];
// //      for (int i = 0; i < processes; i++)
// //      {
// //          for (int j = 0; j < resources; j++)
// //          {
// //              cin >> maximum[i][j];
// //          }
// //      }
// //      cout << "Enter Available resources\N";
// //      int available[resources];
// //      for (int i = 0; i < resources; i++)
// //      {
// //          cin >> available[i];
// //      }
// //      int finish[processes], res[processes], ind = 0;
// //      memset(finish, 0, sizeof(finish));
// //      int need[processes][resources];
// //      for (i = 0; i < processes; i++)
// //      {
// //          for (j = 0; j < resources; j++)
// //              need[i][j] = maximum[i][j] - allocation[i][j];
// //      }
// //      cout << "Need Allocations\N";
// //      for (i = 0; i < processes; i++)
// //      {
// //          for (j = 0; j < resources; j++)
// //          {
// //              cout << need[i][j] << " ";
// //          }
// //          cout << "\N";
// //      }
// //      int y = 0;
// //      for (k = 0; k < processes; k++)
// //      {
// //          for (i = 0; i < processes; i++)
// //          {
// //              if (finish[i] == 0)
// //              {
// //                  int flag = 0;
// //                  for (j = 0; j < resources; j++)
// //                  {
// //                      if (need[i][j] > available[j])
// //                      {
// //                          flag = 1;
// //                          break;
// //                      }
// //                  }
// //                  if (flag == 0)
// //                  {
// //                      res[ind++] = i;
// //                      for (y = 0; y < resources; y++)
// //                      {
// //                          available[y] += allocation[i][y];
// //                      }
// //                      finish[i] = 1;
// //                  }
// //              }
// //          }
// //      }
// //      int flag = 1;
// //      for (int i = 0; i < processes; i++)
// //      {
// //          if (finish[i] == 0)
// //          {
// //              flag = 0;
// //              cout << "The process is not safe,chance of deadlock\N";
// //              break;
// //          }
// //      }
// //      if (flag == 1)
// //      {
// //          cout << "The Safe sequence is for the process is\N";
// //          cout << "Sequence:\N";
// //          for (i = 0; i < processes; i++)
// //          {
// //              cout << " P->" << res[i];
// //          }
// //      }
// //      return 0;
// //  }

// // Dininng Philosophers
// // #include <bits/stdc++.h>
// // #include <mutex>
// // #include <thread>
// // using namespace std;
// // const int total_philosopher = 5;
// // mutex forks[total_philosopher];
// // void philosopher(int number){
// //     int right_fork=(number+1)%total_philosopher;
// //     int left_fork=number;
// //     while(true){
// //         cout<<"Philosopher"<<number <<" is currently Thinking\N";
// //         this_thread::sleep_for(chrono::milliseconds(2000));
// //         cout<<"Philosopher"<<number<<" is hungry and planning to pick up the forks.\N";
// //         lock(forks[left_fork],forks[right_fork]);
// //         cout<<"Philosopher"<<number<< " picked the "<<left_fork<<" forks"<< "and "<<right_fork<<" and started eating.\N";
// //         this_thread::sleep_for(chrono::milliseconds(2000));
// //         forks[right_fork].unlock();
// //         forks[left_fork].unlock();
// //         cout << "Philosopher" << number << " finished eating and put down forks" << left_fork << " and " << right_fork << "." << "\N";
// //     }
// // }

// // int main()
// // {
// //     thread p[total_philosopher];
// //     for(int i=0;i<total_philosopher;i++){
// //         p[i]=thread(philosopher,i);
// //     }
// //     for(int i=0;i<total_philosopher;i++){
// //         p[i].join();
// //     }
// //     return 0;
// // }

// // fcfs
// //  #include <iostream>
// //  using namespace std;

// // int waitingTime(int process[], int execution[], int waiting[],int N)
// // {
// // 	waiting[0] = 0;
// // 	for (int i = 1; i < N; i++)
// // 	{
// // 		waiting[i] = execution[i - 1] + waiting[i - 1];
// // 	}
// // 	return 0;
// // }

// // int turnAroundTime(int process[], int execution[], int waiting[], int tat[],int N)
// // {
// // 	for (int i = 0; i < N; i++)
// // 	{
// // 		tat[i] = execution[i] + waiting[i];
// // 	}
// // 	return 0;
// // }

// // int avgTime(int process[], int execution[],int N)
// // {
// // 	int waiting[N], tat[N];
// // 	waitingTime(process, execution, waiting,N);
// // 	turnAroundTime(process,execution, waiting, tat,N);
// // 	int totalWait = 0, totalturnArr = 0;
// // 	cout << "Processes "<< " Execution Time "<< " Waiting Time "<< "TurnAroundTime " << "\N";
// // 	for (int i = 0; i < N; i++)
// // 	{
// // 		totalWait = totalWait + waiting[i];
// // 		totalturnArr = totalturnArr + tat[i];
// // 		cout << "P" << i + 1 << "\t\t" << execution[i] << "\t\t " << waiting[i] << "\t\t " << tat[i] << "\N";
// // 	}
// // 	cout << "Hence the Average waiting time = " << (float)totalWait / (float)N<<"\N";
// // 	cout << "Hence the Average turn around time = " << (float)totalturnArr / (float)N<<"\N";
// // 	return 0;
// // }
// // int main()
// // {
// // 	int N;
// // 	cout << "Enter Total Numner of Processes: ";
// // 	cin >> N;
// // 	int process[N], ExecutionTime[N];
// // 	for (int i = 0; i < N; i++)
// // 	{
// // 		cout << "Enter the Arrival time for p"<<i+1<<": ";
// // 		cin >> process[i];
// // 	}
// // 	for (int i = 0; i < N; i++)
// // 	{
// // 		cout << "Enter the Execution time for p"<<i+1<<": ";
// // 		cin >> ExecutionTime[i];
// // 	}
// // 	avgTime(process, ExecutionTime,N);
// // 	return 0;
// // }

// // SJF
// //  #include <iostream>
// //  using namespace std;
// //  int main()
// //  {
// //      int N;
// //      cout << "Enter the number of processes: ";
// //      cin >> N;
// //      int i, j;
// //      int arrTime[N], executionTime[N];
// //      for (i = 0; i < N; i++)
// //      {
// //          cout << "Enter the arrival time for process "<< "p" << i + 1 << ": ";
// //          cin >> arrTime[i];
// //      }
// //      for (i = 0; i < N; i++)
// //      {
// //          cout << "Enter the execution time for process "<< "p" << i + 1 << ": ";
// //          cin >> executionTime[i];
// //      }
// //      for (i = 0; i < N; i++)
// //      {
// //          for (j = i + 1; j < N; j++)
// //          {
// //              if (executionTime[i] > executionTime[j])
// //              {
// //                  swap(arrTime[i], arrTime[j]);
// //                  swap(executionTime[i], executionTime[j]);
// //              }
// //          }
// //      }

// //     int d;
// //     int minTime = arrTime[0];
// //     for (i = 0; i < N; i++)
// //     {
// //         if (minTime > arrTime[i])
// //         {
// //             minTime = arrTime[i];
// //             d = i;
// //         }
// //     }

// //     int total_time;
// //     int exe[N];
// //     exe[d] = minTime+ executionTime[d];
// //     total_time = exe[d];
// //     for (i = 0; i < N; i++)
// //     {
// //         if (arrTime[i] != minTime)
// //         {
// //             exe[i] = executionTime[i] + total_time;
// //             total_time = exe[i];
// //         }
// //     }
// //     int tat[N], wt[N];
// //     for (i = 0; i < N; i++)
// //     {
// //         tat[i] = exe[i] - arrTime[i];
// //         totalTAT = totalTAT + tat[i];
// //         wt[i] = tat[i] - executionTime[i];
// //         totalWT = totalWT + wt[i];
// //     }

// //     float totalTAT = 0, totalWT = 0;
// //     float avgTAT = 0, avgWT = 0;
// //     avgTAT = totalTAT / N;
// //     avgWT = totalWT / N;

// //     cout << "ProcessID\tArrivalTime\tExecutionTime\tWaitingTime\tTurnAroundTime "<< "\N";
// //     for (i = 0; i < N; i++)
// //     {
// //         cout <<"P:"<<i + 1 << "\t\t " << arrTime[i] << "\t\t " << executionTime[i] << "\t\t" << wt[i] << "\t\t " << tat[i] << "\N";
// //     }
// //     cout << "Hence the Average waiting time is " << avgWT << "\N";
// //     cout << " Hence the Average turn around time is " << avgTAT;

// //     return 0;
// // }

// // Priority
// //  #include <iostream>
// //  using namespace std;

// // int main()
// // {
// //     int N;
// //     cout << "Enter Total Number of Processes: ";
// //     cin >> N;
// //     int Arrival[10], execution[10], priority[10];
// //     int i, j;
// //     for (i = 0; i < N; i++)
// //     {
// //         cout << "Enter the arrival time for process "<< "p" << i + 1 << ": ";
// //         cin >> Arrival[i];
// //     }

// //     for (i = 0; i < N; i++)
// //     {
// //         cout << "Enter the execution time for process "<< "p" << i + 1 << ": ";
// //         cin >> execution[i];
// //     }

// //     for (i = 0; i < N; i++)
// //     {
// //         cout << "Enter the Priority for process "<< "p" << i + 1 << ": ";
// //         cin >> priority[i];
// //     }

// //     int temp[10];

// //     for (i = 0; i < N; i++)
// //     {
// //         temp[i] = execution[i];
// //     }

// //     int Waiting[10], TurnAround[10], completion[10];
// //     double avg = 0, tat = 0, end;
// //     priority[9] = -1;
// //     int count = 0;

// //     for (int time = 0; count != N; time++)
// //     {
// //         int smallest = 9;
// //         for (i = 0; i < N; i++)
// //         {
// //             if (Arrival[i] <= time && priority[i] > priority[smallest] && execution[i] > 0)
// //                 smallest = i;
// //         }
// //         execution[smallest]--;

// //         if (execution[smallest] == 0)
// //         {
// //             count++;
// //             end = time + 1;
// //             completion[smallest] = end;
// //             Waiting[smallest] = end - Arrival[smallest] - temp[smallest];
// //             TurnAround[smallest] = end - Arrival[smallest];
// //         }
// //     }

// //     cout << "ProcessID"<< "\t"<<"Arrival-time"<<"\t"<< "Execution-time"<< "\t"<< "Priority"<< "Waiting-time"<< "\t"<< "TurnAround-time"<< "\t"<< "completion-time"<< "\t"<< "\N";

// //     for (i = 0; i < N; i++)
// //     {
// //         cout << "P" << i + 1 << "\t\t" << Arrival[i] << "\t\t"<<temp[i]  << "\t\t"<< priority[i] <<"\t\t"<<  Waiting[i] << "\t\t" << TurnAround[i] << "\t\t" << completion[i] << "\N";
// //         avg = avg + Waiting[i];
// //         tat = tat + TurnAround[i];
// //     }

// //     cout << "Hence the Average Waiting time is =" << avg / N;
// //     cout << "\nHence the Average Turnaround time =" << tat / N << "\N";
// // }

// // //Round Robin
// // #include <iostream>
// // using namespace std;

// // int main(){
// //  int i,N,time,remain,temps=0,time_quantum;

// //  int wt=0,tat=0;

// //  cout<<"Enter the total number of process="<<endl;
// //  cin>>N;

// //  remain=N;

// //  int at[N];
// //  int bt[N];
// //  int rt[N];

// //  cout<<"Enter the Arrival time, Burst time for All the processes"<<endl;
// //  for(i=0;i<N;i++)
// //  {
// //    cout<<"Arrival time for process "<<i+1<<endl;
// //   cin>>at[i];
// //   cout<<"Burst time for process "<<i+1<<endl;
// //   cin>>bt[i];
// //   rt[i]=bt[i];
// //  }

// //  cout<<"Enter the value of time QUANTUM:"<<endl;
// //  cin>>time_quantum;

// //  cout<<"\N\nProcess\t:Turnaround Time:Waiting Time\N\N";
// //  for(time=0,i=0;remain!=0;)
// //  {
// //   if(rt[i]<=time_quantum && rt[i]>0)
// //   {
// //    time += rt[i];

// //    rt[i]=0;
// //    temps=1;
// //   }

// //   else if(rt[i]>0)
// //   {
// //    rt[i] -= time_quantum;

// //    time += time_quantum;

// //   }

// //   if(rt[i]==0 && temps==1)
// //   {
// //    remain--;

// //    printf("Process{%d}\t:\t%d\t:\t%d\N",i+1,time-at[i],time-at[i]-bt[i]);
// //    cout<<endl;

// //    wt += time-at[i]-bt[i];
// //    tat += time-at[i];
// //    temps=0;
// //   }

// //   if(i == N-1)
// //    i=0;
// //   else if(at[i+1] <= time)
// //    i++;
// //   else
// //    i=0;
// //  }

// //  cout<<"Average waiting time "<<wt*1.0/N<<endl;
// //  cout<<"Average turn around time "<<tat*1.0/N<<endl;;

// //  return 0;
// // }

 def solution (N, A, B){
    // ans = True     
 dict = {}    
  for i in range(0,N):        
  min = Math.min(A[i], B[i])        
  max = Math.max(A[i], B[i])         
  dict[min] = Math.max(min, Math.min(dict[min], max))    
    for i in range (1, N ):     
    {
        if(dict[i] != i +1):        
             return false
    }          
    return True
 
} 
 

#include <bits/stdc++.h>
using namespace std;
int solution(int N, vector<int> &A, vector<int> &B) {
    // bool ans=true;
    int dict[];
    for(int i=0;i<N;i++){
        int mini=min(A[i],B[i]);
        int maxi=max(A[i],B[i]);
    }
    dict[min]=max(min,min(dict[min],max));
    for(int i=0;i<n;i++){
        if(dict[i]!=i+1){
            return false;
        }
    }
    return true;



}