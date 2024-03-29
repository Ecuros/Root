#include "pch.h"
#include <iostream>
#include "Root_lib.h"
#include <string>
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
// Big numbers (n-bit) square root
// Stage 1 - 128b (4 word)
//
//
// Example 32b (1):
// In : 2326440277 = 1000 1010 1010 1010 1010 1001 0101 0101b
// Out: 48233      = 0000 0000 0000 0000 1011 1100 0110 1001b
//
// Example 32b (2):
// In : 2511054761 = 1001 0101 1010 1011 1010 0111 1010 1001b
// Out: 50110      = 0000 0000 0000 0000 1100 0011 1011 1110b
//
// Out^2 = 2511012100 -> ratio = 0,00001698927505~0,002%
//
//
//
// Algorighm "Search and check - Square root" for 128b numbers
//
// In : number[] (128b-4w)
// Out: result[] (square root of number)
//
//
// result = 0;
// one = 2^127;
//
// while (one > number)
//     one = one/4;
//
// while (one != 0)
// {
//     if ( number >= (result + one) )
//     {
//         number = number - (result + one);
//         result = result/2 + one;
//     }
//     else
//       result = result/2;
//     one = one/4;
// }
//
// Stage 2
// Transform function for 32b-words arguments.
// Invent and implement (inconvenient) way of verify.
/*
 TODO:
  -subtract
  -verify
	delta = number - square(result)

*/




//const unsigned int word_len = 39;
//uint32_t w_number[word_len] = {0b0010101010, 42553,425,35245};
/*uint32_t input[word_len] = { 10,10,324,234,52,5,3462345,2541,425,1346,643657,134,134314,346,8568456,1342345,74574,23564,456,1234,63,7775634,35657121,86578245,36457,234536,34221,1789085,3565245,7856245,3564,2457,245,22345,65463,6777,3345,6682,234556 };
uint32_t one[word_len] = { 0,0,0,0,0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0 };
uint32_t var[word_len] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint32_t buff[word_len] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
uint32_t result[word_len] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
uint32_t empty_arr[word_len] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };



uint32_t x[word_len] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };*/
//uint32_t input[] = { 0,0,1,2434322 };
//uint32_t result[] = { 0,0,0,0 };


uint32_t input128[4] = {0,0,0,3250235234};
uint32_t result128[4] = { 0 };


uint32_t input256[8] = { 0 };
uint32_t result256[8] = { 0 };

uint32_t input512[16] = { 0 };
uint32_t result512[16] = { 0 };

uint32_t input1024[32] = { 0 };
uint32_t result1024[32] = { 0 };

uint32_t input2048[64] = { 0 };
uint32_t result2048[64] = { 0 };

string strInput;
string strResult;
string diff;

//string rezult = "";

uint32_t pomocnicza[4] = { 0 };
uint32_t pomocnicza2[4] = { 0 };

int numberOfTests = 1;



int main(int argc, char const *argv[])
{

	randomizer_init();

	copy(input128, pomocnicza, 4);
	cout << "Input: " << endl;
	convert(input128, 4, strInput);
	root(input128, result128, 4);

	convert(input128, 4, diff);
	//cout << "Diff: " << diff;
	
	
	/*cout << endl << "Result: ";
	convert(result128, 4, strResult);
	 
	square(strResult, sqrtResult);

	std::istringstream results (sqrtResult);

	results >> pomocnicza2[3];
	
	subtract_word(pomocnicza, pomocnicza2, difference128, 4);
	cout << endl << "Difference: " ;
	convert(difference128, 4, strDif);
	*/
	

	

	return 0;
}
