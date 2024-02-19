#include <iostream>
#include <algorithm>
#include "scheduler.h"

int timeQuantum = 5;

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
		int responseTime = processes[i].getWaitingTime();
		processes[i].setResponseTime(responseTime);
	}
}

void Scheduler::roundRobinScheduling(){

	std::sort(this->processes.begin(), this->processes.end(), compareByArrivalTime);
	std::vector<int> remainingBurst;

	for(int i=0; i < this->processes.size(); i++){
		remainingBurst.push_back(this->processes[i].getBurstTime());
	}

	int currTimestamp = 0;

	while(1){
		
		bool done = true;

		for(int i=0; i < this->processes.size(); i++){
			if(remainingBurst[i] > 0){

				done = false; //Pending process

				if(this->processes[i].getArrivalTime() >= currTimestamp){
					currTimestamp = this->processes[i].getArrivalTime();
				}
				// Scheduled for the first time
				if(remainingBurst[i] == this->processes[i].getBurstTime()){
					this->processes[i].setResponseTime(currTimestamp - this->processes[i].getArrivalTime());
				}

				if(remainingBurst[i] > timeQuantum){
					remainingBurst[i] -= timeQuantum;
					currTimestamp += timeQuantum;
				}
				else{
					currTimestamp += remainingBurst[i];
					this->processes[i].setCompletionTime(currTimestamp);
					remainingBurst[i] = 0;
				}
			}
		}
		
		if(done)
			break;
	}

	std::sort(this->processes.begin(), this->processes.end(), compareByProcessID);

	for(int i=0; i < this->processes.size(); i++){
		this->processes[i].setTurnaroundTime(this->processes[i].getCompletionTime() - this->processes[i].getArrivalTime());
		this->processes[i].setWaitingTime(this->processes[i].getTurnaroundTime() - this->processes[i].getBurstTime());
	}
}

void Scheduler::sjfScheduling(){
	std::sort(this->processes.begin(), this->processes.end(), compareByArrivalTime);

	std::vector<int> remainingBurst;

	for(auto process: this->processes){
		remainingBurst.push_back(process.getBurstTime());
	}
	int currTimestamp = this->processes[0].getArrivalTime();

	

	while(1){
		int minBurst = INT32_MAX;
		int minBurstIdx = -1;
		for(int i=0; i < this->processes.size(); i++){
			if(remainingBurst[i] > 0){
				if(this->processes[i].getBurstTime() < minBurst && this->processes[i].getArrivalTime() <= currTimestamp){
					minBurst = this->processes[i].getBurstTime();
					minBurstIdx = i;
				}
			}
		}

		if(minBurstIdx == -1)
			break;

		remainingBurst[minBurstIdx] = 0;
		this->processes[minBurstIdx].setResponseTime(currTimestamp - this->processes[minBurstIdx].getArrivalTime());
		currTimestamp += this->processes[minBurstIdx].getBurstTime();
		this->processes[minBurstIdx].setCompletionTime(currTimestamp);

	}

	std::sort(this->processes.begin(), this->processes.end(), compareByProcessID);

	for(int i=0; i < this->processes.size(); i++){
		this->processes[i].setTurnaroundTime(this->processes[i].getCompletionTime() - this->processes[i].getArrivalTime());
		this->processes[i].setWaitingTime(this->processes[i].getTurnaroundTime() - this->processes[i].getBurstTime());
	}
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
			std::cout<<"FCFS Scheduling results :"<<std::endl;
			std::cout<<"-------------------------"<<std::endl<<std::endl;
			break;
		
		case ROUND_ROBIN:
			std::cout<<"Round Robin Scheduling results(Time Quantum = "<<timeQuantum<<") :"<<std::endl;
			std::cout<<"--------------------------------------------------"<<std::endl<<std::endl;
			break;

		case SJF:
			std::cout<<"Shortest Job First Scheduling results :"<<std::endl;
			std::cout<<"---------------------------------------"<<std::endl<<std::endl;
			break;

		case SRTF:
			std::cout<<"Shortest Remaining Time First Scheduling results :"<<std::endl;
			std::cout<<"--------------------------------------------------"<<std::endl<<std::endl;
			break;			
	}

	std::cout<<"+------------+--------------+------------+-----------------+-----------------+--------------+---------------+"<<std::endl;	

	std::cout<<"| Process ID |";
	std::cout<<" Arrival Time |";
	std::cout<<" Burst Time |";
	std::cout<<" Completion Time |";
	std::cout<<" Turnaround Time |";
	std::cout<<" Waiting Time |";
	std::cout<<" Response Time |"<<std::endl;

	std::cout<<"+------------+--------------+------------+-----------------+-----------------+--------------+---------------+"<<std::endl;

	int totalTurnaroundTime = 0;
	int totalWaitingTime = 0;
	int totalResponseTime = 0;

	int numSpaces = 0;
	for(auto process: this->processes){
		std::cout<<"| "<<process.getProcessID();

		numSpaces = 12 - (1 + std::to_string(process.getProcessID()).length());

		for(int i = 0; i < numSpaces; i++)
			std::cout<<" ";
		

		std::cout<<"| "<<process.getArrivalTime();
		numSpaces = 14 - (1 + std::to_string(process.getArrivalTime()).length());

		for(int i = 0; i < numSpaces; i++)
			std::cout<<" ";

		std::cout<<"| "<<process.getBurstTime();
		numSpaces = 12 - (1 + std::to_string(process.getBurstTime()).length());

		for(int i = 0; i < numSpaces; i++)
			std::cout<<" ";

		std::cout<<"| "<<process.getCompletionTime();
		numSpaces = 17 - (1 + std::to_string(process.getCompletionTime()).length());

		for(int i = 0; i < numSpaces; i++)
			std::cout<<" ";
		std::cout<<"| "<<process.getTurnaroundTime();
		numSpaces = 17 - (1 + std::to_string(process.getTurnaroundTime()).length());

		for(int i = 0; i < numSpaces; i++)
			std::cout<<" ";
		std::cout<<"| "<<process.getWaitingTime();
		numSpaces = 14- (1 + std::to_string(process.getWaitingTime()).length());

		for(int i = 0; i < numSpaces; i++)
			std::cout<<" ";

		std::cout<<"| "<<process.getResponseTime();
		numSpaces = 15- (1 + std::to_string(process.getWaitingTime()).length());

		for(int i = 0; i < numSpaces; i++)
			std::cout<<" ";
		
		std::cout<<"|"<<std::endl;
		

		totalTurnaroundTime += process.getTurnaroundTime();
		totalWaitingTime += process.getWaitingTime();
		totalResponseTime += process.getResponseTime();

		std::cout<<"+------------+--------------+------------+-----------------+-----------------+--------------+---------------+"<<std::endl;
	}

	

	float avgTurnaroundTime = (float)(totalTurnaroundTime) / (float)(processes.size());
	float avgWaitingTime = (float)(totalWaitingTime) / (float)(processes.size());
	float avgResponseTime = (float)(totalResponseTime) / (float)(processes.size());

	std::cout<<"Average Turnaround Time : "<<avgTurnaroundTime<<std::endl;
	std::cout<<"Average Waiting Time : "<<avgWaitingTime<<std::endl;
	std::cout<<"Average Response Time : "<<avgResponseTime<<std::endl<<std::endl;
	
}
