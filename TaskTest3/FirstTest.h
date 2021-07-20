#pragma once
#include "BaseTest.h"

// Prepare stage checks is local time is even, and if it is not, then exit(-1) 
// In Run stage this test get all files in user's home directory and print them
// Clean up does not do nothing

class FirstTest : public BaseTest
{
public:
	explicit FirstTest() noexcept : BaseTest() {} // Using explicit modify because C++ 17 recomend to use it, also, inheritance constuctor from BaseTest class
	explicit FirstTest(std::string name) noexcept : BaseTest(name) {} // Using explicit modify because C++ 17 recomend to use it, also, inheritance constuctor from BaseTest class
	virtual ~FirstTest() noexcept = default;
protected:
	virtual void Prepare() override; //Override the BaseTest::Prepare() methode
	virtual void Run() override; //Override the BaseTest::Run() methode
	virtual void CleanUp() override; //Override the BaseTest::CleanUp() methode
private:
	const void PrintListOfFilesInDirectory(std::string Path) noexcept; //Function for print list of liles in directory
};

