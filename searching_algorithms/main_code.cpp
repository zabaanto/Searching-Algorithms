#include "main_header.h"

int main()
{

	string* file_name = new string("data_base.txt");
	string* sample = new string("ext");
	string text (file_to_string(*file_name));

	cout << text << endl;

	cout << "Looking for a match with '" << *sample << "'" << endl << endl;

	// calling algorithms
	cout << "Naive Algorithm" << endl;
	cout << "-----------------" << endl;
	naive_algorithm(text, *sample);
	
	cout << endl;

	cout << "KMP Algorithm" << endl;
	cout << "-----------------" << endl;
	kmp_algorithm(text, *sample);

	cout << endl;

	cout << "Boyer-Moore Algorithm" << endl;
	cout << "-----------------" << endl;
	bm_algorithm(text, *sample);

	cout << endl;

	cout << "Boyer-Moore another Algorithm" << endl;
	cout << "-----------------" << endl;
	bm_another_algorithm(text, *sample);

	return 0;
}