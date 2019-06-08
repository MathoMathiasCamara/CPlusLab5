// CPlusLab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

int goodNumber();

int main()
{
	srand(time(0));

	cout << "Enter a 'k' value:\n";
	int k = goodNumber();
	cout << "Enter a 'l' value:\n";
	int l = goodNumber();
	cout << "Enter a 'n' Matrix size:\n";
	int n = goodNumber();

	//---------------------------------------------------
	//запись

	ofstream output;
	//first file
	output.open("C:\\Users\\matho\\source\\repos\\CPlusLab1\\CPlusLab1\\first.txt");
	if (output.is_open())
	{
		//checking and adding matrices to the file
		if (k != 1 && l > k)
		{
			for (int i = 0; i < l - k; i++)
			{
				for (int j = 0; j < n; j++)
				{
					for (int h = 0; h < n; h++)
					{
						output << (j == h ? 1 : 0) << " ";
					}
					output << "\n";
				}
				output << "\n----------\n\n";
			}
		}

		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int h = 0; h < n; h++)
				{
					output << ((rand() % 9) + 1) << " ";
				}
				output << "\n";
			}
			output << "\n----------\n\n";
		}


	}
	output.close();

	//second file
	output.open("C:\\Users\\matho\\source\\repos\\CPlusLab1\\CPlusLab1\\second.txt");
	if (output.is_open())
	{
		//checking and adding matrix to the file
		if (k > l)
		{
			for (int i = 0; i < k - l; i++)
			{
				for (int j = 0; j < n; j++)
				{
					for (int h = 0; h < n; h++)
					{
						output << (j == h ? 1 : 0) << " ";
					}
					output << "\n";
				}
				output << "\n----------\n\n";
			}
		}
		for (int i = 0; i < l; i++)
		{
			int r = (rand() % 9) + 1;
			for (int j = 0; j < r; j++)
			{
				for (int h = 0; h < r; h++)
				{
					output << ((rand() % 9) + 1) << " ";
				}
				output << "\n";
			}
			output << "\n----------\n\n";
		}
	}
	output.close();

	//---------------------------------------------------
	//READING

	//first file
	cout << "\n\nReading first file...\n----------\n\n";
	string line;
	ifstream input1("C:\\Users\\matho\\source\\repos\\CPlusLab1\\CPlusLab1\\first.txt");
	if (input1.is_open())
	{
		while (getline(input1, line))
		{
			cout << line << "\n";
		}
	}
	input1.close();

	//second file
	cout << "\n\nReading second file...\n----------\n\n";
	ifstream input2("C:\\Users\\matho\\source\\repos\\CPlusLab1\\CPlusLab1\\second.txt");
	if (input2.is_open())
	{
		while (getline(input2, line))
		{
			cout << line << "\n";
		}
	}
	input2.close();

	//-------------------------------------------------

	system("pause");
}

//checking the entered number
int goodNumber()
{
	string s = "c";
	int n = 0;

	while (n <= 0 || n > 9)
	{
		cout << "Enter a number between 1 and 9:\n";
		getline(cin, s);
		n = atoi(s.c_str());
	}
	return n;
}