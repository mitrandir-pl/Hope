#include "Transport.h"

int main() {
	transport::Train train;
	std::cout << "train makes: " << std::endl;
	train.signal();
	transport::Ship ship;
	std::cout << "ship makes: " << std::endl;
	ship.signal();
	transport::Helicopter copter;
	std::cout << "helicopter makes: " << std::endl;
	copter.signal();
	transport::Bike bike;
	std::cout << "bike makes: " << std::endl;
	bike.signal();
	transport::Car car;
	std::cout << "car makes: " << std::endl;
	car.signal();
	transport::Airplane plane;
	std::cout << "plane makes: " << std::endl;
	plane.signal();
	transport::FlyingCar f_car;
	std::cout << "Flying car makes: " << std::endl;
	f_car.signal();
}