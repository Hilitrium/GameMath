#include<iostream>
#include"math.h"


int main() {
	//Closed
	//square function
	std::cout << sqr(5) << std::endl;
	//double function
	std::cout << dbl(6) << std::endl;
	//cube function
	std::cout << cube(3) << std::endl;
	//degreese to radians
	std::cout << degToRad(180) << std::endl;
	//radians to degreese
	std::cout << radToDeg(4.712389) << std::endl;
	//Open
	//basic quadratic
	std::cout << quad(5) << std::endl;
	//linear blend
	std::cout << lerp(0, 10, 1.0) << std::endl;
	//distance

	while(true) {}
}