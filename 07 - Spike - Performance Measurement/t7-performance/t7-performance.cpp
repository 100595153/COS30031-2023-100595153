#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// - count char using slow repeated string::find_first_of
int count_char_using_find_first_of(string s, char delim)
{
	int count = 0;
	// note: string::size_type pos = s.find_first_of(delim);
	auto pos = s.find_first_of(delim);
	while ((pos = s.find_first_of(delim, pos)) != string::npos)
	{
		count++;
		pos++;
	}
	return count;
}

// - count char using fast std::count
int count_char_using_count(string s, char delim)
{
	return count(s.begin(), s.end(), delim);
}

void SortingAlgorithm(vector<int> toSort)
{
	int size = toSort.size();

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (toSort[j] > toSort[j + 1])
			{
				swap(toSort[j], toSort[j + 1]);
			}
		}
	}
}

vector<int> RandomiseVect(int ranSize)
{
	vector<int> vect;

	srand(time(0));

	for (int i = 0; i < ranSize; i++)
	{
		vect.push_back(rand() % 100);
	}

	return vect;
}

void SingleExecution(int size)
{
	vector<int> vect = RandomiseVect(size);

	auto start = chrono::steady_clock::now();

	SortingAlgorithm(vect);

	auto end = chrono::steady_clock::now();
	auto diff = duration_cast<nanoseconds>( end - start ).count();

	cout << "Execution Time: " << diff << " ns" << endl;

}

void MultiExecution(int runs)
{
	vector<int> vect = RandomiseVect(10);

	auto start = chrono::steady_clock::now();

	for (int i = 0; i < runs; i++)
	{
		SortingAlgorithm(vect);
	}

	auto end = chrono::steady_clock::now();
	auto diff = duration_cast<nanoseconds>(end - start).count();

	cout << "Execution Time: " << diff << " ns" << endl;
}

void RampUpLinear(int runs)
{
	SingleExecution(1);

	for (int i = 10; i <= runs; i += 10 )
	{
		SingleExecution(i);
	}
}

void RampDownLinear(int runs)
{
	for (int i = runs * runs; i > 0; i -= runs)
	{
		SingleExecution(i);
	}

	SingleExecution(1);
}

void ComparisonTest(int runs)
{
	string s1 = "s";
	
	auto start = chrono::steady_clock::now();
	auto end = chrono::steady_clock::now();
	auto diff = duration_cast<nanoseconds>(end - start).count();

	for (int i = 0; i < runs; i++)
	{
		s1 += "s";
		start = chrono::steady_clock::now();

		count_char_using_find_first_of(s1, 's');

		end = chrono::steady_clock::now();
		diff = duration_cast<nanoseconds>(end - start).count();

		cout << "Run " << i << ": " << diff << endl;
	}

	cout << "--------------------------------------------" << endl;

	s1 = "";

	for (int i = 0; i < runs; i++)
	{
		s1 += "s";
		start = chrono::steady_clock::now();

		count_char_using_count(s1, 's');

		end = chrono::steady_clock::now();
		diff = duration_cast<nanoseconds>(end - start).count();

		cout << "Run " << i << ": " << diff << endl;
	}
}

void RampUpExponential(int scale, int runs)
{
	for (int i = 1; i < pow(scale, runs); i = i * scale)
	{
		SingleExecution(i);
	}
}

int main()
{
	//Single Execution Block
	if (false)
	{
		cout << "----- Single Tests -----" << endl;

		cout << "Test 1: " << endl;
		SingleExecution(1);
		cout << endl;

		cout << "Test 2: " << endl;
		MultiExecution(10);
		cout << endl;
	}

	//Ramp-up Testing Block
	if (false)
	{
		cout << "----- Ramp Tests -----" << endl;

		cout << "Ramp-Up Linear:" << endl;
		RampUpLinear(100);
		cout << endl;


		cout << "Ramp-Down Linear:" << endl;
		RampDownLinear(10);
		cout << endl;


		cout << "Ramp-Up Exponential:" << endl;
		RampUpExponential(2, 15);
		cout << endl;
	}

	//Comparison Block
	if (true)
	{
		ComparisonTest(20);
	}
}
