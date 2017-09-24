// app.cpp : Defines the entry point for the console application.
//

/*#include "stdafx.h"*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define bsize 1024

using namespace std;

enum Moznosti {
riadky, slova
};

int Scitanie(istream &is, Moznosti mode){

	long i;
	long r = 0, n = 0;
	char buf[bsize] = {0, };

	do {
		is.read(buf, bsize);
		r = is.gcount();
		switch (mode) {
		case riadky: for (i = 0; i<r; i++)if (buf[i] == '\n')n++; break;
		case slova: return 0;
		}

	} while (r>0);

	switch (mode) {
	case riadky: cout << n + 1;
	case slova: cout << "Este nic";
	}

	/*cout << "\n";*/
	return 0;

}

int main()
{
	ifstream f;
	long i;
	Moznosti mode;
	string text;
	string moznost;
	long r = 0, n = 0;
	char buf[bsize] = { 0, };

	std::cout << "Subor alebo vstup" << std::endl;
	getline(cin, moznost);


	if(moznost =="vstup"){
		cout << "Zadajte text:" << endl;
		getline(cin, text);
		switch (mode) {
		 case riadky: for (i = 0; i < cin.gcount(); i++)if (buf[i] == '\n')n++; break;
		 }
	    switch (mode) {
	     case riadky: cout << n + 1;
			}
	}


	if (moznost == "Subor") {

		f.open("text.txt", ios::in);
		cout << Scitanie(f, riadky) << "/n";
		f.close();

		/* f.open("ten.txt", ios::in);
		cout << Scitanie(f, slova) << "/n";
		f.close();*/
	}
	return 0;
}
