#include "pch.h"
#include <iostream>
#include "Root_lib.h"
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




const unsigned int word_len = 4;
//uint32_t w_number[word_len] = {0b0010101010, 42553,425,35245};
uint32_t input[word_len] = { 0,0,12,0 };
uint32_t one[word_len] = { 0,0,0,0 };
uint32_t var[word_len] = { 0,0,0,0 };
uint32_t buff[word_len] = { 0,0,0,0 };
uint32_t result[word_len] = { 0,0,0,0 };
uint32_t empty_arr[word_len] = { 0,0,0,0 };


uint32_t x[word_len] = { 0,0,0,0 };



int main(int argc, char const *argv[])
{
	
	//uint32_t liczba1[5] = { 421,32131,5200,1,4311 };
	//printAsBit(liczba1);
	//shiftR_word(liczba1);
	//printAsBit(liczba1);
	/*uint32_t liczba2[5] = { 0,123,100,890,901 };
	uint32_t wynik[5] = { 0,0,0,0,0 };

	subtract_word(liczba1, liczba2, wynik, 5);
	for (int i = 0; i <=4 ; i++)
	{
		cout << " " <<wynik [i];
	}
	
	if (isBigger(liczba1, liczba2))
		cout << " 1 ma wiekszego";*/
	//shiftR_word(liczba1);
	//printAsBit(liczba1);

	//for (int i = 0; i <= 4; i++)
	//{
	//	cout << " " << liczba1[i];
	//}
	//cout << endl << endl << endl;


	std::cout << "In : ";

	printAsBit(input);
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		cout << input[i] << " ";
	}
	cout << endl;
	one[0] = 1L << 30;

	while (isBigger(one, input))
	{
		shiftR_word(one);
		shiftR_word(one);
	}
;
	while (!isZero(one))
	{
		copy(empty_arr, var, 4);		//zerowanie var
		add_word(result, one, var); // var = result + one 
	
		if (isBigger(input, var) || equals (input,var,4 ))
		{		
			copy(empty_arr, buff, 4);			//zerowanie buff
			subtract_word(input, var, buff,4);
			copy(buff, input,4);				//input -=var
			shiftR_word(result);
			copy(empty_arr, x,4);		//	zerowanie x

			add_word(result, one, x,4);		
			copy(x, result, 4);
		}
		else
		{
			shiftR_word(result);			
		}
		shiftR_word(one);
		shiftR_word(one);
	}


	std::cout << "\nOut: ";
	for (int i = 0; i < 4; i++)
	{
		cout << result[i] << " ";
	}
	printAsBit(result);
	std::cout << std::endl;

	cout << square("110111011011001111");


	

	return 0;
}
