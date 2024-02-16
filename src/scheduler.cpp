#include <iostream>
#include <algorithm>
#include "scheduler.h"

Scheduler::Scheduler(std::vector<Process> processes, SchedulingType schedulingType){
	this->processes = processes;
	this->schedulingType = schedulingType;
}

int compareByArrivalTime(const Process &a, const Process &b){
	return a.getArrivalTime() < b.getArrivalTime();
}

int compareByProcessID(const Process &a, const Process &b){
	return a.getProcessID() < b.getProcessID();
}

void Scheduler::fcfsScheduling(){
	std::sort(this->processes.begin(), this->processes.end(), compareByArrivalTime);
	
	int currCompletionTime = 0;
	for(int i=0; i < processes.size(); i++){
		if(i == 0 || currCompletionTime <= processes[i].getArrivalTime())
		 	currCompletionTime = processes[i].getArrivalTime();

		currCompletionTime += processes[i].getBurstTime();
		processes[i].setCompletionTime(currCompletionTime);
	}

	std::sort(this->processes.begin(), this->processes.end(), compareByProcessID);

	for(int i=0; i < processes.size(); i++){
		int turnaroundTime = processes[i].getCompletionTime() - processes[i].getArrivalTime();
		processes[i].setTurnaroundTime(turnaroundTime);
		int waitingTime = processes[i].getTurnaroundTime() - processes[i].getBurstTime();
		processes[i].setWaitingTime(waitingTime);
	}
}

void Scheduler::roundRobinScheduling(){
	
}

void Scheduler::sjfScheduling(){

}

void Scheduler::srtfScheduling(){

}

void Scheduler::schedule(){
	
	switch(this->schedulingType){
		case FCFS:
			this->fcfsScheduling();
			break;

		case ROUND_ROBIN:
			this->roundRobinScheduling();
			break;
		
		case SJF:
			this->sjfScheduling();
			break;

		case SRTF:
			this->srtfScheduling();
			break;

	}
}

void Scheduler::results(){
	std::cout<<std::endl;
	switch(this->schedulingType){
		case FCFS:
			std::cout<<"FCFS Scheduling results : "<<std::endl<<std::endl;
			break;
		
		case ROUND_ROBIN:
			std::cout<<"Round Robin Scheduling results : "<<std::endl<<std::endl;
			break;

		case SJF:
			std::cout<<"Shortest Job First Scheduling results : "<<std::endl<<std::endl;
			break;

		case SRTF:
			std::cout<<"Shortest Remaining Time First Scheduling results : "<<std::endl<<std::endl;
			break;			
	}

	

	std::cout<<"Process ID";
	std::cout<<" Arrival Time";
	std::cout<<" Burst Time";
	std::cout<<" Completion Time";
	std::cout<<" Turnaround Time";
	std::cout<<" Waiting Time"<<std::endl;

	int totalTurnaroundTime = 0;
	int totalWaitingTime = 0;

	for(auto process: this->processes){
		std::cout<<process.getProcessID();
		std::cout<<"\t\t"<<process.getArrivalTime();
		std::cout<<"\t\t"<<process.getBurstTime();
		std::cout<<"\t\t"<<process.getCompletionTime();
		std::cout<<"\t\t"<<process.getTurnaroundTime();
		std::cout<<"\t\t"<<process.getWaitingTime()<<std::endl;

		totalTurnaroundTime += process.getTurnaroundTime();
		totalWaitingTime += process.getWaitingTime();
	}

	float avgTurnaroundTime = (float)(totalTurnaroundTime) / (float)(processes.size());
	float avgWaitingTime = (float)(totalWaitingTime) / (float)(processes.size());

	std::cout<<"Average Turnaround Time : "<<avgTurnaroundTime<<std::endl;
	std::cout<<"Average Waiting Time : "<<avgWaitingTime<<std::endl<<std::endl;
	
}