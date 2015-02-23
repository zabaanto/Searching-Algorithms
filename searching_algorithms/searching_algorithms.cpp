#include "main_header.h"

/* NAIVE/TRIVIAL/ELEMENTERY ALGORITHM */
void naive_algorithm(string text, string sample)
{
	int n = text.length();
	int m = sample.length();

	/* ITTERATION INSIDE TEXT */
	for (int main_index = 0; main_index <= n - m; main_index++)
	{
		int control_index = 0;  // current position in SAMPLE which is comparing to
		
		// WHILE compare is SUCCEDEing .. only looking for first m-elements in SAMPLE; compare element in TEXT and SAMPLE
		while ( (control_index <= m-1) && (text[main_index + control_index] == sample[control_index]) )
			control_index++;  // will be next position to control
		
		// IF all SAMPLE elements checked
		if (control_index >= m)
			cout << "Word found on position: " << main_index << endl;
	}

}

/* KMP ALGORITHM */
void kmp_algorithm(string text, string sample)
{
	int n = text.length();
	int m = sample.length();

	vector<int> sample_info = kmp_sample_preprocess(sample);  // sample preprocessing
	int control_index = 0;
	int main_index = 0;

	/*for (int number: sample_info)
		cout << number << " ";*/

	while (main_index <= n - m + 1)
	{
		if (text[main_index] == sample[control_index])
		{
			control_index++;

			if (control_index >= m)
			{
				cout << "Word found on position: " << main_index - control_index + 1 << endl;
				control_index = sample_info[control_index - 1];
			}

			main_index++;
		}
		else
		{
			if (control_index == 0)
				main_index++;
			else
				control_index = sample_info[control_index - 1];
		}
	}

}

vector<int> kmp_sample_preprocess(string sample)
{
	vector<int> sample_info (sample.length());
	sample_info[0] = 0;
	int element_in_a_row = 0;

	for (int main_index = 1; main_index < sample.length(); main_index++)
	{
		if (sample[element_in_a_row] == sample[main_index])
			element_in_a_row++;
		else
			element_in_a_row = 0;

		sample_info[main_index] = element_in_a_row;  // save info
	}

	return sample_info;
}