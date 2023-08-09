
#include <iostream>

using namespace std;

class DemoClass
{
private:
    int var1;
public:
    int var2;

    DemoClass(int tVar1, int tVar2)
    {
        var1 = tVar1;
        var2 = tVar2;
    }

    int add_vars()
    {
        return var1 + var2;
    }

};

void print_para(int para1, int para2)
{
    cout << para1 << endl << para2 << endl;
}

int alter_para(int para1)
{
    int result = para1;

    result += result;

    return result;
}

void print_odds()
{
    for (int i = 1; i < 20; i += 2)
    {
        if (i != 1)
            cout << " ";
        
        cout << i;

    }
    cout << endl;
}

void print_rand_arr()
{
    srand(time(0));
    int randNum[5] = {};

    for (int i = 0; i < 5; i++)
    {
        randNum[i] =  rand() % 100;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << randNum[i] << endl;
    }
}

void split_string(string lString)
{
    size_t pos = 0;
    string token;
    string delimiter = " ";
    while ((pos = lString.find(delimiter)) != string::npos) {
        token = lString.substr(0, pos);
        cout << token << endl;
        lString.erase(0, pos + delimiter.length());
    }
    cout << lString << endl;
}


int main()
{
    //Create a function that accepts at least two values (simple parameter values, not user input), prints the values to screen, and returns nothing. Call this function from your main.
    cout << "T1 - Print parameters" << endl;
    print_para(5, 6);
    cout << endl;

    //Create a function that accepts one value, alters it, and returns it(simple value).Call this function from main, and print the returned value.
    cout << "T2 - Alter variable" << endl;
    cout << alter_para(4) << endl;
    cout << endl;

    //Declare a pointer to a variable, and demonstrate the setting and reading of the value in the variable using the pointer.
    cout << "T3 - Pointers and such" << endl;
    int var1 = 4;
    //Declaration
    int *point1 = &var1;

    //Test 1
    cout << "Variable: " << var1 << endl;
    cout << "Pointer: " << *point1 << endl;
    
    //Setting
    *point1 = 5;
    cout << "*point1 = 5;" << endl;
    //Reading
    cout << "Variable: " << var1 << endl;
    cout << "Pointer: " << *point1 << endl;
    cout << endl;

    //Create a function that uses a for loop to print all odd numbers between 0 and 20 on a single text line of text output, formatted with spaces. Call this from main.
    cout << "T4 - Print odd numbers" << endl;
    print_odds();
    cout << endl;
    
    //Create a function that creates a 1 - dimensional array of 5 integers, then fill the array with random int values, print the contents of the array to the screen. Call from main.
    cout << "T5 - Print array of 5 random numbers" << endl;
    print_rand_arr();
    cout << endl;

    //Split the line of text, such as “this has spaces in it”, by spaces, and show each part to screen.
    cout << "T6 - Split the line" << endl;
    split_string("this has spaces in it");
    cout << endl;

    //Declare a simple class that has at least one private variable, one public variable, and one public method.Create an instance of the class, and demonstrate its use.
    cout << "T7 - Class demo" << endl;
    DemoClass demo = DemoClass(1, 2);
    cout << demo.add_vars() << endl;
    cout << endl;
}
