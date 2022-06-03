#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <stdexcept>
#include <fstream>

using namespace std;



/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

void Histogram() {
	ifstream inFS;
	string item;
	int itemOccurence;
	cout << "Opening frequency.dat from C++" << endl;
	inFS.open("frequency.dat");

	if (!inFS.is_open()) {
		throw runtime_error("Could not open frequency.dat");
	}

	while (!inFS.fail()) {
		int x = 0;
		inFS >> item;
		inFS >> itemOccurence;
		cout << item << " ";

		for (x = 0; x < itemOccurence; x++)
		{
			cout << "*";
		}
		cout << endl;
	}

	if (!inFS.eof()) {
		throw runtime_error("Failure before reaching end of file.");
	}
	cout << "Closing frequency.dat" << endl;
	inFS.close();

}

void menu(int userChoice, string item) {
	try
	{
		do
		{
			cout << "***************************************************************" << endl;
			cout << "1: Make list of all items purchased in a day and how many times" << endl;
			cout << "2: Show how many times a specific item was purchased in a day" << endl;
			cout << "3: Create histogram of all items purchased and how many times (this will produce a file)" << endl;
			cout << "4: Exit" << endl;
			cout << "***************************************************************" << endl;
			cin >> userChoice;
			
			if (cin.fail()) {
				throw runtime_error("Invalid selection; Please input a number");
			}
			switch (userChoice)
			{
			case 1:
				CallProcedure("ListItemFreq");
				break;
			case 2:
				cout << "Type the item you want to count: ";
				cin >> item;
				cout << "This item occurs: " << callIntFunc("SingleItemFreq", item) << " times" << endl;
				break;
			case 3:
				CallProcedure("Frequency");
				Histogram();
				break;
			case 4:
				break;
			default:
				break;
			}
		} while (userChoice != 4);
	}
	catch (runtime_error& excpt)
	{
		cout << excpt.what() << endl;
		cout << "Please run program again" << endl;
	}
}



void main()
{
	string item = "";
	int menuSelection = 0;
	menu(menuSelection, item);
}
