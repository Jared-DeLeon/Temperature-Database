/*
 * TemperatureData.cpp
 *
 *  Created on: Jul 16, 2018
 *      Author: student
 */
#include <iostream>
#include <ctime>
#include "TemperatureData.h"
using namespace std;

TemperatureData::TemperatureData() : year(0), month(0), temperature(-99.99) {} //initialize everything

TemperatureData::TemperatureData(std::string id, int year, int month, double temperature) :
	id(id), year(year), month(month), temperature(temperature) {} //initialize everything


TemperatureData::~TemperatureData() {} // You should not need to implement this

bool TemperatureData::operator<(const TemperatureData& b) {
	// Implement this
	if (this->id < b.id) return true;
	else if (this->id == b.id) {
		if (this->year < b.year) return true;
		else if (this->year == b.year) {
			if (this->month < b.month) return true;
		}
	}
	return false;
}

bool TemperatureData::validYear(int year) {
	time_t t = time(0);
	tm* now = localtime(&t);
	int curYear = now->tm_year+1900;
	return (year >= 1800 && year <= curYear);
}

bool TemperatureData::validMonth(int month) {
	return (month >= 1 && month <=12);
}

bool TemperatureData::validTemperature(double temperature) {
	return (temperature >= -50.0 && temperature <= 50.0);
}
