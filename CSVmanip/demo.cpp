#include "CSVReader.h"
#include "CSVWriter.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
using namespace ynym::util;
int main() {
	vector<string> words;

	try {

		CSVReader csv("test.csv");

		while (!csv.eof()) {
			words = csv.parseLine();
		}

	} catch (std::runtime_error& err) {
		cout << "ERROR!\n" << err.what() << endl;
	}


	try {
		CSVWriter csv("test2.csv");

		csv.writeLine(words);
	} catch (std::runtime_error& err) {
		cout << "ERROR!\n" << err.what() << endl;
	}


	for (auto s : words) {
		cout << s << endl;
	}



	return 0;
}