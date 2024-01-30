#include <iostream>
#include <cstdlib>	//c standard library - ex. sqaure root(sqrt)
using std::cout;
using std::endl;

//------------------------ C++ static_cast ---------------------------------------------------------
//ref link:https://www.youtube.com/watch?v=M4y5KnnlDhE&list=PLRwVmtr-pp05motkiTlDIuU5ZfoRr-kWC&index=3

//static cast - (static means compile time) , not recommended in pointers
//static_cast doesnot have a runtime cost, it will just do it
//dynamic cast should be recommended in casting hierarchies, and pointers

void main()
{// casting explicitly with the type 
	int i = 25;
	//sqrt(i);	// 11 years ago this was an ERROR - i is an overloaded func, it can be long/float/double
	sqrt(static_cast<double>(i)); // this expression: it takes as int returns into a double then sqrt of the double version will be invoke
	// d1
	double d = sqrt(static_cast<double>(i));
	cout << d << endl;		// result: sqrt of 25 is 5
}

//##########################################
//class Base {};
//class Derived1 : public Base {};
//class Derived2 : public Base {};
//
//void main()
//{
//	Base* b =																		new Derived1;	// static - Compile time but in runtime it will show
//	//Derived1* d1 = b;	//error: b cant be recognize because its in static(compile time) requires static_cast
//	Derived1* d1 = static_cast<Derived1*>(b); 
//	// d1
//	Derived2* d1 = static_cast<Derived2*>(b); //<---- error: Undefined 
//	// d1	<---- error: Undefined 
//}
































// --------------------------- C++ reinterpret_cast -----------------------------------------------------
//ref link:https://www.youtube.com/watch?v=wcKXGvi1JRk&list=PLRwVmtr-pp05motkiTlDIuU5ZfoRr-kWC&index=2&t=7s

//reinterpret cast allows you to cast a pointer type into another type
//reinterpret casting - does not change the address while changing the value type of a RAM in compile time
//one thing to point out is reinterpret cast should be used keeping in mind the packing done by the compiler and if you don't want to check the packing, then just use pragma pack 1(compiler optimization won't be applied and there would be no packing)

//struct Cow		//struct defaults to public
//{
//	int mooCount;
//	int legCount;
//	char gender;
//	bool isButchered;
//};
//
//int main()
//{
//	Cow cow;		// cow contains 2x int, char, bool, packing(compiler)
//	cow.mooCount = 8; cow.legCount = 5;
//	cow.gender = 'f'; cow.isButchered = true;
//	Cow* cowPtr = &cow;		//cow pointer - address
//	//cout << cowPtr->gender;		// -> dereference
//	int* intPtr = reinterpret_cast<int*>(cowPtr);		// reinterpret_cast
//	//cout << cowPtr << endl; cout << intPtr << endl;		// Result:same address as intPtr cause of reinterpret_casting
//	//cout << intPtr << endl;	//Result: 8 <- the first value of struct Cow
//	//############################
//	//intPtr++;		//PointerArithmetic-SameAs: intPtr = intPtr + 1;
//	//intPtr = intPtr + 1;	
//	//cout << intPtr << endl;		//result: address + int size value
//	//############################
//	//cout << *intPtr << endl;	//points to mooCount value
//	//intPtr++;
//	//cout << *intPtr << endl;	// *intPtr points to legCount cause of intPtr++
//	//############################
//	intPtr += 2;
//	cout << *intPtr << endl;	// points to gender(int value)
//	cout << *reinterpret_cast<char*>(intPtr) << endl;	// points to gender(char value) and the value char is not save to char point value
//	char* charPtr = reinterpret_cast<char*>(intPtr);
//	//cout << *charPtr << endl;	// stored in charPtr value
//	charPtr++;			// *charPtr pointer move to 4 bytes
//	cout << *charPtr << endl;	// charPtr points to isButchered(charr value)
//	cout << *reinterpret_cast<bool*>(charPtr) << endl;	// charPtr points to isButchered(bool value)
//	cout << true << endl; // prove bool result of isButchered bool value
//}