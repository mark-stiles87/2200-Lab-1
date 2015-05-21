#include "Text.h"
Text::Text(const char*charSeq)
{
bufferSize = strlen(charSeq) + 1;
buffer = new char[bufferSize];
for (int i = 0; i < bufferSize; i++)
	buffer[i] = charSeq[i];
}
Text::Text(const Text& other)
{
bufferSize = other.bufferSize;
buffer = new char[bufferSize];
for (int i = 0; i < bufferSize; i++)
	buffer[i] = other.buffer[i];
}
void Text::operator= (const Text& other)
{
	if (!(*this==other))
	{
		delete[] buffer;
		bufferSize = other.bufferSize;
		buffer = new char[bufferSize];
		for (int i = 0; i < bufferSize; i++)
			buffer[i] = other.buffer[i];
	}
return;
}
Text::~Text()
{
delete[] buffer;
}
int Text::getLength () const
{
	return bufferSize-1;
}
char Text::operator [] (int n) const
{
return buffer[n];
}
void Text::clear()
{
delete [] buffer;
bufferSize = 1;
buffer = new char[1];
buffer[0] = '/0';
return;
}
void Text::showStructure () const
{
int textLength = getLength();
for (int i = 0; i<textLength; i++)
cout << buffer[i];
cout << endl;
return;
}
istream & operator >> (istream &input, Text &inputText)

// Text input function. Extracts a string from istream input and
// returns it in inputText. Returns the state of the input stream.

{
	const int textBufferSize = 256;     // Large (but finite)
	char textBuffer[textBufferSize];   // text buffer

	// Read a string into textBuffer, setw is used to prevent buffer
	// overflow.

	input >> setw(textBufferSize) >> textBuffer;

	// Apply the Text(char*) constructor to convert textBuffer to
	// a string. Assign the resulting string to inputText using the
	// assignment operator.

	inputText = textBuffer;

	// Return the state of the input stream.

	return input;
}

//--------------------------------------------------------------------

ostream & operator << (ostream &output, const Text &outputText)

// Text output function. Inserts outputText in ostream output.
// Returns the state of the output stream.

{
	output << outputText.buffer;
	return output;
}
bool Text::operator==(const Text& other) const
{
	if (bufferSize != other.bufferSize)
		return 0;
	for (int i = 0; i < bufferSize; i++)
	{
		if (buffer[i] != other.buffer[i])
			return 0;
	}
	return 1;
}
