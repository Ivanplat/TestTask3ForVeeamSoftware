#include <filesystem>
#include "FirstTest.h"

void FirstTest::Prepare()
{
    PrintToBoth(LOK, "FirstTest::Prepare()"); // Print to log
    time_t sec; // Create time_t varible
    time(&sec); // Get current local time
    if (sec % 2 != 0) // Check, is local time even
    { //If not
        PrintToBoth(LERR, "The time is not even!"); // Print error to log
        PrintToBoth(LERR, "Exit!"); // Print error to log
        exit(-1); // Exit
    }
    PrintToBoth(LOK, "The time is even!"); // Print to log
}

void FirstTest::Run()
{
    PrintToBoth(LOK, "FirstTest::Run()"); // Print to log
    char* homeDirectory = getenv("HOMEDRIVE"); // Get user's home directory
    std::stringstream ss; // Make stringstream for next using
    ss <<"The home directory is " << homeDirectory; // Fill the stringsteam
    PrintToBoth(LOK, ss.str()); // Print to log
    PrintListOfFilesInDirectory(homeDirectory); // Print the list of files
    
}

void FirstTest::CleanUp()
{
    PrintToBoth(LOK, "FirstTest::CleanUp()"); // Print to log
}

const void FirstTest::PrintListOfFilesInDirectory(std::string Path) noexcept
{
    Path.push_back('/'); // Add to path string '/' (only localy!!! because Path is not a reference, just a copy!!!) 
    for (const auto& i : std::filesystem::directory_iterator(Path)) //Get all files
    {
        PrintToBoth(LOK, i.path().string()); // Print files to log
    }
}
