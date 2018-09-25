
#ifndef AMA_DATE_H
#define AMA_DATE_H
#define min_year 2000
#define max_year 2030
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4	

namespace AMA {

  class Date {
  private:
	long dateYear;
	long dateMonth;
	long dateDay;
	int dateCom;
	int dateErr;
    int mdays(int month, int year)const;	
	void errCode(int errCode);	
 
  public:
	Date();
	Date( int year_, int month_, int day_);
	bool operator== (const Date& rhs) const;
	bool operator!= (const Date& rhs) const;
	bool operator< (const Date& rhs) const;
	bool operator> (const Date& rhs) const;
	bool operator<= (const Date& rhs) const;
	bool operator>= (const Date& rhs) const;
	int errCode() const;
	bool bad() const;
	void read(std::istream& istr);
	void write(std::ostream& ostr) const;
};
	std::ostream& operator<<(std::ostream& ostr, const Date& date);
	std::istream& operator>>(std::istream& istr, Date& date);
}
#endif