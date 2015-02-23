#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// OTHER FUNCTIONS
string file_to_string(string file_name);

// NAIVE ALGORITHM
void naive_algorithm(string text, string sample);

// KMP ALGORITHM
void kmp_algorithm(string text, string sample);
vector<int> kmp_sample_preprocess(string sample);