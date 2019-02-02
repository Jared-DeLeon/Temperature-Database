#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "TemperatureDatabase.h"
#include "TemperatureData.h"

using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1
	ifstream dataIn(filename);
	if (!dataIn.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	while (!dataIn.eof()) {
		string line, location;
		int year=0, month=0;
		double temperature=0.0;
		getline(dataIn, line);
		stringstream ss(line);
		ss >> location >> year >> month >> temperature;
		if (ss.bad() || ss.fail()) {
			if (line.size() != 0) // ignore blank lines in file
				cout << "Error: Other invalid input " << line << endl;
		}
		else {
			if (temperature != -99.99) { // check for special case
				// validate inputs
				bool valid = true;
				if (!TemperatureData::validYear(year)) {
					valid = false;
					cout << "Error: Invalid year " << year << endl;
				}
				if (!TemperatureData::validMonth(month)) {
					valid = false;
					cout << "Error: Invalid month " << month << endl;
				}
				if (!TemperatureData::validTemperature(temperature)) {
					valid = false;
					cout << "Error: Invalid temperature " << temperature << endl;
				}
				if (valid)
					records.insert(location,year,month,temperature);
			}
			// else do nothing
		}
	}
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
    
    istringstream iss;//interprets line
    
    
    ofstream outData("result.dat");//output file
    if(!outData.is_open()){
        cout << "Error: Unable to open result.dat" << endl;
        exit(1);
    }
        
        ifstream inData(filename);//input file
        if (!inData.is_open()) {
            cout << "Error: Unable to open " << filename << endl;
            exit(1);
        }
            
            while(!inData.eof()){
                
                string ID;//instantiate intermediate variables
                string query;
                int startYear = 0;
                int endYear = 0;
                
                string lineString;//holds string of line
                getline(inData,lineString);
                
                
                iss.clear();//clear istringstream
                stringstream iss(lineString);//create string stream with the get line string
                iss >> ID >> query >> startYear >> endYear;//input things from iss into variables
                
                if(!iss.bad() && !iss.fail()){//if stream has no error
                    if(endYear <= 2018 && startYear >= 1800 && startYear<=endYear){//check the year is it within ranvge? is start < end?
                        
                        if(query == "AVG"){//if AVG is query
                            outData << ID <<" " << startYear << " " << endYear << " AVG "<< records.getAVG(ID, startYear,endYear)<<endl;
                        }
                        else if(query == "MODE"){//if MODE is query
                            outData << ID <<" " << startYear << " " << endYear << " MODE "<< records.getMODE(ID, startYear,endYear)<<endl;
                        }
                        else {//anything else
                            cout << "Error: Unsupported query " << query << endl;
                        }
                        
                    }else{//if year has an error
                        cout << "Error: Invalid range "<< startYear << "-" <<endYear<<endl;
                    }
                }else{
                    if (lineString.size() != 0) // ignore blank lines in file
                        cout << "Error: Other invalid query"<<endl;
                    
                }
            }
    
	//  Leave it blank for part 1
}

void TemperatureDatabase::myTest() {
}
