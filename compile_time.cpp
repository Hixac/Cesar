#include <iostream>
#include <random>
#include <chrono>
#include <time.h>
#include <vector>
#include <array>
#include <list>
#include <math.h>

#define LENGTH 3000000
#define TYPE int
#define ARRAY_CAPACITY , 3000000
#define CONTAINER_TYPE std::array<int ARRAY_CAPACITY>
#define FILL_OPERATOR container[i] = rand();
#define ACTION sum = sum + container[i];

int main(void)
{
	srand(time(0));
	
	CONTAINER_TYPE container;

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < LENGTH; i++)
	{
		FILL_OPERATOR
	}
	auto end = std::chrono::high_resolution_clock::now();

	std::cout << container[0] << std::endl;
	std::cout << container[1] << std::endl;
	std::cout << container[2] << std::endl;

	std::cout << "Fill time: " << std::chrono::duration<float, std::micro>(end - start).count() / 1000 << std::endl;

	TYPE sum = 1;

	auto nstart = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < LENGTH; i++)
	{
	    ACTION
	}
	auto nend = std::chrono::high_resolution_clock::now();

	std::cout << "Operation time: " << std::chrono::duration<float, std::micro>(nend - nstart).count() / 1000 << std::endl;

	return 0;
}
