#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;
const int Total_philosopher = 5;
mutex forks[Total_philosopher];
void philosopher(int number)
{
    int right_fork = (number + 1) % Total_philosopher;
    int left_fork = number;
    while (true)
    {
        cout << "Philosopher" << number << " is Currently Thinking.\n";
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "Philosopher" << number << " is hungry and planning to pick up the forks.\n";
        lock(forks[left_fork], forks[right_fork]);
        cout << "Philosopher" << number << " picked the "<<left_fork << " forks" <<  " and " << right_fork << " and started eating.\n";
        this_thread::sleep_for(chrono::milliseconds(2000));
        forks[right_fork].unlock();
        forks[left_fork].unlock();
        cout << "Philosopher" << number << " finished eating and put down forks" << left_fork << " and " << right_fork << "." << "\n";
    }
}
int main()
{
    thread p[Total_philosopher];
    cout<<"21BCT0157\n";
    for (int i = 0; i < Total_philosopher; ++i)
    {
        p[i] = thread(philosopher, i);
    }
    for (int i = 0; i < Total_philosopher; i++)
    {
        p[i].join();
    }
    return 0;
}