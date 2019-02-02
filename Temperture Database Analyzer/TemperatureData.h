/*
 * TemperatureData.h
 *
 *  Created on: Jul 16, 2018
 *      Author: student
 */

#ifndef TEMPERATUREDATA
#define TEMPERATUREDATA
#include <string>

struct TemperatureData {
	// Put data members here
	std::string id;
	int year;
	int month;
	double temperature;
	TemperatureData();
	TemperatureData(std::string id, int year, int month, double temperature);
	virtual ~TemperatureData();
	bool operator<(const TemperatureData& b);
	static bool validYear(int year);
	static bool validMonth(int month);
	static bool validTemperature(double temperature);
};

#endif /* TEMPERATUREDATA */
