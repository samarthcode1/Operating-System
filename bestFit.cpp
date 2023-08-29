BESTFIT Segmentation
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bestFit(int blockSize[],int m,int processSize[],int n){
    int allocation[n];
    memset(allocation ,-1,sizeof(allocation));
    for(int i=0;i<m;i++){
        int bestIndex=-1;
        for(int j=0;j<m;j++){
            if(blockSize[j]>=processSize[i]){
                if(bestIndex==-1){
                    bestIndex=j;
                }
                else if(blockSize[bestIndex]>blockSize[j]){
                    bestIndex=j;
                }
            }
        }
        if(bestIndex!=-1){
            allocation[i]=bestIndex;
            blockSize[bestIndex]-=processSize[i];
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{
    int m;
    cout << "Enter the total number of Blocks\n";
    cin >> m;
    int blockSize[m];
    for (int i = 0; i < m; i++)
    {
        cin >> blockSize[i];
    }
    int n;
    cout << "Enter the total number of processes\n";
    cin >> n;
    int processSize[n];
    for (int i = 0; i < n; i++)
    {
        cin >> processSize[i];
    }
    bestFit(blockSize, m, processSize, n);
    return 0;
}