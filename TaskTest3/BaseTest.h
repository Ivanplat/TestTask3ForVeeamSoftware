#pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include <ctime>

#include "Data.h"

class BaseTest
{
public:
	explicit BaseTest() noexcept : name("basename"), timeinfo(nullptr), rawtime(NULL), tc_id(Count + 1) { Count++; }  // Using explicit modify because C++ 17 recomend to use it
	explicit BaseTest(std::string name) noexcept : name(name), timeinfo(nullptr), rawtime(NULL), tc_id(Count+1){ Count++; } // Using explicit modify because C++ 17 recomend to use it
	virtual ~BaseTest() noexcept = default;
	void Execute(); //Execute() methode
public:
	static int Count; // Create a static variable for id generator
protected:
	virtual void Prepare() = 0; // Pure virtual methode Prepare()
	virtual void Run() = 0; // Pure virtual methode Run()
	virtual void CleanUp() = 0; // Pure virtual methode CleanUp()
	const void PrintToLog(LoggingType lt,std::string str) noexcept; // Methode for logging
	const void PrintToConsole(LoggingType lt, std::string str) noexcept; // Methode for logging
	const void PrintToBoth(LoggingType lt, std::string str) noexcept; // Methode for logging
private:
	void GetLocalTime(); // Get user's local time
private:
	int tc_id; // Id of the test
	std::string name; // Name of the test
private:
	time_t rawtime; // Variable for logging (time)
	struct tm* timeinfo; // Struct for logging (time)
};