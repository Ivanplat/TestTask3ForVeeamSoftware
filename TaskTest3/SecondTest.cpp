#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <filesystem>
#include "SecondTest.h"

// Documentation of memory: https://docs.microsoft.com/ru-ru/windows/win32/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex?redirectedfrom=MSDN
#define DIV 1024 // From documentation

void SecondTest::Prepare()
{
    PrintToBoth(LOK, "SecondTest::Prepare()"); // Print to log
    MEMORYSTATUSEX statex; // Create MEMORYSTATUSEX varialbe
    statex.dwLength = sizeof(statex); // Define the size of statex
    GlobalMemoryStatusEx(&statex); //Get RAM status
    PrintToBoth(LOK, "There are" + std::to_string(statex.ullTotalPhys) + " total KB of physical memory"); // Print to log
    if (statex.ullTotalPhys < 1048576) // Check is that egnouth RAM to complete the test
    {
        PrintToBoth(LERR, "There are not enough memory to run the test!"); //Print error to log
        PrintToBoth(LERR, "Exit!"); //Print error to log
        exit(-1); //Exit from test
    }
}

void SecondTest::Run()
{
    PrintToBoth(LOK, "SecondTest::Run()"); // Print to log
    if (!std::filesystem::is_directory(std::filesystem::current_path().string() + "/temp")) // Check does temp folder exist
    {
        PrintToBoth(LOK, "temp folder does not exist... Creating!"); // Print to log
        std::filesystem::create_directory(std::filesystem::current_path().string() + "/temp/"); // If not, we create a new temp folder
    }
    PrintToBoth(LOK, "Create a test file!"); // Print to log
    std::ofstream file(std::filesystem::current_path().string() + "/temp/test.txt", std::ios::app); // Create a test.txt file in temp folder
    FillTheFileWithRandomContent(file);
}

void SecondTest::CleanUp()
{
    PrintToBoth(LOK, "SecondTest::CleanUp()"); // Pring to log
    if (!std::filesystem::remove(std::filesystem::current_path().string() + "/temp/test.txt")) // Trying to delete our temp/test.txt file
    {
        PrintToBoth(LERR, "Can not delete file!");  //Print error to log
        PrintToBoth(LERR, "Exit!"); //Print error to log
        exit(-1); // Exit from test
    }
    PrintToBoth(LOK, "File succsecsfuly deleted!"); // Print to log
}

void SecondTest::FillTheFileWithRandomContent(std::ofstream& file)
{
    PrintToBoth(LOK, "SecondTest::FillTheFileWithRandomContent(std::ofstream& file)"); // Print to log
    for (int i = 0; i < 1024; i++) // We need to create a file with random context with 1024kb size
    {
        int r = std::rand() % (127 - 32 + 1); //Get random number in range from [32;127]
        char c = static_cast<char>(r); //Make a char from this integer number
        std::string str(&c); // Create a string with only one character for next using
        file.write(str.c_str(), 1); // Fill the file
    }
    PrintToBoth(LOK, "File is filled with random content!"); // Pring to log
}
