// // #include <iostream>
// // #include <vector>
// // #include <algorithm>
// // #include <thread>
// // #include <chrono>
// // using namespace std;
// // using namespace std::chrono;

// // int helper(int N, int nums[], int sum, int idx)
// // {
// //     if (idx == N) {
// //         return sum;
// //     }
// //     int picked = helper(N, nums, sum + nums[idx], idx + 1);
// //     int notPicked = helper(N, nums, sum, idx + 1);
// //     return picked + notPicked;
// // }

// // int sumOfSubset(int arr[], int n)
// // {
// //     return helper(n, arr, 0, 0);
// // }

// // void sumOfSubset1(int arr[], int n, int *ans)
// // {
// //     *ans = helper(n, arr, 0, 0);
// // }

// // int main()
// // {
// //     int arr1[] = {4,3,1,7,9,2,5,6,8};
// //     int size1 = 8;
// //     int arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34};
// //     int size2 = 34;
// //     auto startTime1 = high_resolution_clock::now();
// //     int number1 = sumOfSubset(arr1, size1+1);
// //     int number2 = sumOfSubset(arr2, size2+1);
// //     cout<<"ans is: "<<number1<<endl;
// //     cout<<"ans is: "<<number2<<endl;
// //     auto stopTime1 = high_resolution_clock::now();
// //     auto duration1 = duration_cast<microseconds>(stopTime1 - startTime1);
// //     cout<<"Duration without threads is: "<<duration1.count()<<endl;
// //     int number3;
// //     int number4;
// //     auto startTime2 = high_resolution_clock::now();
// //     std::thread FIB1(sumOfSubset1, arr1, size1+1, &(number3));
// //     std::thread FIB2(sumOfSubset1, arr2, size2+1, &(number4));
// //     FIB1.join();
// //     FIB2.join();
// //     cout<<"ans is: "<<number3<<endl;
// //     cout<<"ans is: "<<number4<<endl;
// //     auto stopTime2 = high_resolution_clock::now();
// //     auto duration2 = duration_cast<microseconds>(stopTime2 - startTime2);
// //     cout<<"Duration with threads is: "<<duration2.count()<<endl;
// //     return 0;
// // }

// #include <iostream>
// #include <vector>
// #include <thread>
// #include <chrono>

// std::vector<int> inputSet = {1, 3, 5, 7, 9};
// int targetSum = 12;
// bool foundSubset = false;
// void findSubsetSum(int start, int sumSoFar) {
//     if (sumSoFar == targetSum) {
//         foundSubset = true;
//         return;
//     }

//     if (sumSoFar > targetSum || start >= inputSet.size())
//         return;
//     for (int i = start; i < inputSet.size(); ++i) {
//         findSubsetSum(i + 1, sumSoFar + inputSet[i]);
//         if (foundSubset)
//             return;
//     }
// }

// int main() {
//     std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
//     int numThreads = 4;
//     std::vector<std::thread> threads;
//     int subsetSize = inputSet.size() / numThreads;

//     for (int t = 0; t < numThreads; ++t) {
//         int startIndex = t * subsetSize;
//         int endIndex = (t == numThreads - 1) ? inputSet.size() : (startIndex + subsetSize);
//         threads.emplace_back(findSubsetSum, startIndex, 0);
//     }
//     for (auto& thread : threads) {
//         thread.join();
//     }
//     std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
//     std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
//     if (foundSubset)
//         std::cout << "Subset sum exists!" << std::endl;
//     else
//         std::cout << "Subset sum does not exist." << std::endl;
//     std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;

//     return 0;
// }

// Subset sum exists!
// Execution time: 0.00123456 seconds.

#include <pthread.h>
#include <iostream>
void *ThreadFunc(void *arg)
{
    int threadNum = *(int *)arg;
    std::cout << "Thread " << threadNum << " running..." << std::endl;
    return NULL;
}
int main()
{
    pthread_t thread1, thread2;
    int threadData1 = 1, threadData2 = 2;
    pthread_create(&thread1, NULL, ThreadFunc, &threadData1);
    pthread_create(&thread2, NULL, ThreadFunc, &threadData2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}