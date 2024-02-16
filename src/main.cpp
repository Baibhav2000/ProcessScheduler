#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "process.h"
#include "scheduler.h"

std::vector<std::vector<std::string>> readCSV(const std::string &filename){
	std::ifstream file(filename);
	std::vector<std::vector<std::string>> data;
	std::string line;

	while(std::getline(file, line)){
		std::vector<std::string> row;
		std::stringstream ss(line);
		std::string cell;

		while (std::getline(ss, cell, ',')) {
			row.push_back(cell);
		}

		data.push_back(row);
	}

	return data;
}

int main(){

	std::vector<std::vector<std::string>> csv_data = readCSV("../data/process_data.csv");

	std::vector<Process> processes;

	for(int i=0; i < csv_data.size(); i++){
		Process process;
		process.setProcessID(i);
		process.setArrivalTime(std::stoi(csv_data[i][0]));
		process.setBurstTime(std::stoi(csv_data[i][1]));
		processes.push_back(process);
	}

	Scheduler fcfsScheduler = Scheduler(processes, FCFS);
	fcfsScheduler.schedule();
	fcfsScheduler.results();

	Scheduler roundRobinScheduler = Scheduler(processes, ROUND_ROBIN);
	roundRobinScheduler.schedule();
	roundRobinScheduler.results();

	Scheduler sjfScheduler = Scheduler(processes, SJF);
	sjfScheduler.schedule();
	sjfScheduler.results();

	Scheduler srtfScheduler = Scheduler(processes, SRTF);
	srtfScheduler.schedule();
	srtfScheduler.results();

	return 0;
}

