#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class T {
	char *first { };
	char *last { };
public:
	T();
	T(char*);
	T(char*, char*);
	T(const T&);
	~T();

	const char* get_first();
	const char* get_last();
	void set_first(const char*);
	void set_last(const char*);

	friend ostream& operator<<(ostream&, const T&);
	friend istream& operator>>(istream&, T&);
};

T::T(char *f, char *l) :
		first { f ? new char[strlen(f) + 1] : nullptr }, last {
				l ? new char[strlen(l) + 1] : nullptr } {
	if (first)
		strcpy(first, f);
	if (last)
		strcpy(last, l);
}

T::T(char *f) :
		T(f, "Doe") {
}

T::T() :
		T("John", "Doe") {
}

T::T(const T &t) {
	this->first = t.first ? new char[strlen(t.first) + 1] : nullptr;
	this->last = t.last ? new char[strlen(t.last) + 1] : nullptr;
	if (first)
		strcpy(this->first, t.first);
	if (last)
		strcpy(this->last, t.last);
}

T::~T() {
	if (this->first)
		delete[] this->first;
	if (this->last)
		delete[] this->last;
}

const char* T::get_first() {
	return this->first;
}

const char* T::get_last() {
	return this->last;
}

void T::set_first(const char *c) {
	if (this->first)
		delete[] this->first;
	this->first = new char[strlen(c) + 1];
	strcpy(this->first, c);
}

void T::set_last(const char *c) {
	if (this->last)
		delete[] this->last;
	this->last = new char[strlen(c) + 1];
	strcpy(this->last, c);
}

ostream& operator<<(ostream &out, const T &t) {
	out << t.first << " " << t.last;
	return out;
}

istream& operator>>(istream &in, T &t) {
	in >> t.first >> t.last;
	return in;
}

int main() {
	T t("Nabuhdonazsoriusz", "Methusellahliver");
	cout << t << endl;
	cin >> t;
	cout << t << endl;
	T t2 { "James" };
	cout << t2 << endl;
	return 0;
}
