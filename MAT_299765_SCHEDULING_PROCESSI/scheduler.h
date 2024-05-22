
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "list.h"
#include "process.h"


class Scheduler
{
	protected:
		List<Process> processes;
		
	public:
		
		Scheduler(List<Process>& l) {
			//a termine di questo assegnamento, processes conterrà una copia del parametro di input l.
			//essendo una copia di l, i suoi attributi head e tail punteranno alla medesima lista di quella puntata
			//dagli attributi head e tail del parametro di input
			processes = l;
		}
		
		virtual void schedule() = 0;
};

#endif
