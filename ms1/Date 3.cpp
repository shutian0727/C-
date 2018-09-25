#include <iostream>
#include "Date.h"

namespace AMA {

	// number of days in month mon and year year_
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}


	void Date::errCode(int errCode) {
		if (errCode >0 && errCode <5) dateErr = errCode;
		else dateErr = 0;
	}

	Date::Date(){
		dateYear = 0;
		dateMonth = 0;
		dateDay = 0;
		dateCom = 0;
		dateErr = 0;
	}

	Date::Date(int year_, int month_, int day_) {
		int err = 0;
		if (year_ < min_year || year_ > max_year)	err = 2;
		else if (month_ < 1 || month_ > 12)		err = 3;
		else if (day_ < 1 || day_ > mdays(month_, year_))	err = 4;

		if (err == 0) {
			dateYear = year_;
			dateMonth = month_;
			dateDay = day_;
			dateCom = year_ * 372 + month_ * 13 + day_;
			dateErr = 0;
		}
		else {
			dateYear = 0;
			dateMonth = 0;
			dateDay = 0;
			dateCom = 0;
			dateErr = err;
		}
	}

	bool Date::operator== (const Date& rhs) const {
		if (dateCom == rhs.dateCom)	return 1;
		else return 0;
	}

	bool Date::operator!= (const Date& rhs) const {
		if (dateCom != rhs.dateCom)	return 1;
		else return 0;
	}

	bool Date::operator< (const Date& rhs) const {
		if (dateCom < rhs.dateCom)	return 1;
		else return 0;
	}

	bool Date::operator>(const Date& rhs) const {
		if (dateCom > rhs.dateCom)	return 1;
		else return 0;
	}

	bool Date::operator<= (const Date& rhs) const {
		if (dateCom <= rhs.dateCom)	return 1;
		else return 0;
	}

	bool Date::operator>= (const Date& rhs) const {
		if (dateCom >= rhs.dateCom)	return 1;
		else return 0;
	}

	int Date::errCode() const {
		return dateErr;
	}

	bool Date::bad() const {
		return dateErr != 0;
	}

	void Date::read(std::istream& istr) {
		bool yes = 0;
		int year_, month_, day_;
		istr >> year_;
		istr.get();
		istr >> month_;
		istr.get();
		istr >> day_;
		istr.clear();

		if (year_ < 0 || year_>9999) yes = 1;
		else if (month_ < 0 || month_>99) yes = 1;
		else if (day_ < 0 || day_>99) yes = 1;
		else;

		if (yes ==0) {
			Date temp(year_, month_, day_);
			*this = temp;
		}
		else {
			errCode(1);
			istr.fail();
		}
	}

	void Date::write(std::ostream& ostr) const {
		ostr.fill('0');
		ostr << dateYear << "/";
		ostr.width(2);
		ostr << dateMonth << "/" ;
		ostr.width(2);
		ostr << dateDay;
	}

	std::ostream& operator<<(std::ostream& ostr, const Date& date) {
		date.write(ostr);
		return ostr;
	}

	std::istream& operator >> (std::istream& istr, Date& date) {
		date.read(istr);
		return istr;
	}
}
