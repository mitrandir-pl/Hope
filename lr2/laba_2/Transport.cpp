#include "Transport.h"
#include <iostream>

void transport::Transport::set_max_speed(int max_speed)
{
    Transport::max_speed = max_speed;
}

void transport::Transport::set_type_of_fuel(std::string type_of_fuel)
{
    Transport::type_of_fuel = type_of_fuel;
}

int transport::Transport::get_max_speed()
{
    return Transport::max_speed;
}

std::string transport::Transport::get_type_of_fuel()
{
    return Transport::type_of_fuel;
}

void transport::Transport::signal()
{
    std::cout << "Default signal" << std::endl;
}

void transport::PublicTransport::set_cost(double cost)
{
    PublicTransport::cost = cost;
}

double transport::PublicTransport::get_cost()
{
    return PublicTransport::cost;
}

void transport::PublicTransport::set_people_amount(int number_people)
{
    PublicTransport::people_amount = people_amount;
}

int transport::PublicTransport::get_people_amount()
{
    return PublicTransport::people_amount;
}

void transport::Train::set_railway_carriage(int railway_carriage)
{
    Train::railway_carriage = railway_carriage;
}

int transport::Train::get_railway_carriage()
{
    return Train::railway_carriage;
}

void transport::Train::signal()
{
    std::cout << "Tu-tu!!!" << std::endl;
}

void transport::Ship::set_board_amount(int board_amount)
{
    Ship::board_amount = board_amount;
}

int transport::Ship::get_board_amount()
{
    return Ship::board_amount;
}

void transport::Ship::signal()
{
    std::cout << "TUUUU!!!" << std::endl;
}

void transport::Helicopter::set_screw_count(int screw_count)
{
    Helicopter::screw_count = screw_count;
}

int transport::Helicopter::get_screw_count()
{
    return Helicopter::screw_count;
}

void transport::Helicopter::set_have_weapon(bool have_weapon)
{
    Helicopter::have_weapon = have_weapon;
}

bool transport::Helicopter::get_have_weapon()
{
    return Helicopter::have_weapon;
}

void transport::Helicopter::signal()
{
    std::cout << "TR-TR-TR!!!" << std::endl;
}

void transport::Bike::set_year_of_release(int year_of_release)
{
    Bike::year_of_release = year_of_release;
}

int transport::Bike::get_year_of_release()
{
    return Bike::year_of_release;
}

void transport::Bike::signal()
{
    std::cout << "RRRR!!!!" << std::endl;
}

void transport::Car::set_brand(std::string brand)
{
    Car::brand = brand;
}

std::string transport::Car::get_brand()
{
    return Car::brand;
}

void transport::Car::signal()
{
    std::cout << "Bzzzzz!!" << std::endl;
}

void transport::Airplane::set_wing_count(int wings_count)
{
    Airplane::wings_count = wings_count;
}

int transport::Airplane::get_wings_count()
{
    return Airplane::wings_count;
}

void transport::Airplane::signal()
{
    std::cout << "Weeeeee!!" << std::endl;

}

void transport::FlyingCar::set_price(int price)
{
    FlyingCar::price = price;
}

int transport::FlyingCar::get_price()
{
    return FlyingCar::price;
}

void transport::FlyingCar::signal()
{
    std::cout << "UUUUUU!!" << std::endl;
}

