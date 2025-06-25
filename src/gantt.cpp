#include<bits/stdc++.h>
#include "scheduler.h"
#include <iostream>
using namespace std;

void printGanttChart(const vector<Process>& processes) {
    cout << "\nGantt Chart:\n|";
    for (const auto& p : processes)
        cout << " P" << p.pid << " |";
    cout << "\n";

    cout << processes.front().start_time;
    for (const auto& p : processes)
        cout << "\t" << p.completion_time;
    cout << "\n";
}
