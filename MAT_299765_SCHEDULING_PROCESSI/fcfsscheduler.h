
#ifndef FCFS_SCHEDULER_H
#define FCFS_SCHEDULER_H

#include <iostream>

#include "scheduler.h"
#include "list.h"
#include "queue.h"
#include "process.h"

using namespace std;

class FCFSScheduler : Scheduler {
	
	public:
		
		FCFSScheduler(List<Process>& l) : Scheduler(l) { }
		
		void schedule()
		{
			// creo una coda dei processi da eseguire, rispettando l'ordine in cui sono contenuti.
			// Tale ordine sarà quello usato per eseguire i processi
			Queue<Process> queue(processes);
			
			cout << "[First Come First Served Scheduler] Ordine di esecuzione dei processi: " << endl;
			while (!queue.isEmpty())
			{
				cout << queue.remove() << endl;
			}
		}
};

#endif
