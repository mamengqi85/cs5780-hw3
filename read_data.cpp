#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "sparse_vector.h"

#define FEATURES 29328

int ReadSparseVectors(std::vector<const SparseVector<double>*>& samples, std::vector<int>& labels, const char* str)
{
	int label, col;
	double val;
	std::string tmp_str;
	std::ifstream fin(str);
	char* p;
	if (!fin.is_open()) {
		return -1;
	}
	while (fin.good()) {
		SparseVector<double> vect = SparseVector<double>(FEATURES);
		getline(fin, tmp_str);
		label = strtol(tmp_str.c_str(), &p, 10);
		while (p < tmp_str.c_str()+tmp_str.length()){
			col = strtol(p, &p, 10);
			val = strtod(p, &p);
			vect(col) = val;
		}
		labels.push_back(label);
		samples.push_back(&vect);
	}
	return 0;
}

