#include <iostream>
#include "sparse_matrix.h"
#include "proceptron_machine.h"

using namespace std;

int main(int argc, char *argv[])
{
	double miu = 0.5;
	int iter = 100;	
	ProceptronMachine pm(miu, iter);
	cout<<pm.get_miu()<<endl;
	cout<<pm.get_iter()<<endl;
	pm.set_iter(200);
	ProceptronMachine pm2(pm);
	cout<<pm2.get_iter()<<endl;
	return 0;
}
