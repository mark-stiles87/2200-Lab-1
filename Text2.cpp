Text::getLength () const
{
int count = 0;
while (charSeq[count])!='\0')
{
if (charSeq[count])!='\0')
count++;
else:
return count;
}
}
char operator [] (int n) const
{
return charSeq[n];
}
void clear()
{
delete [] charSeq;
}
void showStructure () const
{
int textLength = getLength();
for (int i = 0; i<textLength; i++)
cout << charSeq[i];
}
