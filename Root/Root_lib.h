#ifndef ROOT_LIB
#define ROOT_LIB

#include <iostream>
#include <stdint.h>
#include <vector>
#include <bitset>
#include <time.h>
#include <chrono>
#include <stdlib.h>
#include <inttypes.h>
#include <ctime>
#include <sstream>
using namespace std;

const unsigned int word_len = 64;
uint32_t one[word_len] = { 0 };
uint32_t var[word_len] = { 0 };
uint32_t buff[word_len] = { 0 };
uint32_t empty_arr[word_len] = { 0 };
uint32_t x[word_len] = { 0 };
uint32_t result[word_len] = { 0};
string result_str;


std::chrono::high_resolution_clock::time_point begTime;
std::chrono::high_resolution_clock::time_point endTime;


void timeStart()
{
	begTime = std::chrono::high_resolution_clock::now();
}

void timeStop()
{
	endTime = std::chrono::high_resolution_clock::now();
}

long execTime()
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - begTime).count();
}

void randomizer_init()
{
	std::srand(std::time(nullptr));

}
void randomizer(uint32_t array[], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		array[i] = std::rand();
	}
}




void copy(uint32_t a[], uint32_t b[], int n )
{
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
}

void add_word(uint32_t a[], uint32_t b[], uint32_t result[], int len )
{
	int carry = 0;

	for (int i = len - 1; i >= 0; i--)
	{
		result[i] = a[i] + b[i] + carry;
		carry = (a[i] > result[i] || b[i] > result[i]) ? 1 : 0;
	}
}

void subtract_word(uint32_t a[], uint32_t b[], uint32_t result[], int len )
{
	int carry = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		result[i] = a[i] - b[i] - carry;
		if (b[i] + carry > a[i])
		{
			carry = 1;
		}
		else
		{
			carry = 0;
		}
	}
}

void shiftR_word(uint32_t array[], int n )
{
	{
		if (n == 0)
			return;

		for (int i = n - 1; i >= 0; i--)
		{
			// right shift
			array[i] = array [i] >> 1;

			// carry bit
			if (i > 0)
				array[i] = array[i] | (array[i - 1] & 0x1) << 31;
		}
	}
}


void printAsBit(uint32_t w_number[], int n )
{
	std::cout << std::endl;

	for (size_t i = 0; i < n; i++)
	{
		std::cout << std::bitset<32>(w_number[i]);
	}
}

void fillZeros(uint32_t a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = 0;
	}
}

bool equals(uint32_t a[], uint32_t b[], int len )
{
	for (int i = 0; i < len; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

bool isZero(uint32_t a[], int len )
{
	for (int i = 0; i < len; i++)
	{
	
		if (a[i] != 0)
			return false;
	}
	return true;
}

bool isBigger(uint32_t a[], uint32_t b[], int len )
{
	for (int i = 0; i < len; i++)
	{
		if (a[i] > b[i])
		{
			return true;
		}
		else
			if (a[i] < b[i])
			{
				return false;
			}
	}
}
void root(uint32_t input[], uint32_t result[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (input[i] != 0)
			one[i] = 1L << 30;

	}
	while (isBigger(one, input, n))
	{
		shiftR_word(one, n);
		shiftR_word(one, n);
	}

	while (!isZero(one, n))
	{
		copy(empty_arr, var, n);		//zerowanie var
		add_word(result, one, var, n); // var = result + one

		if (isBigger(input, var, n) || equals(input, var, n))
		{
			copy(empty_arr, buff, n);			//zerowanie buff
			subtract_word(input, var, buff, n + 1);
			copy(buff, input, n);				//input -=var
			shiftR_word(result, n);
			copy(empty_arr, x, n);		//	zerowanie x

			add_word(result, one, x, n);
			copy(x, result, n);
		}
		else
		{
			shiftR_word(result, n);
		}
		shiftR_word(one, n);
		shiftR_word(one, n);
	}
	printAsBit(result,n);
	cout << endl;
}
string convert(uint32_t array[], int n, string result)
{
	std::stringstream ss;
	for (int i = 0; i <= sizeof(array) - 1; i++)
	{
		ss << array[i];
	}
	ss >> result;
	cout << result;
	result_str = result;
	return result_str;
}
long autoTest(uint32_t array[], uint32_t result[], long numberOfTests, int n)
{
	long resultTime = 0;

	for (size_t i = 0; i < numberOfTests; i++)
	{
		randomizer(array, n);
		timeStart();
		root(array, result, n);
		timeStop();
		resultTime += execTime();

		fillZeros(one, word_len);
		fillZeros(var, word_len);
		fillZeros(buff, word_len);
		fillZeros(empty_arr, word_len);
		fillZeros(x, word_len);
	}
	string s;
	cout << endl << endl;
	convert(array, sizeof(array), s);
	cout << "Time: " << resultTime << endl;
	return resultTime;
}



void compareResults()
{

}


string square(string num1, string &s, int base = 10)
{
	num1 = result_str;
	string num2 = num1;
	int n1 = num1.size();
	int n2 = num2.size();
	if (n1 == 0 || n2 == 0)
		return "0";

	// will keep the result number in vector
	// in reverse order
	vector<int> result(n1 + n2, 0);

	// Below two indexes are used to find positions
	// in result.
	int i_n1 = 0;
	int i_n2 = 0;

	// Go from right to left in num1
	for (int i = n1 - 1; i >= 0; i--) {
		int carry = 0;
		int n1 = num1[i] - '0';

		// To shift position to left after every
		// multiplication of a digit in num2
		i_n2 = 0;

		// Go from right to left in num2
		for (int j = n2 - 1; j >= 0; j--) {
			// Take current digit of second number
			int n2 = num2[j] - '0';

			// Multiply with current digit of first number
			// and add result to previously stored result
			// at current position.
			int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

			// Carry for next iteration
			carry = sum / base;

			// Store result
			result[i_n1 + i_n2] = sum % base;

			i_n2++;
		}

		// store carry in next cell
		if (carry > 0)
			result[i_n1 + i_n2] += carry;

		// To shift position to left after every
		// multiplication of a digit in num1.
		i_n1++;
	}

	// ignore '0's from the right
	int i = result.size() - 1;
	while (i >= 0 && result[i] == 0)
		i--;

	// If all were '0's - means either both or
	// one of num1 or num2 were '0'
	if (i == -1)
		return "0";

	// generate the result string
	
	while (i >= 0)
		s += std::to_string(result[i--]);

	cout << endl << "Square: " << s;
	return s;
}



#endif /* ROOT_LIB */


