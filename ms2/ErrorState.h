/*
ErrorState.h
Name: Shutian Xu
Student ID: 109783175
E-mail: sxu61@myseneca.ca
*/
#ifndef SICT_ERROR_STATEE_H__
#define SICT_ERROR_STATE_H__

#include <iostream>
namespace AMA {
	class ErrorState {
		char* message_;

	public:
		// constructors
		ErrorState(const char* erroMessage = nullptr);
		ErrorState(const ErrorState& em) = delete;
		// Public member functions and operator overloads
		ErrorState& operator=(const ErrorState& em) = delete;
		virtual ~ErrorState();// destructuor
		void clear(); //De - allocates the memory pointed by message
		bool isClear() const; //Check whether message_ is nullptr or not
		void message(const char* str);// message_ setter
		const char* message()const;// return message
	};
	    //Helper operator <<
		std::ostream& operator<<(std::ostream& ostr, const ErrorState& em);

	

}
#endif
