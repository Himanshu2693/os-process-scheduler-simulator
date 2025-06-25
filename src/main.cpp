#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include "scheduler.h"

using namespace std;

int main() {
    vector<Process> processes;
    int choice, quantum;

    readFromFile("data/input.txt", processes);

    cout << "CPU Scheduling Algorithms:\n1. FCFS\n2. SJF\n3. Priority\n4. Round Robin\nChoose: ";
    cin >> choice;

    switch (choice) {
        case 1:
            fcfs(processes);
            break;
        case 2:
            sjf(processes);
            break;
        case 3:
            priority_scheduling(processes);
            break;
        case 4:
            cout << "Enter quantum: ";
            cin >> quantum;
            round_robin(processes, quantum);
            break;
        default:
            cout << "Invalid choice\n";
            return 1;
    }

    printGanttChart(processes);
    writeToFile("data/output.txt", processes);

    return 0;
}
