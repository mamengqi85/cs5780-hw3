#include <vector>
#include "sparse_matrix.h"

#ifndef CS5780HW3_PROCEPTRONMACHINE_H_
#define CS5780HW3_PROCEPTRONMACHINE_H_

class ProceptronMachine
{
 public:
	 ProceptronMachine(const double m, const int i) : miu(m), iter(i) {}
	 ProceptronMachine(const ProceptronMachine& pm) 
		 : miu(pm.miu), iter(pm.iter) {}

	 int DoProceptron(const std::vector<double>&, const std::vector<int>&, 
			 std::vector<double>&, double&);

	 const int get_miu() { return miu; }
	 const int get_iter() { return iter; }
	 void set_iter(int i) { iter = i; }
 
 private:
 	 const double miu;
	 int iter;
};

#endif /* CS5780HW3_PROCEPTRON_MACHINE_H_ */
