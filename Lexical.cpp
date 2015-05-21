#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Text.h"
//int main()
//{
//string line;
//string Token;
//int count = 0;
//ifstream inputfile("progsamp.dat");
//if (inputfile.is_open())
//{
//while (getline(inputfile, line))
//{
//for (int i = 0; i < line.length(); i++)
//{
//if (line[i] != ' ')
//{
//int j = 0;
//int k = i;
//while (line[i] != ' ' && i < line.length())
//{
//j++;
//i++;
//}
//Token.assign(line, k, j);
//count++;
//cout << count << " : " << Token << endl;
//}
//}
//}
//inputfile.close();
//}
//else
//cout << "Error: Unable to open file.";
//return 0;
//}
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
		while (infile.peek() != ' '&&infile.peek() != '\t'&&infile.peek() != '\n'&&infile.peek() != '\0')
			infile >> test;
		count++;
		outfile << count << ' ' << test << endl;
		test.clear();
		while (infile.peek() == ' '||infile.peek() == '\t'||infile.peek() == '\n'||infile.peek() == '\0')
			infile >> test;
		test.clear();
	}
	infile.close();
	outfile.close();
	return 0;
}
