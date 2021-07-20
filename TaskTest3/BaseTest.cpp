#include <sstream>
#include <filesystem>
#include <fstream>
#include "BaseTest.h"

int BaseTest::Count = 0; // Initiliaze static varialbe BaseTest::Count 

void BaseTest::Execute()
{ //Execute methode
	Prepare(); // Call protected Prepare() methode
	Run(); // Call protected Run() methode
	CleanUp(); // Call protected CleanUp() methode
}

const void BaseTest::PrintToLog(LoggingType lt, std::string str) noexcept
{
	GetLocalTime(); // Call private GetLocalTime() metode
	std::string type; // Create string for next using
	switch (lt) // switch on LoggingType
	{
	case LoggingType::ERR:		type = "ERROR: ";	break; //File the type = "ERROR: "
	case LoggingType::WARNING:  type = "WARNING: "; break; //File the type = "WARNING: "
	case LoggingType::OK:		type = "OK: ";		break; //File the type = "OK: "
	}

	if (!std::filesystem::is_directory(std::filesystem::current_path().string() + "/log")) // Check does /log directory exist
	{
		std::filesystem::create_directory(std::filesystem::current_path().string() + "/log"); // If not, create it
	}
	std::ofstream ofile(std::filesystem::current_path().string() + "/log/"+ std::to_string(tc_id) +"_"+ name +  "_log.txt", std::ios::app); // Create (id)_(name)_log.txt file
	std::stringstream ss; // Create stringstream for next using
	ss<< "LOG " << type << ": " << str << "\t" << asctime(timeinfo) << std::endl; //Fill the string stream
	ofile.write(ss.str().c_str(), ss.str().size()); // Write to the log file
	ofile.close(); // Close the file
}

const void BaseTest::PrintToConsole(LoggingType lt, std::string str) noexcept
{
	GetLocalTime(); // Call private GetLocalTime() metode
	std::string type; // Create string for next using
	switch (lt) // switch on LoggingType
	{
	case LoggingType::ERR:		type = "ERROR: ";	break; //File the type = "ERROR: "
	case LoggingType::WARNING:  type = "WARNING: "; break; //File the type = "WARNING: "
	case LoggingType::OK:		type = "OK: ";		break; //File the type = "OK: "
	}
	std::cout << "LOG "<<type<<": " << str <<"\t"<<asctime(timeinfo)<<std::endl; //Print log to console
}

const void BaseTest::PrintToBoth(LoggingType lt, std::string str) noexcept
{
	PrintToConsole(lt, str); //Print to console
	PrintToLog(lt, str); // Print to log
}

void BaseTest::GetLocalTime()
{
	time(&rawtime); // Fill the time variable
	timeinfo = localtime(&rawtime); // Fill the tm* stucture
}
