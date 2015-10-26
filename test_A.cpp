#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "string_set.h"

using namespace std;

int main() {
	string_set set;
	int n;

	cout << "\ncheck/add \"e\"" << endl;
	n = set.contains("e");
	cout << "\tcontains(\"e\") returns " << n << endl;
	cout << "adding \"e\"" << endl;
	set.add("e");
	n = set.contains("e");
	cout << "\tcontains(\"e\") returns " << n << endl;

	cout << "\ncheck/add \"f\"" << endl;
	n = set.contains("f");
	cout << "\tcontains(\"f\") returns " << n << endl;
	cout << "adding \"f\"" << endl;
	set.add("f");
	n = set.contains("f");
	cout << "\tcontains(\"f\") returns " << n << endl;

	cout << "\ncheck/add \"df\"" << endl;
	n = set.contains("df");
	cout << "\tcontains(\"df\") returns " << n << endl;
	cout << "adding \"df\"" << endl;
	set.add("df");
	n = set.contains("df");
	cout << "\tcontains(\"df\") returns " << n << endl;

	cout << "\nadd \"e\" again" << endl;
	try {
		set.add("e");
	} catch (duplicate_exception) {
		cout << "\tcaught duplicate_exception" << endl;
	}

	cout << "\ncheck for shallow copy" << endl;
	char s[10];
	strcpy(s,"g");
	set.add(s);
	n = set.contains("g");
	cout << "\tcontains(\"g\") returns " << n << endl;
}
