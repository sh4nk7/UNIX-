
#ifndef SJF_SCHEDULER_H
#define SJF_SCHEDULER_H

#include <iostream>

#include "scheduler.h"
#include "list.h"
#include "queue.h"
#include "process.h"

using namespace std;

class SJFScheduler : Scheduler {
	
	public:
		
		SJFScheduler(List<Process>& l) : Scheduler(l) { }
		
		void schedule()
		{
			int numProcesses = processes.size();
			Process array[numProcesses];
			int i = 0;
			// scorro lungo la lista dei processi, per inserire tutti i processi in un array e successivamente ordinarli in modo crescente
			// rispetto ai rispettivi cpu burst. Tale ordine rappresenterà quello di esecuzione dei processi
			for (processes.moveToStart(); processes.hasNext(); processes.next())
			{
				array[i] = processes.getValue();
				i++;
			}
			
			int pos_min;
			Process p;
			//ordino l'array
			for (i = 0; i < processes.size() - 1; i++)
			{
				pos_min = i;
				for (int j = i + 1; j < processes.size(); j++)
				{
					if (array[j].getCpuBurst() < array[pos_min].getCpuBurst())
						pos_min = j;
				}
				
				if (pos_min != i)
				{
					p = array[i];
					array[i] = array[pos_min];
					array[pos_min] = p;
				}
			}
			
			// una volta ordinati, inserisco i processi in una coda, pronti per essere eseguiti
			Queue<Process> priorityQueue;
			for (i = 0; i < processes.size(); i++)
			{
				priorityQueue.add(array[i]);
			}
			
			cout << "[Shortest Job First] Ordine di esecuzione dei processi: " << endl;
			while (!priorityQueue.isEmpty())
			{
				cout << priorityQueue.remove() << endl;
			}
			
		};		
};

#endif
