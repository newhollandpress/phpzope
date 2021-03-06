/* Standard C++ headers */
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdexcept>
#include <regex>
#include <fstream>

#include "pycodes.hpp"

using namespace std;
	
static void retrieve_state(string state2)
        {
	std::string filename = "state.txt";
	std::ofstream out(filename);

	/* fetch the data : retrieve all the rows in the result set */
	out << state2;
	cout << state2;

	Pickle *myPickler = new Pickle();
	std::string::iterator it;
	it = state2.begin();
	while (it != state2.end())
	{
	    cout << *it;
	    for (int i = 0; i < OPCODE_COUNT; i++)
	    {
	        Opcode *currentOpcode = myPickler->opcodes[i];
		if (currentOpcode->opcode == *it)
                {
		    int result;
	            result = (currentOpcode->opfunc)(state2,it,currentOpcode);
		}
	    }
	    it++;
        }
        cout << "END-OF-LINE";
        cout << std::endl;
        out.close();
} // retrieve_state()

int main(int argc, const char *argv[]) {
	std::string state;
	std::string state2;
	ifstream infile;
	infile.open("newdoc.txt");
	while (!infile.eof())
        {
	    infile >> state;
	    state2.append(state); 
	    const char *newline = "|";
	    state2.append(newline);
	}
	retrieve_state(state2);
	infile.close();
} // main()
