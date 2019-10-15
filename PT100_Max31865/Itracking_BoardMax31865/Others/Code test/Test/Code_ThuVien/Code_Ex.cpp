#include <conio.h>
#include <iostream>

using namespace std;

void valueChecksum(char *array, char *readData, char *findChecksum);
int compareChecksum(char *array, char *findChecksum);
void ghepChuoi();

struct Data
{
	char data[128];
	char CheckXOR[2];
} s;

void main()
{
	char array[] = { 
		"$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62 \r\n"
		"$GPGSV,3,3,11,22,42,067,42,24,14,311,43,27,05,244,00,,,,*3D \r\n"	
		
		"$TEMP,1000*21 \r\n"
	};
	int result;

	valueChecksum(array, s.data, s.CheckXOR);
	if (result=compareChecksum(array,s.CheckXOR) != 0 ) {
		cout << "True Data" << endl;	
	} else {
		cout << "False Data" << endl;
	}

	cout << "Data: " << s.data << endl;
	//cout << "CheckXOR: " << hex << (int)s.CheckXOR << endl;
	cout << "CheckXOR: " << s.CheckXOR << endl;

	ghepChuoi();

	getch();
}

//.............../*Code Document for Checksum XOR*/.......................

// function to convert decimal to hexadecimal 
void decToHexa(int n, char *findChecksum) 
{    
	char hex[2];
    // char array to store hexadecimal number 
    char hexaDeciNum[2];
    // counter for hexadecimal number array 
    int i = 0, count = 0; 
    while(n!=0) 
    {    
        // temporary variable to store remainder 
        int temp  = 0;           
        // storing remainder in temp variable. 
        temp = n % 16;         
        // check if temp < 10 
        if(temp < 10) 
        { 
            hexaDeciNum[i] = temp + 48; 
            i++; 
        } 
        else
        { 
            hexaDeciNum[i] = temp + 55; 
            i++; 
        }          
        n = n/16; 
    }       
	//cout << "i: " << i << endl;
    // printing hexadecimal number array in reverse order 
    for(int j=i-1; j>=0; j--) { 
        //cout << hexaDeciNum[j];
		hex[count] = hexaDeciNum[j];
		count++;
	}

	//cout << endl << "Hex: " << hex << endl;
	//strcpy(s.CheckXOR, hex);
	strcpy(findChecksum, hex);
} 

//Function read value checksum of data
void valueChecksum(char *array, char *readData, char *findChecksum)
{
	int count = 0, index = 0, count1 = 0, i;
	char lhs[128];
	unsigned int xor = 0;

	//memset(lhs, 0, 128);

	for (int k=0; k < strlen(array); k++) {
		count++;
		if (strncmp(&array[k], "$", 1) == 0) {
			for (int i=count; array[i] != '\n'; i++)
			{
				index ++;
				memcpy(lhs, array+(count-1), index);
			}
			break;
		}
	}
	cout << "Example String: " << lhs << endl;

	for (int j=1; lhs[j] != 0; j++)
	{
		count1++;
		if (lhs[j] == '*')
		{
			memcpy(readData, lhs + 1, count1 - 1);
		}
	}

	for (i=0; i < strlen(readData); i++)
	{
		xor ^=  readData[i];
	}
	//cout << "xor: " << hex << xor << endl;
	decToHexa(xor, findChecksum); 
}

int compareChecksum(char *array, char *findChecksum) 
{
	int count = 0, index = 0, count1 = 0, count2;
	char lhs[128];
	char checksum[16];
	int Num_checksum, Num_checkxor, result; 

	/*memset(s.data, 0, 128);
	memset(s.CheckXOR, 0, 2);
	memset(lhs, 0, 128);
	memset(checksum, 0, 16);*/

	for (int k=0; k < strlen(array); k++) {
		count++;
		if (strncmp(&array[k], "$", 1) == 0) {
			for (int i=count; array[i] != '\n'; i++)
			{
				index ++;
				memcpy(lhs, array+(count-1), index);
			}
			break;
		}
	}
	for (int j=1; lhs[j] != 0; j++)
	{
		count1++;
		if (lhs[j] == '*')
		{
			count2 = count1;
		}
	}
	memcpy(checksum, lhs + count2 + 1, count1);

	//Convert string to number
	Num_checksum = atol (checksum);
	Num_checkxor = atol (findChecksum);

	//Compare if result = 1: Checksum true
	//If result = 0: Checksum false
	if (Num_checksum == Num_checkxor) {
		result = 1;
	} else {
		result = 0;
	}

	return result;
}

//........................./*Ghep 2 chuoi*/.......................
void ghepChuoi() {
	char string[] = "$TEMP,";
	char temp[] = "24.6549";
	int count3;

	cout << "String: " << string << endl;
	cout << "Temp: " << temp << endl;

	count3 = strlen(temp);
	memcpy(string + 6, temp, count3);
	memcpy(string + count3 + 6, "*\r\n", 3);

	cout << "Result: " << string << endl;
}