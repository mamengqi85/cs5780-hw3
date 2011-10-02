#include <vector>
#include <climits>
#include "sparse_matrix.h"
#include "proceptron_machine.h"

//TODO @zhitu: Put it in template, headfile & namespace?
double max(const std::vector<double> v)
{
	double maximum = INT_MAX;
	int i;
	for( i = 0; i < v.size(); ++i) {
		if (v[i] < maximum) maximum = v[i];
	}
	return maximum;
}

int ProceptronMachine::DoProceptron(const std::vector<double> &samples, const std::vector<int> &labels, std::vector<double> &w, double &b)
{
	//TODO: double R = max(GetMaxL1Norm(samples));
	double R = 1;
	//TODO:wait
	//w = std::vector<double>(samples[0].get_col_nr(), 0);
	b = 0.0;
	int i, j;
	int k = 0;
	int found_err = 1;
	for (i = 0; found_err || i < iter; ++i) {
		for (j = 0; j < samples.size(); ++j) {
			//TODO: wait
			/*
			if (labels[j] * (samples[j] * w) + b <= 0) {
				w = samples[j] * labels[j] + w;
				b += samples[j] * (R * R * labels[j]);
				k += 1;
				break;
			}*/
			if (j == samples.size()) found_err = 0;
		}
	}
	return 0;
}
