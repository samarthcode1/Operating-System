#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int processes, resources, i, j, k;
    cout << "Enter the number of processes\n";
    cin >> processes;
    cout << "Enter the number of resources\n";
    cin >> resources;
    int allocation[processes][resources];
    cout << "Enter the allocation\n";
    for (int i = 0; i < processes; i++)
    {
        cin >> allocation[i][0] >> allocation[i][1] >> allocation[i][2];
    }
    int maximum[processes][resources];
    cout << "Enter the Maximum-Allocations\n";
    for (int i = 0; i < processes; i++)
    {
        cin >> maximum[i][0] >> maximum[i][1] >> maximum[i][2];
    }
    int avaiable[resources];
    cout << "Enter the available resources\n";
    for (int i = 0; i < resources; i++)
    {
        cin >> avaiable[i];
    }
    int finish[processes], ans[processes], ind = 0;
    for (k = 0; k < processes; k++)
    {
        finish[k] = 0;
    }
    int need[processes][resources];
    for (i = 0; i < processes; i++)
    {
        for (j = 0; j < resources; j++)
            need[i][j] = maximum[i][j] - allocation[i][j];
    }
    cout << "Need Allocations\n";
    for (i = 0; i < processes; i++)
    {
        for (j = 0; j < resources; j++)
        {
            cout << need[i][j] << " ";
        }
        cout << "\n";
    }
    int y = 0;
    for (k = 0; k < processes; k++)
    {
        for (i = 0; i < processes; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < resources; j++)
                {
                    if (need[i][j] > avaiable[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < resources; y++)
                        avaiable[y] += allocation[i][y];
                    finish[i] = 1;
                }
            }
        }
    }
    int flag = 1;
    for (int i = 0; i < processes; i++)
    {
        if (finish[i] == 0)
        {
            flag = 0;
            cout << "The process is not safe,chances of deadlock\n";
            break;
        }
    }
    if (flag == 1)
    {
        cout << "The Safe sequence is for the process is\n";
        cout << "Sequence:\n";
        for (i = 0; i < processes; i++)
        {
            cout << " P->" << ans[i];
        }
    }
    return 0;
}