
#ifndef PRIORITY_SCHEDULER_H
#define PRIORITY_SCHEDULER_H

#include <iostream>

#include "scheduler.h"
#include "list.h"
#include "queue.h"
#include "process.h"

using namespace std;

class PriorityScheduler : Scheduler
{
	public:
		
		PriorityScheduler(List<Process>& l) : Scheduler(l) { }
		
		void schedule()
		{
			//creo una seconda lista di tutti i processi, che userò per eseguirli
			List<Process> remainingProcesses(processes);
			int max_priority;
			
			//lista di code: in essa verrà inserita una coda per ogni priorità che compare nella lista dei processi e conterrà
			//tutti i processi che hanno quella priorità
			List< Queue<Process> > queues;
			//prelevo dalla lista i processi da eseguire per inserirli nelle varie code di priorità.
			//Creo di volta in volta una nuova coda di priorità in cui inserire tutti i processi che hanno la priorità più alta 
			//(valori inferiori di priorità denotano una priorità maggiore)
			while (!remainingProcesses.isEmpty())
			{
				Queue<Process> q;
				//scorro la lista per trovare la priorità più alta tra i processi da eseguire
				remainingProcesses.moveToStart();
				max_priority = remainingProcesses.getValue().getPriority();
				for (remainingProcesses.next(); remainingProcesses.hasNext(); remainingProcesses.next())
				{
					//se il processo corrente ha una priorità maggiore (quindi un valore inferiore), la sua priorità è la nuova
					//priorità massima
					if (remainingProcesses.getValue().getPriority() < max_priority)
						max_priority = remainingProcesses.getValue().getPriority();
				}
				//creo una coda di tutti i processi con la priorità più alta per eseguirli, rimuovendoli al tempo stesso
				//dalla lista dei processi ancora da eseguire
				remainingProcesses.moveToStart();
				while (remainingProcesses.hasNext())
				{
					if (remainingProcesses.getValue().getPriority() == max_priority)
					{
						q.add(remainingProcesses.getValue());
						remainingProcesses.removeCurr();
					}
					else
						remainingProcesses.next();
				}
				//la coda di priorità creata, la aggiungo a quelle già create
				queues.append(q);
			}
			
			cout << "[Priority] Ordine di esecuzione dei processi: " << endl;
			//eseguo tutti i processi di una coda dopo l'altra, partendo da quella che la priorità più alta
			for (queues.moveToStart(); queues.hasNext(); queues.next())
			{
				Queue<Process>& queue = queues.getValue();
				while (!queue.isEmpty())
				{
					cout << queue.remove() << endl;
				}
			}
			cout << "[Numero code di priorita' create: " << queues.size() << "]" << endl;
		}
};

#endif
