#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "string_set.h"

using namespace std;

int main() {
	string_set string_set0;
	const char *s;

	cout << "adding \"e\"" << endl;
	string_set0.add("e");

	cout << "adding \"f\"" << endl;
	string_set0.add("f");

	cout << "adding \"df\"" << endl;
	string_set0.add("df");

	cout << "\niterate to end" << endl;
	s = string_set0.next();

	cout << "\tnext returns |" << s << "|" << endl;
	s = string_set0.next();
	cout << "\tnext returns |" << s << "|" << endl;
	s = string_set0.next();
	cout << "\tnext returns |" << s << "|" << endl;
	s = string_set0.next();
	if (s == NULL) {
		cout << "\tnext returns NULL" << endl;
	} else {
		cout << "\tnext returns |" << s << "|" << endl;
	}
	s = string_set0.next();
	if (s == NULL) {
		cout << "\tnext returns NULL" << endl;
	} else {
		cout << "\tnext returns |" << s << "|" << endl;
	}

	cout << "\nreset and iterate once" << endl;
	string_set0.reset();
	s = string_set0.next();
	cout << "\tnext returns |" << s << "|" << endl;

	cout << "\nremove an element and iterate" << endl;
	cout << "\tremove \"df\"" << endl;
	string_set0.remove("df");
	s = string_set0.next();
	cout << "\tnext returns |" << s << "|" << endl;
	s = string_set0.next();
	cout << "\tnext returns |" << s << "|" << endl;
	s = string_set0.next();
	if (s == NULL) {
		cout << "\tnext returns NULL" << endl;
	} else {
		cout << "\tnext returns |" << s << "|" << endl;
	}
}
