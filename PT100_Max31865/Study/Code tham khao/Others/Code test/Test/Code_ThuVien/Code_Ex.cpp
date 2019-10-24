#include <conio.h>
#include <iostream>

using namespace std;

void valueChecksum(char *array, char *readData, char *findChecksum);
int compareChecksum(char *array);
void ghepChuoi();

struct Data
{
	char data[128];
	char CheckXOR[2];
} s;

void main()
{
	char array[] = { 
		"$TEMP,27.934209*21 \r\n"
		"$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*0A \r\n"
		"$GPGSV,3,3,11,22,42,067,42,24,14,311,43,27,05,244,00,,,,*3D \r\n"		
	};
	int result;

	result = compareChecksum(array);
	if (result != 0 ) {
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
/*void decToHexa(int n, char *findChecksum) 
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
}*/ 

//Function read value checksum of data
void valueChecksum(char *array, char *readData, char *findChecksum)
{
	int count, dola, sao;
	unsigned int xor = 0;

	for (int k=0; k < strlen(array); k++) {
		if (strncmp(&array[k], "$", 1) == 0) {
			dola = k;
		}
		if (strncmp(&array[k], "*", 1) == 0) {
			sao = k;
			break;
		}
	}
	count = sao - dola;
	memcpy(readData, &array[dola + 1], count - 1);

	//cout << "Example String: " << readData << endl;

	for (int i=0; i < strlen(readData); i++)
	{
		xor ^=  readData[i];
	}
	//cout << "xor: " << hex << xor << endl;
	//decToHexa(xor, findChecksum); 
	sprintf(findChecksum, "%02x", xor);
	//cout << "Find checksum: " << findChecksum << endl;
}

int compareChecksum(char *array) 
{
	int count, sao;
	char checksum[3];
	int result; 

	/*memset(s.data, 0, 128);
	memset(s.CheckXOR, 0, 2);
	memset(checksum, 0, 3);*/

	valueChecksum(array, s.data, s.CheckXOR);

	for (int k=0; k < strlen(array); k++) {
		if (array[k] == '*') {
			sao = k;
		}
		if (array[k] == '\r') {
			count = k - sao;
			memcpy(checksum, &array[sao + 1], count - 1);
			break;
		}
	}
	
	cout << "Checksum in string: " << checksum << endl;

	//Compare if result = 1: Checksum true
	//If result = 0: Checksum false
	if (strcmp(checksum, s.CheckXOR) == 0) {
		result = 1;
	} else {
		result = 0;
	}

	return result;
}

//........................./*Ghep 2 chuoi*/.......................
void ghepChuoi() {
	char string[50] = "$TEMP,";
	char temp[] = "24.6549";
	int count3;

	cout << "String: " << string << endl;
	cout << "Temp: " << temp << endl;

	count3 = strlen(temp);
	memcpy(string + 6, temp, count3);
	memcpy(string + count3 + 6, "*\r\n", 3);

	cout << "Result: " << string << endl;
}