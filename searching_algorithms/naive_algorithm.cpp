#include "main_header.h"

/* NAIVE/TRIVIAL/ELEMENTERY ALGORITHM */
void naive_algorithm(string text, string sample)
{
	int n = text.length();
	int m = sample.length();

	int count_check = 0;

	/* ITTERATION INSIDE TEXT */
	for (int main_index = 0; main_index <= n - m; main_index++)
	{
		int control_index = 0;  // current position in SAMPLE which is comparing to

														// WHILE compare is SUCCEDEing .. only looking for first m-elements in SAMPLE; compare element in TEXT and SAMPLE
		while ((control_index <= m - 1) && ++count_check && (text[main_index + control_index] == sample[control_index]))
			control_index++;  // next loop looking for next element in SAMPLE

												// IF all SAMPLE elements checked
		if (control_index >= m)
			cout << "Word found on position: " << main_index + 1 << endl;
	}

	cout << "Checked time ... " << count_check << endl;
}