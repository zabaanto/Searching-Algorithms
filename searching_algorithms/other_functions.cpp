#include "main_header.h"

string file_to_string(string filename) {
	
	string text = "";
	ifstream file_stream (filename, ifstream::in);

	if (file_stream.is_open()) {
		
		/* GET FILE SIZE */
		file_stream.seekg(0, file_stream.end);
		int file_size = file_stream.tellg();
		file_stream.seekg(0, file_stream.beg);

		/* FILE to STRING */
		// without newlines (13, 10)
		char current_char;
		while (file_stream >> noskipws >> current_char) 
			if ( (int(current_char) != 13) & (int(current_char) != 10) )
				text += current_char;

	}
	else {
		cout << "Error: Unable to open file.";
		text = "";
	}

	file_stream.close();
	
	return text;
}