#include "main_header.h"

string file_to_string(string filename) {
	
	string text = "";
	ifstream file_stream ("filename", ifstream::binary);

	if (file_stream.is_open()) {

		int count_char = 0;
		string row;
		
		while ( getline(file_stream, row))
			text += row.substr(0, row.length()-1);

	}
	else {
		cout << "Error: Unable to open file.";
		text = "";
	}

	file_stream.close();
	
	return text;
}