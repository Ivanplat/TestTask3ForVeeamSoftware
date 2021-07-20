#include "FirstTest.h"
#include "SecondTest.h"

//This project maded as test task for Veeam Software on work possition QA Atomation Engineer
//Autor: Ivan Platonov
//E-Mail: Ivanplateam@gmail.com

// Program is the unit tests

int main()
{

 
	FirstTest ft("FirstTest");
	ft.Execute();

	SecondTest st("st");
	st.Execute();
	
	return 0;
}