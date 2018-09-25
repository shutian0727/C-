#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {
	class Contact {
		char name[20];
		long long* phone;
		int pn;
		bool validate(const long long Phone);
	public:
		Contact();
		Contact(const Contact& src);
		Contact& operator=(const Contact& src);
		Contact& operator+=(long long Phone);
		Contact(const char* Name, const long long* Phone, int PN);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};
}

#endif // SICT_CONTACT_H
