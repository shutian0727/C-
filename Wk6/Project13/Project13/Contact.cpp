#include <iostream>
#include <cstring>
#include "Contact.h"
#include <iomanip>

using namespace std;

namespace sict {

	Contact::Contact() {
		name[0] = '\0';
		phone = nullptr;
		pn = 0;
	}
	Contact::Contact(const char* Name, const long long* Phone, int PN) {
		int j = 0;

		name[0] = '\0';
		phone = nullptr;
		pn = 0;

		// Validate the input of name and phone number
		if (Name != nullptr && strcmp(Name, "") != 0 && Phone != nullptr) {
			// Calculate the number of valid phone numbers
			for (int i = 0; i < PN; i++) {
				if (validate(Phone[i]))
					pn++;
			}

			phone = new long long[pn];
			strncpy(name, Name, 20);
			name[19] = '\0';

			for (int i = 0; i < PN; i++) {
				if (validate(Phone[i])) {
					phone[j] = Phone[i];
					j++;
				}
			}

		}
		else if (Name != nullptr && strcmp(Name, "") != 0) {
			strncpy(name, Name, 20);
			name[19] = '\0';
		}

	}
	Contact::~Contact() {
		delete[] phone;
	}

	bool Contact::validate(const long long Phone) {
		bool rv = false;
		int countryCode;
		int areaCode;
		int phoneNumber;

		if (Phone >= 10000000000 && Phone <= 999999999999) { // Validate the number has 11~12 digits
			countryCode = Phone / 10000000000;
			areaCode = Phone % 10000000000 / 10000000;
			phoneNumber = Phone % 10000000;

			if (countryCode >= 1 && countryCode <= 99 && areaCode >= 100 && areaCode <= 999 &&
				phoneNumber >= 1000000 && phoneNumber <= 9999999) // Validate each field's number of digits
				rv = true;
		}
		else
			rv = false;

		return rv;
	}

	bool Contact::isEmpty() const {
		bool rv;

		if (name[0] == '\0')
			rv = true;
		else
			rv = false;

		return rv;
	}

	void Contact::display() const {
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << name << endl;
			if (phone != nullptr) {
				for (int i = 0; i < pn; i++) {
					cout << "(+" << phone[i] / 10000000000 << ") ";
					cout << phone[i] % 10000000000 / 10000000 << " ";
					cout << phone[i] % 10000000 / 10000 << "-";
					cout << setfill('0') << setw(4) << (int)(phone[i] % 10000) << endl;
				}
			}
		}
	}

	Contact::Contact(const Contact& src) {
		strncpy(name, src.name, 20);
		name[19] = '\0';
		pn = src.pn;

		if (src.phone != nullptr) {
			phone = new long long[pn];

			for (int i = 0; i < pn; i++)
				phone[i] = src.phone[i];
		}
		else {
			phone = nullptr;
		}
	}

	Contact& Contact::operator=(const Contact& src) {
		if (this != &src) {
			strncpy(name, src.name, 20);
			name[19] = '\0';
			pn = src.pn;
			delete[] phone;

			if (src.phone != nullptr) {
				phone = new long long[pn];

				for (int i = 0; i < pn; i++)
					phone[i] = src.phone[i];

			}
			else {
				phone = nullptr;
			}
		}

		return *this;
	}

	Contact& Contact::operator+=(long long Phone) {
		bool valid = validate(Phone);

		if (valid) {
			long long* temp = nullptr;
			temp = new long long[pn + 1];

			for (int i = 0; i < pn; i++)
				temp[i] = phone[i];

			temp[pn] = Phone;
			pn++;
			delete[] phone;
			phone = temp;
		}

		return *this;
	}
}
































