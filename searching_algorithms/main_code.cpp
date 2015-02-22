#include "main_header.h"

int main()
{
	ifstream file_stream ("data_base.txt", ifstream::binary);
	
	if (file_stream.is_open()) {
		
		int count_char = 0;
		string row;
		string text = "";
		
		while ( getline(file_stream, row) ) {
			count_char += row.length();
			text += row.substr(0, row.length()-1);
		}

		cout << text;

	}
	else {
		cout << "Error: Unable to open file.";
	}

	file_stream.close();
	return 0;
}