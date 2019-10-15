#include <conio.h>
#include <iostream>

using namespace std;

char lhs[128];
//char rhs[50];
char readData[128];
char checksum[16];

int i;
unsigned long Delay;
//unsigned char xor;
unsigned int XOR = 0;
unsigned int Num_check;

void main()
{
	char array[] = { 
		"$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62 \r\n"
		"$TEMP,1000*33 \r\n"
	};

	char rhs[50];
	int proceed_flag = 0;
	int count = 0, index = 0, dem = 0, count1 = 0, count2, m=0;
	
	for (int k=0; k < strlen(array); k++) {
		count++;
		if (strncmp(&array[k], "$TEMP", 5) == 0) {
			for (int i=count; array[i] != '\n'; i++)
			{
				index ++;
				memcpy(lhs, array+(count-1), index);
			}
			//proceed_flag = 1;
			break;
		}
	}
	cout << "Example Transmit from Itracking: " << lhs << endl;

	for (int j=1; lhs[j] != 0; j++)
	{
		count1++;
		if (lhs[j] == '*')
		{
			count2 = count1;
			memcpy(readData, lhs + 1, count1 - 1);
		}

		if (lhs[j] == ',')
		{
			cout << "Vi tri co dau phay (tinh tu sau dau $): " << j << endl;
			for (int m=j; lhs[m] != '*'; m++)
			{
				dem++;
			}
			memcpy(rhs, lhs + (j + 1), dem - 1);
			//cout << rhs << endl;
			dem = 0;
		}
	}	

	//for (xor=0, i=0; i < strlen(readData); i++)
	//{
		//xor ^=  (unsigned char)readData[i];
	//}
	//cout << "xor: " << hex << (int)xor << endl;

	for (i=0; i < strlen(readData); i++)
	{
		XOR ^= readData[i];
	}

	memcpy(checksum, lhs + count2 + 1, count1);
	Delay = atol (rhs); //Doi sang kieu so nguyen
	Num_check = atol (checksum);

	if (Num_check == XOR) {
		proceed_flag = 1;
	}

	cout << "ReadData: " << readData << endl;
	cout << "Checksum: " << Num_check << endl;
	cout << "Delay: " << Delay << endl;
	//cout << "XOR: " << hex << XOR << endl;
	cout << "Proceed flag: " << proceed_flag << endl;

	count1 = 0;
	XOR = 0;

	getch();
}

void test() 
{
	float temp = 24.765;
	char string_temp[50];
	char string_xor[128] = "TEMP";

	sprintf(string_temp,"%f",temp); //Chuyen so thuc sang chuoi
	cout << "String temp: " << string_temp << endl;

	//Ghep 2 chuoi

}