#pragma once
#include <fstream>
#include "BaseTest.h"

// Prepare stage checks how much RAM user have, and if it's less than 1 GB, then exit(-1) 
// In Run stage this test create a file with random content, and remove it, when the test has done
// Clean up stage just delete this temp file

class SecondTest : public BaseTest
{
public:
	explicit SecondTest() noexcept : BaseTest() {}  // Using explicit modify because C++ 17 recomend to use it, also, inheritance constuctor from BaseTest class
	explicit SecondTest(std::string name) noexcept : BaseTest(name) {} // Using explicit modify because C++ 17 recomend to use it, also, inheritance constuctor from BaseTest class
	virtual ~SecondTest() noexcept = default;
protected:
	virtual void Prepare() override; //Override the BaseTest::Prepare() methode
	virtual void Run() override; //Override the BaseTest::Prepare() methode
	virtual void CleanUp() override; //Override the BaseTest::Prepare() methode
private:
	void FillTheFileWithRandomContent(std::ofstream& file); //Function for fill the file with random content
};

