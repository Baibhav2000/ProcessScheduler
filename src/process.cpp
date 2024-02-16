#include "process.h"

Process::Process(){
	this->responseTime = 0;
	this->waitingTime = 0;
	this->completionTime = 0;
	this->turnaroundTime = 0;
}

void Process::setProcessID(int processID){
	this->processID = processID;
}

int Process::getProcessID() const{
	return this->processID;
}

void Process::setArrivalTime(int arrivalTime){
	this->arrivalTime = arrivalTime;
}

int Process::getArrivalTime() const{
	return this->arrivalTime;
}

void Process::setBurstTime(int burstTime){
	this->burstTime = burstTime;
}

int Process::getBurstTime() const{
	return this->burstTime;
}

void Process::setCompletionTime(int completionTime){
	this->completionTime = completionTime;
}

int Process::getCompletionTime(){
	return this->completionTime;
}

void Process::setTurnaroundTime(int turnaroundTime){
	this->turnaroundTime = turnaroundTime;
}

int Process::getTurnaroundTime(){
	return this->turnaroundTime;
}

void Process::setWaitingTime(int waitingTime){
	this->waitingTime = waitingTime;
}

int Process::getWaitingTime(){
	return this->waitingTime = waitingTime;
}

void Process::setResponseTime(int responseTime){
	this->responseTime = responseTime;
}

int Process::getResponseTime(){
	return this->responseTime;
}
