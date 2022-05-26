#include <iostream>
#include <functional>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <corecrt_math_defines.h>

#define ANALYTIC_INTEGRAL M_PI*4/6

// measure function execution time
void time_measure(std::function<double(std::function<double(double)> f, double A, double B, int n)> integral, std::function<double(double)> f, double A, double B, int n, double &result, double &time)
{
	auto start_time = std::chrono::high_resolution_clock::now();
	result = integral(f, A, B, n);
	auto finish_time = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration<double>(finish_time - start_time).count();
}

// objective function
double func(double x)
{
	return 4 / sqrt(4 - pow(x, 2));
}