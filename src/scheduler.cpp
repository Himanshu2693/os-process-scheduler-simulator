#include<bits/stdc++.h>
#include "scheduler.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <climits>
#include<vector>


bool sortByArrival(Process a, Process b) {
    return a.arrival_time < b.arrival_time;
}

void fcfs(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), sortByArrival);
    int current_time = 0;

    for (auto& p : processes) {
        p.start_time = max(current_time, p.arrival_time);
        p.completion_time = p.start_time + p.burst_time;
        current_time = p.completion_time;
        p.turnaround_time = p.completion_time - p.arrival_time;
        p.waiting_time = p.turnaround_time - p.burst_time;
    }
}

void sjf(vector<Process>& processes) {
    int n = processes.size(), completed = 0, current_time = 0;
    vector<bool> is_done(n, false);

    while (completed < n) {
        int idx = -1;
        int min_bt = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!is_done[i] && processes[i].arrival_time <= current_time && processes[i].burst_time < min_bt) {
                min_bt = processes[i].burst_time;
                idx = i;
            }
        }

        if (idx != -1) {
            processes[idx].start_time = current_time;
            processes[idx].completion_time = current_time + processes[idx].burst_time;
            current_time = processes[idx].completion_time;
            processes[idx].turnaround_time = processes[idx].completion_time - processes[idx].arrival_time;
            processes[idx].waiting_time = processes[idx].turnaround_time - processes[idx].burst_time;
            is_done[idx] = true;
            completed++;
        } else {
            current_time++; // Idle time
        }
    }
}

void priority_scheduling(vector<Process>& processes) {
    int n = processes.size(), completed = 0, current_time = 0;
    vector<bool> is_done(n, false);

    while (completed < n) {
        int idx = -1;
        int highest_priority = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!is_done[i] && processes[i].arrival_time <= current_time && processes[i].priority < highest_priority) {
                highest_priority = processes[i].priority;
                idx = i;
            }
        }

        if (idx != -1) {
            processes[idx].start_time = current_time;
            processes[idx].completion_time = current_time + processes[idx].burst_time;
            current_time = processes[idx].completion_time;
            processes[idx].turnaround_time = processes[idx].completion_time - processes[idx].arrival_time;
            processes[idx].waiting_time = processes[idx].turnaround_time - processes[idx].burst_time;
            is_done[idx] = true;
            completed++;
        } else {
            current_time++; // Idle time
        }
    }
}

void round_robin(vector<Process>& processes, int quantum) {
    int n = processes.size();
    vector<int> remaining_burst(n);
    vector<bool> is_started(n, false);
    int current_time = 0, completed = 0;

    for (int i = 0; i < n; i++)
        remaining_burst[i] = processes[i].burst_time;

    while (completed < n) {
        bool did_process = false;

        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0 && processes[i].arrival_time <= current_time) {
                did_process = true;

                if (!is_started[i]) {
                    processes[i].start_time = max(current_time, processes[i].arrival_time);
                    is_started[i] = true;
                }

                int exec_time = min(quantum, remaining_burst[i]);
                current_time = max(current_time, processes[i].arrival_time) + exec_time;
                remaining_burst[i] -= exec_time;

                if (remaining_burst[i] == 0) {
                    processes[i].completion_time = current_time;
                    processes[i].turnaround_time = current_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    completed++;
                }
            }
        }

        if (!did_process) current_time++; // CPU is idle
    }
}

void printGanttChart(const vector<Process>& processes) {
    cout << "\nGantt Chart:\n";
    cout << "|";

    for (const auto& p : processes)
        cout << " P" << p.pid << " |";
    cout << "\n";

    cout << processes[0].start_time;
    for (const auto& p : processes)
        cout << "\t" << p.completion_time;
    cout << "\n";
}