// MultithreadinginCplusplus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
using namespace std;


class class_for_launching_a_thread {

public:

	void operator()(int x) {

		cout << "We are in class class_for_launching_a_thread, function operator() " << x << "\n";
	}

	void print_x( int x, int z ) {

		cout <<"We are in class class_for_launching_a_thread, print_x() " << x <<" "<< z << "\n";
	}
};


void my_first_thread(int x) 
{
	cout << "We are in function my_first_thread() \n";
}

int main()
{
	int y = 8;
	int a = 99;

	//here we define a thread named "threadul" which is launched using 
	// the function my_first_thread with the integer parameter
	thread threadul(my_first_thread, y);
	threadul.join();


	//here we define a thread named "threadul_class" which is launched using 
	// the class class_for_launching_a_thread with the integer parameter
	thread  threadul_class(class_for_launching_a_thread(), y);
	threadul_class.join();

	//here we define a thread named "threadul_class_function" which is launched using 
	// the class class_for_launching_a_thread with the function print_x, an object (instance of the class)
	// and the two parameters from print_x function, in our case 2 integers
	thread  threadul_class_function(&class_for_launching_a_thread::print_x, class_for_launching_a_thread(), y, a);
	threadul_class_function.join();

}

