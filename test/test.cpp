// test.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>

#include <iterator>

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#define bsize 1024
using namespace std;

enum Moznosti {
	riadky, slova, znaky
};

int Scitanie(std::istream &is, Moznosti mode) {
	short inw;
	long i;
	long r = 0, n = 0;
	char buf[bsize] = { 0, };

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
	case riadky:std::cout<< n + 1;
	case slova: std::cout << n;
	case znaky: std::cout << n;
	}

	std::cout<< "\n";
	return 0;

}
int TEST_METHOD(std::istream &is, Moznosti mode)
{

	std::ifstream ifs;
	int c;

	ifs.open("text.txt", std::ios::in);
	if (Scitanie(ifs, slova) == 35) {
		std::cout<<"pocet slov sedi";
		ifs.close();
	}

	ifs.open("text.txt", std::ios::in);
	if (Scitanie(ifs, riadky) == 10) {
		std::cout << "riadky su v poriadku";
		ifs.close();
	}

	ifs.open("text.txt", std::ios::in);
	if (Scitanie(ifs, znaky) == 187) {
		std::cout << "pocet znakov";
		ifs.close();
	}

}

template<typename T>
size_t poc(istream &s)
{	return distance(istream_iterator<T>(s), istream_iterator<T>());
}
struct Line : public std::string {};

std::istream & operator >> (std::istream & stream, Line & line) {
	std::getline(stream, line);
	return stream;
}

std::stringstream test1("Toto je zadanie.\n A nie som ista ze mam to dobre");
std::stringstream test2("Tvorba Softverovych systemov.");
std::stringstream test3("Tvorba Softverovych systemov.");

TEST_CASE("Prebehia kontrola", "[poc]") {
	REQUIRE(pocitadlo<Line>(test1) == 2);
	REQUIRE(pocitadlo<char>(test2) == 27);
	REQUIRE(pocitadlo<string>(test3) == 3);
}