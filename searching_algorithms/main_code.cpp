#include "main_header.h"

int main()
{

	string* file_name = new string("data_base.txt");
	string* sample = new string("Jak");
	string text (file_to_string(*file_name));

	// calling algorithm
	naive_algorithm(text, *sample);
	


	return 0;
}