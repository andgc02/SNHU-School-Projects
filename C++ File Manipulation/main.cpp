#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class FileManipulation {
	public:
		void OpenFile(); //open FahrenheitTemperature.txt
		void CreateFile(); //create new CelsiusTemperature.txt

		void ReadFile();
		void WriteFile();
		void CalculateCelsius();
	private:
		ifstream inFS; //input file stream
		ofstream outFS; //output file stream

		string fileString;
		int fileNum;

		vector<string> cities; //vector to store fileString
		vector<int> temperatures; //vector to store fileNum

		int i;

};

void FileManipulation::OpenFile() {
	inFS.open("FahrenheitTemperature.txt");
}

void FileManipulation::CreateFile() {
	outFS.open("CelsiusTemperature.txt");
}

void FileManipulation::ReadFile() {
	if (!inFS.is_open()) { //create error if file could not be opened
		cout << "Could not open text file." << endl;
	}
	while (!inFS.eof()) { //iterate through the file until the end
		inFS >> fileString;
		cities.push_back(fileString); //add fileString to cities vector

		inFS >> fileNum;
		temperatures.push_back(fileNum);//add fileNum to temperatures vector
	}
	inFS.close();
}

void FileManipulation::WriteFile() {
	if (!outFS.is_open()) { //create error if new file could not be created
		cout << "Could not create text file." << endl;
	}
	for (i = 0; i < temperatures.size(); i++) { //iterate through both vectors since they are the same size
		outFS << cities.at(i) << " " << temperatures.at(i) << endl; //add items of vector to new file
	}
}

void FileManipulation::CalculateCelsius() {
	for (i = 0; i < temperatures.size(); i++) { //change all fahrenheit integers in temperatures to celsius
		temperatures.at(i) = (temperatures.at(i) - 32) * 5 / 9;
	}
	outFS.close();
}


int main() {

	FileManipulation file1;

	file1.OpenFile();
	file1.ReadFile();
	file1.CalculateCelsius();
	file1.CreateFile();
	file1.WriteFile();

	cout << "New File Successfully Created" << endl;

	return 0;
}