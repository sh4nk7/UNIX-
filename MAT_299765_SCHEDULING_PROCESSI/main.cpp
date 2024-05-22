
#include <iostream>
#include <fstream>
#include <sstream>

#include "assert.h"
#include "fcfsscheduler.h"
#include "sjfscheduler.h"
#include "priorityscheduler.h"
#include "roundrobinscheduler.h"

using namespace std;


int main()
{
	char filename[50];
	
	cout << "Inserire il nome del file: ";
	cin >> filename;
	ifstream f;
	f.open(filename);
	Assert(f.is_open(), "Errore nell'aprire il file");
	
	string first_line;
	int round_robin;
	cout << "Lettura round robin in corso..." << endl;
	getline(f, first_line);
	stringstream(first_line) >> round_robin;
	cout << "Round robin: " << round_robin << endl;
	
	List<Process> processes;
	string line, process, cpu_str, priority_str;
	int cpu_burst, priority;
	cout << "Lettura processi in corso..." << endl;
	while (!f.eof())
	{
		getline(f, process, ',');
		getline(f, cpu_str, ',');
		getline(f, priority_str, '\n');
		stringstream(cpu_str) >> cpu_burst;
		stringstream(priority_str) >> priority;
		Process p(process, cpu_burst, priority);
		cout << p << endl;
		processes.append(p);
	}
	cout << "Lettura completata [Num processi letti: " << processes.size() << "]" << endl;
	cout << endl;
	
	FCFSScheduler fcfs(processes);
	fcfs.schedule();
	cout << endl;
	
	SJFScheduler sjf(processes);
	sjf.schedule();
	cout << endl;
	
	PriorityScheduler p(processes);
	p.schedule();
	cout << endl;
	
	RoundRobinScheduler rr(processes, round_robin);
	rr.schedule();
	cout << endl;
	
	system("pause");
	
	return 0;
}
