#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "process.h"

/***************************************************************************
 * @brief An enumeration representing type
 * scheduling algorithm used
 ***************************************************************************/
typedef enum SchedulingType{
	FCFS,
	ROUND_ROBIN,
	SJF,
	SRTF
}SchedulingType;

class Scheduler{
	private:
		
		std::vector<Process> processes;		// Array of processses
		SchedulingType schedulingType;		// Type of scheduling algorithm used

		/**********************************************************************
		 * @brief Performs FCFS Scheduling
		 **********************************************************************/
		void fcfsScheduling();


		/**********************************************************************
		 * @brief Performs Round Robin Scheduling
		 **********************************************************************/
		void roundRobinScheduling();

		/***********************************************************************
		 * @brief Performs Shortest Job First Scheduling
		 ***********************************************************************/
		void sjfScheduling();

		/***********************************************************************
		 * @brief Performs Shortest Remaining Time First Scheduling
		 ***********************************************************************/
		void srtfScheduling();

	public:

		/**********************************************************************
		 * @brief Instantiates Scheduler instance
		 *
		 * @param[in,out] processes An array of processes to be scheduled
		 *
		 * @param[in] schedulingType Type of scheduling algorithm to be used
		 **********************************************************************/
		 Scheduler(std::vector<Process> processes, SchedulingType schedulingType);


		/***********************************************************************
		 * @brief Schedules the processes
		 ***********************************************************************/
		void schedule();


		/*************************************************************
		 * @brief Displays results after scheduling is done
		 * ***********************************************************/
		void results();


};
#endif