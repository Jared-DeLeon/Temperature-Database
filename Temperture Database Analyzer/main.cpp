#include "TemperatureDatabase.h"

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	if (argc < 3) {
		cout << "Usage: " << argv[0] << " data_file query_file" << endl;
		return 1;
	} else {
		//cout << argv[1] << " - " << argv[2] << endl;
		TemperatureDatabase database;
		database.loadData(argv[1]);
		//database.myTest();
		database.performQuery(argv[2]); // Will be done in Part 2
	}
}
