// C-string.cpp
#include <iostream>
#include <cstring>
using namespace std;
// comment the next line when compiling for MAC or Unix
 

int main() {
	char a[10] = "ole";  // with extra unused space
	char a2[4] = "ole";
	char b[10] = "brumm";
	// a = b;  // error, not allowed by compiler

	cout << "\n*** C-string copy\n";
	strcpy(a, b);  // VS Code gives warning and suggests strcpy_s 

// In general, the availability of these functions differ between operating systems and libraries.
// More info is here: https://en.cppreference.com/w/c/string/byte/strcpy	
#ifdef _MSC_VER
	strcpy_s(a, b);  // is part of C11, only available under windows
	// strcpy_s(a2, b); // Gives runtime error: "L buffer is too small..."
#else
	strcpy(a, b);
	strcpy(a2, b);
#endif

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	char c[] = "ccccc";
	char d[] = "dddDDDDD";
	cout << "d = " << d << endl;

	// strncpy(a,b,n); copies n chars from the start of b to a (from the start of a), gives warning under windows
	// More info: https://en.cppreference.com/w/c/string/byte/strncpy
#ifdef _MSC_VER
	strncpy_s(d, c, 4);
#else
	strncpy(d, c, 4);
#endif
	cout << "d after = " << d << endl;

	cout << "\n*** C-string concatenation\n";
	char s1[] = "Ole";
	char s2[] = "Brumm";
	char s3[20] = "Ole";
	cout << "s1 = " << s1 << endl << "s2 = " << s2 << endl;

// More info: https://en.cppreference.com/w/c/string/byte/strcat
// More info: https://en.cppreference.com/w/c/string/byte/strncat
#ifdef _MSC_VER
	strcat_s(s3, " ");  // appends a blank to s3
	strcat_s(s3, s2); // appends s2 to s3
	cout << "s3 = " << s3 << endl;

	strncat_s(s3, s2, 3);  // concatenate n chars, here 3 chars from s2 to s3
	cout << "s3 = " << s3 << endl;
#else
	strcat(s3, " ");
	strcat(s3, s2);
	cout << "s3 = " << s3 << endl;

	strncat(s3, s2, 3);
	cout << "s3 = " << s3 << endl;
#endif

	// search after char
	// strchr returns pointer to the first instance of a char 
	cout << "\n *** Search after char\n";
	cout << "strchr(s3, 'B') = " << strchr(s3, 'B') << endl;

	// length of C-string
	cout << "\n *** length of C-string\n";
	cout << "strlen(s2) = " << strlen(s2) << " and ";
	cout << "strlen(s3) = " << strlen(s3) << endl;

	// search after C-string
	// strstr returns pointer to first instance of the searchstring 
	cout << "\n *** Search after string\n";
	cout << "strstr(s3, \"ummB\") = "; // note that specifying " in output must be "protected (escaped)" by the \-char  
	cout << strstr(s3, "ummB") << endl;

	char englishAlphabet[27];
	for (char c = 'a'; c <= 'z'; c++) {
		englishAlphabet[c - 'a'] = c;
	}
	cout << englishAlphabet << endl;
	// statement above writes out too much, 0-termination is missing, can give runtime error 
	englishAlphabet[26] = '\0';
	cout << englishAlphabet << endl;
	return 0;
}