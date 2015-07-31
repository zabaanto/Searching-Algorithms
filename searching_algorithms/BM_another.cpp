#include "main_header.h"

/* BM */

void bm_another_algorithm(string text, string pattern)
{
	// ALPHABET MAP IN PATTERN
	map<char, int> map;
	for (int i = 0; i < 26; i++) map[char(97 + i)];  // alphabet as a key
	bm_another_alg_pattern_preprocess(pattern, map);  // first position of the alphabet's element in the pattern from its end

																						// LENGTHS AND INDEXES, ...
	int n = text.length(), m = pattern.length();
	int main_index = m - 1;  // check elements of pattern from its end
	int control_index = m - 1;
	int count_check = 0;

	// ITERATION INSIDE TEXT
	while (main_index < n)
	{
		// ELEMENT MATCHED .. TEXT vs PATTERN
		if (++count_check && text[main_index] == pattern[control_index])
		{
			// WHOLE PATTERN MATCHED
			if (control_index == 0)
			{
				cout << "Word found on position: " << main_index + 1 << endl;
				main_index += m - control_index;  // trivial shift
				control_index = m - 1;
			}
			// JUST SUB-PATTERN MATCHED
			else { control_index--; main_index--; }
		}
		// ELEMENT NOT MATCHED .. TEXT vs PATTERN
		else
		{
			main_index += m - control_index > m - (map[text[main_index + (m - control_index) - 1]] + 1) ? m - control_index : m - control_index - 1 + m - (map[text[main_index + (m - control_index) - 1]] + 1);  // shift by BM algorithm (at least trivial shift or more)
			control_index = m - 1;
		}
	}

	cout << "Checked time ... " << count_check << endl;
}

void bm_another_alg_pattern_preprocess(string &pattern, map<char, int> &map)
{
	for (auto pair : map)
	{
		// find first existance of the letter in the pattern from the end
		int j = pattern.length() - 1;
		while ((j > -1) && (pattern[j] != pair.first) || (j > -1 && (pattern[j] == pair.first) && (j == pattern.length() - 1))) j--;
		map[pair.first] = j;
	}
}