#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
void FirstFitPaging(vector<int> blockSize, int n, int m, vector<int> Processes)
{
    int allocation[m];
    int filled[n];
    memset(allocation, -1, sizeof(allocation));
    for (int i = 0; i < n; i++)
    {
        filled[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)

        {
            if (!filled[j] && blockSize[j] >= Processes[i])
            {
                allocation[i] = j;
                filled[j] = 1;
                break;
            }
        }
    }
    cout << "\nProcesses\t Process Size\t\t Blocks Size\n";
    for (int i = 0; i < m; i++)
    {
        cout << i + 1 << "\t\t" << Processes[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1 << "\n";
        else
            cout << "NA"<< "\n";
    }
}
void FirstFitSegmentaion(vector<int> blockSize, int n, int m, vector<int> Processes)
{
    int allocation[m];
    memset(allocation, -1, sizeof(allocation));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (blockSize[j] >= Processes[i])
            {
                allocation[i] = j;
                blockSize[j] -= Processes[i];
                break;
            }
        }
    }
    cout << "\nProcesses\t Process Size\t\t Blocks Size\n";
    for (int i = 0; i < m; i++)
    {
        cout << i + 1 << "\t\t" << Processes[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1 << "\n";
        else
            cout << "NA"<< "\n";
    }
}

int main()
{
    int n;
    cout << "Enter number of Blocks\n ";
    cin >> n;
    int m;
    cout << "Enter number of Processes\n ";
    cin >> m;
    vector<int> Processes;
    vector<int> blockSize;
    cout << "Enter Block Size\n ";
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        blockSize.push_back(b);
    }
    cout << "Enter the process sizes: ";
    for (int i = 0; i < m; i++)
    {
        int p;
        cin >> p;
        Processes.push_back(p);
    }
    cout << "WORST FIT SEGMENTATION TABLE:";
    worstFitSegmentation(blockSize, n, m, Processes);
    cout << "\n";
    return 0;
}