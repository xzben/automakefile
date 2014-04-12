#include"classA.h"
#include<iostream>
using namespace std;

ClassA::ClassA()
{
	cout<<"construct"<<endl; 	
}

ClassA::~ClassA()
{
	cout<<"destruct"<<endl;
}

void ClassA::print()
{
#ifdef LINUX_MACRO
	cout<< "LINUX_MACRO" <<endl;
#endif//LINUX_MACRO

#ifdef LINUX_MACRO_TWO
	cout<< "LINUX_MACRO_TWO" <<endl;
#endif
	cout<< "print" <<endl;
}

