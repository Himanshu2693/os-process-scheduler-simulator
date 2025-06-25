#ifndef SCHEDULER_H
#define SCHEDULER_H
#include<bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;

    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void fcfs(vector<Process>& processes);
void sjf(vector<Process>& processes);
void priority_scheduling(vector<Process>& processes);
void round_robin(vector<Process>& processes, int quantum);
void calculateTimes(vector<Process>& processes);
void printGanttChart(const vector<Process>& processes);
void readFromFile(string filename, vector<Process>& processes);
void writeToFile(string filename, const vector<Process>& processes);

#endif
