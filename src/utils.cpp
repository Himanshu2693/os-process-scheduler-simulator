#include<bits/stdc++.h>
#include "scheduler.h"
#include <fstream>
#include <sstream>
#include <iostream>

void readFromFile(string filename, vector<Process>& processes) {
    ifstream fin(filename);
    int id = 1, at, bt, pr;
    while (fin >> at >> bt >> pr) {
        processes.push_back({id++, at, bt, pr});
    }
}

void writeToFile(string filename, const vector<Process>& processes) {
    ofstream fout(filename);
    for (const auto& p : processes) {
        fout << "P" << p.pid << ": Waiting = " << p.waiting_time 
             << ", Turnaround = " << p.turnaround_time << "\n";
    }
}
