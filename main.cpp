// app.cpp : Defines the entry point for the console application.
//

/*#include "stdafx.h"*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>


#define bsize 1024

using namespace std;

enum Moznosti {
riadky, slova, znaky
};

int Scitanie(istream &is, Moznosti mode){
	short inw;
	long i;
	long r = 0, n = 0;
	char buf[bsize] = {0, };

	do {
		is.read(buf, bsize);
		r = is.gcount();
		switch (mode) {
		case riadky: for (i = 0; i<r; i++)if (buf[i] == '\n')n++; break;
		case slova:for (i = 0; i<r; i++)
			if ((buf[i] >= 'a' && buf[i] <= 'z') || (buf[i] >= 'A' && buf[i] <= 'Z'))inw = 1;
			else { if (inw) { n++; inw = 0; } }
			break;
		case znaky: n += r; break;
		}

	} while (r>0);

	switch (mode) {
	case riadky: cout << n + 1;
	case slova: cout << n;
	case znaky: cout << n;
	}

	cout << "\n";
	return 0;

}

int main(int argc, char **argv)
{
	ifstream f;
	long i;
	Moznosti mode;
	string text;
	string moznost;
	char *fname;
	long r = 0, n = 0;
	char buf[bsize] = { 0, };

/*	std::cout << "Subor alebo vstup" << std::endl;
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

		 f.open("ten.txt", ios::in);
		cout << Scitanie(f, slova) << "/n";
		f.close();
	}
	return 0;*/


	switch (argc) {
	case 3:
		if (argv[1][0] == '-') {
			switch (argv[1][1]) {
			case 'l':mode = riadky; break; 
			case 'w':mode = slova; break;
			case 'c':mode = znaky; break;
			
			default:
				std::cerr << "nespravne argumenty\n\n";
				return -1;
			}

			f.open(fname, ios::in);
			if (!f) {
				std::cerr << "chyba otvarania\n";
				return -1;
			}

			cout << Scitanie(f, mode);

		}
		else {
			std::cerr << "nespravne argumenty\n\n";
			return -1;
		}
		break;

	default:
		std::cerr << "nespravne argumenty\n\n";
		return -1;
	}

}
