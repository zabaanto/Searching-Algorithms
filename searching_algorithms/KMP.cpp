#include "main_header.h"

/* KMP ALGORITHM */
void kmp_algorithm(string text, string sample)
{
	int n = text.length(), m = sample.length();

	vector<int> sample_info = kmp_sample_preprocess(sample);  // sample preprocessing
	int control_index = 0, main_index = 0;

	int count_check = 0;

	/* ITERATION INSIDE TEXT */
	while (main_index < n - m + 1)
	{
		// TEXT[i] vs SAMPLE[j] .. compare SUCCEDE
		if ( ++count_check && text[main_index] == sample[control_index])
		{
			control_index++;  // next loop looking for next element in SAMPLE

												// all SAMPLE elements checked
			if (control_index >= m)
			{
				cout << "Word found on position: " << main_index - control_index + 2 << endl;
				control_index = sample_info[control_index - 1];  // dont forget for already checked subSAMPLES
			}

			main_index++; // you could move on
		}
		// TEXT[i] vs SAMPLE[j] .. compare NOT SUCCEDE
		else
		{
			// first SAMPLE element doesnt fetch => no subSAMPLES, you could move on
			if (control_index == 0) main_index++;
			// otherwise dont forget for already checked subSAMPLES, you CANT move on! (check position again)
			else control_index = sample_info[control_index - 1];
		}
	}

	cout << "Checked time ... " << count_check << endl;
}

vector<int> kmp_sample_preprocess(string sample)
{
	vector<int> sample_info(sample.length());
	sample_info[0] = 0;
	int element_in_a_row = 0;

	// ITERATION INSIDE SAMPLE
	for (int main_index = 1; main_index < sample.length(); main_index++)
	{
		if (sample[element_in_a_row] == sample[main_index]) element_in_a_row++;	 // element in a row
		else element_in_a_row = 0;  // otherwise start over

		sample_info[main_index] = element_in_a_row;  // save info
	}

	return sample_info;
}