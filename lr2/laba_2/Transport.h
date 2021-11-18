#pragma once
#include <iostream>
#include <string>


namespace transport
{
	class Transport
	{
	protected:
		int max_speed;
		std::string type_of_fuel;
	public:
		void set_max_speed(int max_speed);
		void set_type_of_fuel(std::string type_of_fuel);
		int get_max_speed();
		std::string get_type_of_fuel();
		virtual void signal();
	};


	class PublicTransport
	{
	protected:
		int people_amount;
		double cost;
	public:
		void set_cost(double cost);
		double get_cost();
		void set_people_amount(int number_people);
		int get_people_amount();
	};

	class Train : public Transport, public PublicTransport
	{
	protected:
		int railway_carriage;
	public:
		void set_railway_carriage(int railway_carriage);
		int get_railway_carriage();
		void signal() override;
	};

	class Ship : public Transport
	{
	protected:
		int board_amount;
	public:
		void set_board_amount(int board_amount);
		int get_board_amount();
		void signal() override;
	};

	class Helicopter : private Transport
	{
	protected:
		int screw_count;
		bool have_weapon;
	public:
		void set_screw_count(int screw_count);
		int get_screw_count();
		void set_have_weapon(bool have_weapon);
		bool get_have_weapon();
		void signal() override;
	};

	class Bike : protected Transport
	{
	protected:
		int year_of_release;
	public:
		void set_year_of_release(int year_of_release);
		int get_year_of_release();
		void signal() override;
	};

	class Car : virtual public Transport
	{
	protected:
		std::string brand;
	public:
		void set_brand(std::string brand);
		std::string get_brand();
		void signal() override;
	};

	class Airplane : virtual public Transport
	{
	protected:
		int wings_count;
	public:
		void set_wing_count(int wings_count);
		int get_wings_count();
		void signal() override;

	};

	class FlyingCar : public Car, public Airplane
	{
	private:
		int price;
	public:
		void set_price(int price);
		int get_price();
		void signal() override;
	};
}