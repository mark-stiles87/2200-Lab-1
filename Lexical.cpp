/*
Lexical Analysis
System Architect:	Anthony Mauro
Data Architect:		Benjamin Ciaglo
Developer:			Mark Stiles
Last Compiled 2015-05-27 on Dwarf_Box_72
*/
#include <iostream>
#include <fstream>
#include "Text.h"
int main()
{
	Text test;
	int count = 0;
	ifstream infile;
	infile.open("progsamp.dat");
	ofstream outfile;
	outfile.open("test.txt");
	while (infile)
	{
		while (infile.peek() != ' ' && infile.peek() != '\t' && infile.peek() != '\n' && infile.peek() != '\0')
			infile >> test;
		count++;
		outfile << count << ' ' << test << endl;
		if (infile.peek() == ' ')
			infile >> test;
		if (infile.peek() == '\t')
			infile >> test;
		if (infile.peek() == '\n')
			infile >> test;
		if (infile.peek() == '\0')
			test.clear();
	}
	infile.close();
	outfile.close();
	return 0;
}
