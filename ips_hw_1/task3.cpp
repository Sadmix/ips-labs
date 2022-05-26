#include "time_measure.h"
#include <advisor-annotate.h>

// integral function with parallezation
double integral_parallel(std::function<double(double)> f, double A, double B, int n)
{
	auto h = abs(B - A) / n;
	double sum = 0;
	#pragma loop(hint_parallel(8))
    ANNOTATE_SITE_BEGIN(square_loop)
	for (int i = 0; i < n; i++)
	{
        ANNOTATE_TASK_BEGIN(square)
		double x = A + h * i;
		sum += f(x + h/2);
        ANNOTATE_TASK_END(square)
	}
    ANNOTATE_SITE_END(square_loop)
	auto i = h * sum;
	return i;
}

int main(int argc, char const *argv[])
{
    int max_power = 5;

	std::vector<double> time_results(max_power, 0);
	std::vector<double> val_results(max_power, 0);
	std::vector<int> n(max_power, 0);

    std::cout << "[TASK 3] : Parallezation" << std::endl;

	for (int j = 0; j < 5; j++)
	{
		n[j] = 100 * pow(10, j);
		time_measure(integral_parallel, func, 0, 1, n[j], val_results[j], time_results[j]);
	}
	
	std::cout
		<< std::left
		<< std::setw(10)
		<< "N"
		<< std::left
		<< std::setw(20)
		<< "Result"
		<< std::left
		<< std::setw(20)
		<< "Epsilon"
		<< std::left
		<< std::setw(20)
		<< "Elapsed time (s)"
		<< std::endl;

	for (int j = 0; j < 5; j++)
	{
		std::cout
			<< std::left
			<< std::setw(10)
			<< std::setprecision(0)
			<< std::scientific
			<< double(n[j])
			<< std::fixed
			<< std::setprecision(15)
			<< std::left
			<< std::setw(20)
			<< val_results[j]
			<< std::left
			<< std::setw(20)
			<< abs(ANALYTIC_INTEGRAL - val_results[j])
			<< std::left
			<< std::setw(20)
			<< time_results[j]
			<< std::endl;
	}
	std::cout << std::endl;

    return 0;
}