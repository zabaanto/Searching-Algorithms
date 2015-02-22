#include "main_header.h"

int main()
{
	string file_name ("data_base.txt");
	string text (file_to_string(file_name));

	cout << text << endl;

	return 0;
}