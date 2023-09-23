#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;

//https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
//Borrowed code.
string gen_random(const int len) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	string tmp_s;
	tmp_s.reserve(len);

	for (int i = 0; i < len; ++i) {
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	return tmp_s;
}

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

void ComparisonTest(string s)
{
	auto start = chrono::steady_clock::now();
	auto end = chrono::steady_clock::now();
	auto diff = duration_cast<nanoseconds>(end - start).count();

	start = chrono::steady_clock::now();

	count_char_using_find_first_of(s, 's');

	end = chrono::steady_clock::now();
	diff = duration_cast<nanoseconds>(end - start).count();

	cout << "Find First Of: " << diff << endl;

	

	
	start = chrono::steady_clock::now();
	
	count_char_using_count(s, 's');

	end = chrono::steady_clock::now();
	diff = duration_cast<nanoseconds>(end - start).count();

	cout << "Count: " << diff << endl;
	cout << "--------------------------------------------" << endl;
}

void RampUpExponential(int scale, int runs)
{
	for (int i = 1; i < pow(scale, runs); i = i * scale)
	{
		SingleExecution(i);
	}
}

void RampUpLinearComp(int runs)
{
	string s;

	for (int i = 1; i <= pow(10, runs); i *= 10)
	{
		cout << i << endl;
		s = gen_random(i * 10);
		ComparisonTest(s);
	}
}

int main()
{
	//Single Execution Block
	if (true)
	{
		//cout << "----- Single Tests -----" << endl;

		//cout << "Test 1: " << endl;
		//SingleExecution(1);
		//cout << endl;

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
	if (false)
	{
		string s = "According to all known laws of aviation, there is no way a bee should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible. Yellow, black.Yellow, black. Yellow, black.Yellow, black. Ooh, black and yellow! Let's shake it up a little. Barry! Breakfast is ready! Coming! Hang on a second. Hello? Barry? Adam? Can you believe this is happening? I can't. I'll pick you up. Looking sharp. Use the stairs.Your father paid good money for those. Sorry. I'm excited. Here's the graduate. We're very proud of you, son. A perfect report card, all B's. Very proud. Ma! I got a thing going here. You got lint on your fuzz. Ow!That's me! Wave to us!We'll be in row 118,000. Bye! Barry, I told you, stop flying in the house! Hey, Adam. Hey, Barry. Is that fuzz gel? A little.Special day, graduation. Never thought I'd make it. Three days grade school, three days high school.Those were awkward. Three days college. I'm glad I took a day and hitchhiked around the hive. You did come back different. Hi, Barry. Artie, growing a mustache ? Looks good. Hear about Frankie? Yeah.";
		ComparisonTest(s);
		ComparisonTest(s);
		ComparisonTest(s);

		cout << "------------------------------------------------" << endl;

		RampUpLinearComp(10);
	}
}
