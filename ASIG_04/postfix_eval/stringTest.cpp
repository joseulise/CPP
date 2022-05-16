#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int main()
{

	string aString;
	int  index=0;
	int arraySize=0;
	int aNumberArray[11];
	char tempChar;

	cout<<"Enter a string with numbers: ";
	cin>>aString;
	for(int a=0;a<aString.length();a++)
		{
			if(isdigit(aString[a]))
			{
				//aNumber=NULL;
				tempChar=aString[a];
				aNumberArray[arraySize] = atoi(&tempChar);
			//	aNumberArray[arraySize]=aNumber;
				arraySize++;
			}//IF
		}//FOR

//	if(isdigit(aString[0]))
	//	for
//	aNumber=atoi(&aString[index]);
	//cout<<aNumber;
	if(arraySize>0)
		{
			cout<<"Numeric values inside the string:"<<endl;
			for(int b=0;b<arraySize;b++)
				cout<<aNumberArray[b]<<endl;
		}//if

	return 0;
}
