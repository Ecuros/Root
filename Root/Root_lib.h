#ifndef ROOT_LIB
#define ROOT_LIB

#include <iostream>
#include <stdint.h>
#include <vector>
#include <bitset>
using namespace std;

void copy(uint32_t a[], uint32_t b[], int n = 4)
{
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
}

void add_word(uint32_t a[], uint32_t b[], uint32_t result[], int len = 4)
{
	int carry = 0;


	for (int i = len - 1; i >= 0; i--)
	{
		result[i] = a[i] + b[i] + carry;
		carry = (a[i] > result[i] || b[i] > result[i]) ? 1 : 0;
		//cout << " "  << result[i] << " * " << carry;
	}


}

void subtract_word(uint32_t a[], uint32_t b[], uint32_t result[], int len = 5)
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

void shiftR_word(uint32_t array[], int n = 4)
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
	 //n - how many words
	//(n*32b word) >> 1

	/* bool* odd = new bool[n];
	
	   for (int i = 0; i < n; i++)
	   {
	     if(array[i] & 1 )
	       odd[i]=true;
	    else
			odd[i]=false;
	   }
	
	
   for (int i = 0; i < n; i++)
	   array[i] >>= 1;
	
	   for (int i = 0; i < n-1; i++)
	   {
	    if(odd[i])
		  {
	    // array[i+1] = array[i+1] | 1 << 31;
			array[i+1] = (1 << 31) | array[i+1];
			}
		}
	
	 delete[] odd;
	 
	 
/*	for (int i = 0; i < 4; i++)	
	{
		array[i] = array[i] >> 1;

		if (i < 3)
		{
			if (i != 0)
			{
				unsigned int bottom_bit = (array[i + 1] & 0x1) << 31;
				array[i] = array[i] | bottom_bit;
			}
		}
	}*/
}


/*void shiftR_word( uint32_t array [], size_t k =1)
{	
	uint32_t a = array[3];
	uint32_t b = array[2];
	uint32_t c = array[1];
	uint32_t d = array[0];
	
	{
		d = (c << (32 - k)) | (d >> k); \
			c = (b << (32 - k)) | (c >> k); \
			b = (a << (32 - k)) | (b >> k); \
			a = (a >> k);
	}
}*/
void printAsBit(uint32_t w_number[], int n = 4)
{
	std::cout << std::endl;

	for (size_t i = 0; i < n; i++)
	{
		std::cout << std::bitset<32>(w_number[i]);
	}
}

bool equals(uint32_t a[], uint32_t b[], int len = 4)
{
	for (int i = 0; i < len; i++)
	{
	//	if (a[i] == b[i])
			//return true;
		if (a[i] != b[i])
			return false;
	}
	return true;
}

bool isZero(uint32_t a[], int len = 4)
{
	for (int i = 0; i < len; i++)
	{
	
		if (a[i] != 0)
			return false;
	}
	return true;
}

bool isBigger(uint32_t a[], uint32_t b[], int len = 4)
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
	//return true;
	/*if (equals(a, b, 4))
	{
		return false;
	}*/
}



string square(string num1, int base = 2)
{

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
	string s = "";
	while (i >= 0)
		s += std::to_string(result[i--]);

	return s;
}



#endif /* ROOT_LIB */




// void shiftR_word(uint32_t w_number[], int n)
// {
//     // n - how many words
//     //(n*32b word) >> 1
//     //int n = sizeof(w_number)/sizeof(*w_number);
//     //cout << endl << sizeof(w_number) << "*" << sizeof(*w_number) << endl;
//     bool* odd = new bool[n-1];
//
//       for (size_t i = 0; i <= n-1; i++)
//         if( w_number[i] & 1 ) odd[i]=true;
//
//       for (size_t i = 0; i < n; i++)
//         w_number[i] >>= 1;
//
//       for (size_t i = 0; i <= n-1; i++)
//         if(odd[i]) w_number[i+1] = w_number[i+1] | 1 << 31;
//
//       delete[] odd;
//
// }
//
// void printAsBit(uint32_t w_number[], int n)
// {
//   std::cout << std::endl;
//
//   for (size_t i = 0; i < n; i++)
//   {
//     std::cout << std::bitset<32>(w_number[i]);
//   }
// }
//
//
// bool equals(uint32_t a[],uint32_t b[] ,int len)
// {
//   for (size_t i = 0; i < len; i++)
//   {
//     if (a[i]!=b[i])
//       return false;
//   }
//   return true;
// }
//
// bool isZero(uint32_t a[], int len)
// {
//   for (size_t i = 0; i < len; i++)
//   {
//     if (a[i]!=0)
//       return false;
//   }
//   return true;
// }
//
// bool isBigger(uint32_t a[],uint32_t b[] ,int len)
// {
//     for (size_t i = 0; i < len; i++)
//     {
//       if (a[i]>b[i])
//       {
//         //cout << "\n" << a[i] << " " << b[i];
//         return true;
//       }
//     }
//     return false;
// }
