
#ifndef ASSERT_H
#define ASSERT_H

#include <iostream>

using namespace std;

// Assert: Se "val" è falso, stampo il messaggio d'errore terminando l'esecuzione del programma
void Assert(bool val, string s) 
{	
	// Assertion failed -- chiudi il programma
	if (!val) 
	{ 
    	cout << "Asserzione non verificata: " << endl;
		cout << s << endl;
    	exit(-1);
	}
}


#endif
