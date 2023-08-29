#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

class waitForGraph
{
    unordered_map<int, unordered_set<int>> graph;

public:
    void insertEdge(int from, int to)
    {
        graph[from].insert(to);
    }
    bool checkDeadlock()
    {
        vector<int> inDegrees(graph.size(), 0);
        for (const auto &i : graph)
        {
            for (int dependency : i.second)
            {
                inDegrees[dependency]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < inDegrees.size(); i++)
        {
            if (inDegrees[i] == 0)
            {
                q.push(i);
            }
        }
        int processedNodes = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            processedNodes++;
            for (int dependency : graph[node])
            {
                if (--inDegrees[dependency] == 0)
                {
                    q.push(dependency);
                }
            }
        }
        return processedNodes != graph.size();
    }
};

int main()
{
    waitForGraph graph;
    graph.insertEdge(0, 1);
    graph.insertEdge(1, 2);
    graph.insertEdge(2, 0);
    if (graph.checkDeadlock())
    {
        cout << "Hence Deadlock is Detected for the graph\n";
        cout << "21bct0157";
    }
    else
    {
        cout << "Hence Deadlock is not Detected for the graph.\n";
        cout << "21bct0157";
    }
    return 0;
}