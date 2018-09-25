/*
ErrorState.cpp
Name: Shutian Xu
Student ID: 109783175
E-mail: sxu61@myseneca.ca
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "ErrorState.h"

using namespace std;

namespace AMA {

	ErrorState::ErrorState(const char* erroMessage)
	{
		if (erroMessage == nullptr) {
			message_ = nullptr;
		} else {
			message_ = nullptr;
			message(erroMessage);
		}
	}

	ErrorState::~ErrorState()
	{
		delete[] message_;
	}
	void ErrorState::clear()
	{
		delete[] message_;
		message_ = nullptr;
	}
	
	// message_ setter
	void ErrorState::message(const char* str)
	{
		clear(); // deallocate original memory
		message_ = new char[strlen(str) + 1];
		strcpy(message_, str);
	}

	const char* ErrorState::message() const
	{
		return message_;
	}
	bool ErrorState::isClear() const
	{
		bool rv;
		if (message_ == nullptr)

			 rv = true;
		else
			rv = false;
		return rv;
	}


	std::ostream& operator<<(std::ostream& ostr, const ErrorState& em)
	{
		if (!em.isClear())

			ostr << em.message();
		return ostr;

	}


}
