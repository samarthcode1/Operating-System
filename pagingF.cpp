#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main()
{
    int total_space;
    cout << "Enter the Total Space of memory: ";
    cin >> total_space;
    vector<double> memory(total_space, 0.00);
    int rem = total_space;
    vector<vector<int>> page_table;
    while (true)
    {
        double cap;
        cout << "Enter the space for block: ";
        cin >>cap;
        if (cap > rem)
        {
            cout << "Cannot assign this much memory" << "\n";
            cout << "Total space remaining: " << rem << "\n";
            break;
        }
        int pages = ceil(cap);
        double perPage = cap / pages;
        vector<int> pagetable(pages, -1);
        bool broken = false;
        for (int i = 0; i < pages; i++)
        {
            int index = rand() % total_space;
            int count = 1;
            while (true)
            {
                count++;
                if (memory[index] < 1.00)
                {
                    double left = 1.00 - memory[index];
                    if (left >= perPage)
                    {
                        memory[index] += perPage;
                        pagetable[i] = index;
                        break;
                    }
                }
                index = rand() % total_space;
                if (count == 10000)
                {
                    broken = true;
                    break;
                }
            }
            if (broken)
                {
                    break;
                }
        }
        page_table.push_back(pagetable);
        for (int i = 0; i < pages; i++)
        {
            if (pagetable[i] == -1)
            {
                cout << "External Segmentation Fault has occured Memory is full " << "\n";
                    broken = true;
                break;
            }
        }
        if (broken)
        {
            break;
        }
        rem -= cap;
    }

    cout << "\n"
         << "\n";
    cout << "Final Allocation: \n";
    for (int i = 0; i < total_space; i++)
    {
        cout << "Block " << i << " has: " << memory[i] << " space stored." << "\n";
    }
    cout << "\n"<< "\n";

    int count = 0;
    for (int i = 0; i < page_table.size(); i++)
    {
        cout<< "The page table for Block: " << (i + 1) << "\n";
        for (int j = 0; j < page_table[i].size(); j++)
        {
            cout << "Page " << (j + 1) << " is mapped to space : "<<page_table[i][j]<<"\n";
        }
        cout << "\n";
    }
    return 0;
}