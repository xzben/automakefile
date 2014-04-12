#include"classA.h"
#include<header.h>
#include<iostream>
using namespace std;

int main()
{
	int a = 10;
	int b = 20;
#ifdef LINUX_MACRO
	cout << "linux macro"<<endl;
#endif
	cout << MAX(a, b) << endl;
	
	ClassA *pObj = new ClassA;
	pObj->print();
	
	SAFE_DELETE(pObj);
	return 0;
}
