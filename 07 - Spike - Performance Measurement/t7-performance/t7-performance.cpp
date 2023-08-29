#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;

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

void SingleExecution()
{
	vector<int> vect = RandomiseVect(10);

	auto start = chrono::steady_clock::now();

	sort(vect.begin(), vect.end());

	auto end = chrono::steady_clock::now();

	auto diff = duration_cast<nanoseconds>( end - start ).count();

	cout << "Execution Time: " << diff << " ns" << endl;

}

void MultiExecution()
{
	vector<int> vect;

}

int main()
{
	//Single Execution Block
	if (true)
	{
		cout << "----- Single Tests -----" << endl;

		cout << "Test 1: " << endl;
		SingleExecution();

		cout << "Test 2: " << endl;
		MultiExecution();

		cout << "\n";
	}


	//Ramp-up Testing Block
	if (false)
	{

	}


}
