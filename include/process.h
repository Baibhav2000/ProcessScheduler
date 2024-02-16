#ifndef PROCESS_H
#define PROCESS_H

/***********************************************************************
 * @brief Representation of a process
************************************************************************/
class Process{

	private:

		int processID;
		int arrivalTime;
		int burstTime;
		int completionTime;
		int turnaroundTime;
		int waitingTime;
		int responseTime;

	public:

		/***************************************************************************************
		 * @brief Instantiates object with initial attribute values
		****************************************************************************************/
		Process();


		/***************************************************************************************
		 * @brief Sets process ID
		 * 
		 * @param[in] processID An identification number of a process
		****************************************************************************************/
		void setProcessID(int processID);


		/***************************************************************************************
		 * @brief Sets process arrival time
		 * 
		 * @param[in] arrivalTime Arrival time of a process
		****************************************************************************************/
		void setArrivalTime(int arrivalTime);


		/***************************************************************************************
		 * @brief Sets Burst Time of process
		 * 
		 * @param[in]  arrivalTime Burst Time of process
		****************************************************************************************/
		void setBurstTime(int burstTime);
		

		/***************************************************************************************
		 * @brief Sets Completion Time of process
		 * 
		 * @param[in]  completionTime Completion Time of process
		****************************************************************************************/
		void setCompletionTime(int completionTime);


		/***************************************************************************************
		 * @brief Sets Turnaround Time of the process
		 * 
		 * @param[in] turnaroundTime Turnaround Time of the process
		****************************************************************************************/
		void setTurnaroundTime(int turnaroundTime);


		/***************************************************************************************
		 * @brief Sets Waiting Time of process
		 * 
		 * @param[in] waitingTime Waiting Time of process
		****************************************************************************************/
		void setWaitingTime(int waitingTime);


		/***************************************************************************************
		 * @brief Sets Response Time of process
		 * 
		 * @param[in] responseTime Response Time of process
		****************************************************************************************/
		void setResponseTime(int responseTime);


		/***************************************************************************************
		 * @brief Fetches Process ID
		 * 
		 * @return Process ID
		****************************************************************************************/
		int getProcessID() const;


		/***************************************************************************************
		 * @brief Fetches arrival Time
		 * 
		 * @return arrival time
		****************************************************************************************/
		int getArrivalTime() const;


		/***************************************************************************************
		 * @brief Fetches Burst Time
		 * 
		 * @return Burst time
		****************************************************************************************/
		int getBurstTime() const;
		

		/***************************************************************************************
		 * @brief Fetches Completion Time
		 *
		 * @return Completion Time
		****************************************************************************************/
        int getCompletionTime();


		/***************************************************************************************
		 * @brief Fetches Turnaround Time
		 *
		 * @return Turnaround Time
		****************************************************************************************/
        int getTurnaroundTime();


		/***************************************************************************************
		 * @brief Fetches Waiting Time
		 *
		 * @return Waiting Time
		****************************************************************************************/
	    int getWaitingTime();
		

		/***************************************************************************************
		 * @brief Fetches Response Time
		 *
		 * @return Response Time
		****************************************************************************************/ 
        int getResponseTime();

};

#endif