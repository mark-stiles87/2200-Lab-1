#include "Text.h"
Text::Text(const char*charSeq = "")
{
	bufferSize = strlen(charSeq) + 1;
	buffer = new char[bufferSize];
	strcpy(buffer, charSeq);
}
Text::Text(const Text& other)
{
	bufferSize = other.bufferSize;
	buffer = new char[bufferSize];
	strcpy(buffer, other.buffer);
}
void Test::operator= (const Text& other)
{
	delete [] buffer;
	bufferSize = other.bufferSize;
	buffer = new char[bufferSize];
	strcpy(buffer, other.buffer);
	return;
}
Text::~Text()
{
	delete[] buffer;
}