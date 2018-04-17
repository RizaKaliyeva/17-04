#include "Vector.h"

int main() {
	Vector v1(10);
	
	v1.push_back(15);

	//v1.push_dif(13, 5);
	v1.push_plus(12, 5);
	v1.at(3) = 5;
	v1.print();

	system("pause");
	return 0;
}