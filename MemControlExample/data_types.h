#include <cstdint>
#include <array>

#pragma once
enum data_type : uint8_t {
	invalid = 0,
	data_type_1 = 1,
	data_type_2 = 2
};



struct base_data {
	base_data(data_type _type) : type(_type) { }
	base_data() { type = data_type::invalid; }
	public:
		data_type type;
};

struct seralizeable_data_1 :base_data
{
	seralizeable_data_1(data_type _type ,std::array<char, 20> _name, int _age) : name(_name), age(_age), base_data(_type) { }
	seralizeable_data_1() { }
	public:
		std::array<char, 20> name = {""};
		int age = 0;

};


struct seralizeable_data_2 : base_data
{
	seralizeable_data_2(data_type _type, int _weight, int _amount) : weight(_weight), amount(_amount), base_data(_type) {}
	seralizeable_data_2() {}
public:
	int weight = 0;
	int amount = 0;
};

