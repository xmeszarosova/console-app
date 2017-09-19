// app.cpp : Defines the entry point for the console application.
//

#include <iostream>

int main()
{
	File*subor;
	std::cout << "Hello zadania!" << std::endl;
	char prepinac;

	StreamReader* subor = new StreamReader("c:\\text.txt");
	String *riadok = "";
	ArrayList *text = new ArrayList();

	std::cout << "Prosim zvolte prepinaca: c, w, l" << std::endl;
	std::cin >> prepinac;

	if (prepinac == "l") {
		riadok = subor->ReadLine(); while (riadok != 0)
		{
			text->Add(riadok);
			riadok = subor->ReadLine(); <BR / >
		}
	}

	subor->Close();

	return 0;
}
