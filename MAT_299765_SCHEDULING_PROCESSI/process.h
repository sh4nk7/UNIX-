
#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <iostream>

using namespace std;

class Process {
	
	private:
		string name;
		int cpu_burst;
		int priority;
	
	public:
		Process() { name = "", cpu_burst = 0; priority = 0; }
		Process(string& n, int c, int p) : name(n), cpu_burst(c), priority(p) { }
		const string& getName() const { return name; }
		const int getCpuBurst() const { return cpu_burst; }
		const int getPriority() const { return priority; }
		void execute(int round_robin) { cpu_burst -= round_robin; if (cpu_burst < 0) cpu_burst = 0; }
};

ostream& operator << (ostream& out, const Process& p)
{
	out << "Processo: " << p.getName() << " [cpu burst: " << p.getCpuBurst() << ", priorita': " << p.getPriority() << "]";
	return out;
}

#endif
