#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// OTHER FUNCTIONS
string file_to_string(string file_name);

// NAIVE ALGORITHM
void naive_algorithm(string text, string sample);

// KMP ALGORITHM
void kmp_algorithm(string text, string sample);
vector<int> kmp_sample_preprocess(string sample);

// Boyer-Moore 
void bm_algorithm(string text, string letter);
void bm_alg_pattern_preprocess(string &pattern, map<char, int> &map);

// Boyer-Moore another
void bm_another_algorithm(string text, string letter);
void bm_another_alg_pattern_preprocess(string &pattern, map<char, int> &map);