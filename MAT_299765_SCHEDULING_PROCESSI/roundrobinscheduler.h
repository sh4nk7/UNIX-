
#ifndef ROUND_ROBIN_SCHEDULER_H
#define ROUND_ROBIN_SCHEDULER_H

#include <iostream>

#include "scheduler.h"
#include "list.h"
#include "queue.h"
#include "process.h"

using namespace std;

class RoundRobinScheduler : Scheduler
{
	private:
		int round_robin;
		
	public:
		
		RoundRobinScheduler(List<Process>& l, int rr) : round_robin(rr), Scheduler(l) { }
		
		void schedule()
		{
			Queue<Process> processiRimanenti(processes);
			
			cout << "[Round Robin] Ordine di esecuzione dei processi: " << endl;
			//finchè la coda dei processi da eseguire non è vuota, eseguo un suo processo per volta,
			//prelevandolo dalla coda
			while (!processiRimanenti.isEmpty())
			{
				//ricavo il prossimo processo da eseguire rimuovendolo dalla coda
				Process p = processiRimanenti.remove();
				//lo eseguo per il tempo dato dal round_robin (tale valore verrà sottratto al cpu burst rimanente del processo)
				p.execute(round_robin);
				cout << p.getName();
				cout << " [Cpu burst rimanente: " << p.getCpuBurst();
				//dopo averlo eseguito, se gli rimane cpu burst, lo reinserisco nella coda
				if (p.getCpuBurst() > 0)
					processiRimanenti.add(p);
				//altrimenti la sua esecuzione è completata, quindi non lo reinserisco
				else
					cout << "; esecuzione completata";
				cout << "]" << endl;
			}
		}
};

#endif
