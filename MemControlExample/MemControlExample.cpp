

#include <iostream>
#include "data_types.h"
#include <string>
#include <array>


template<typename T>
T deserialize_obj(uint8_t* ptr_in) {
	T data{};
	memcpy(&data, ptr_in, sizeof(T));
	return data;
}
template<typename T>
uint8_t* serialize_obj(T* obj_in, uint8_t* ptr_out) {
	std::memcpy(ptr_out, obj_in, sizeof(T));
	return ptr_out;
}

int main()
{
	seralizeable_data_1 data_1{ data_type::data_type_1, {"Marius"}, 25 };


	seralizeable_data_2 data_2{ data_type::data_type_2, 200, 10 };
	
	std::cout << "data_1 before serialization: " << (int)data_1.type << ", " << std::string(data_1.name.begin(), data_1.name.end()) << ", " << data_1.age << std::endl;

	std::cout << "data_2 before serialization: " << (int)data_2.type << ", " << data_2.weight << ", " << data_2.amount << std::endl;
	
	std::unique_ptr<uint8_t> seralized_data_1(new uint8_t[sizeof(data_1)]); // this would represent a file or similar seralized byte data for this object.

	std::unique_ptr<uint8_t> seralized_data_2(new uint8_t[sizeof(data_2)]); // this would represent a file or similar seralized byte data for this object.

	serialize_obj(&data_1, seralized_data_1.get());
	serialize_obj(&data_2, seralized_data_2.get());

	//std::memcpy(seralized_data_1.get(), &data_1, sizeof(data_1));

	//std::memcpy(seralized_data_2.get(), &data_2, sizeof(data_2));


	// simulate deseralization
	seralizeable_data_1 derseralized_data_1 = deserialize_obj<seralizeable_data_1>(seralized_data_1.get());
	seralizeable_data_2 derseralized_data_2 = deserialize_obj<seralizeable_data_2>(seralized_data_2.get());


	std::cout << "data_1 after deserialization: " << (int)derseralized_data_1.type << ", " << std::string(derseralized_data_1.name.begin(), derseralized_data_1.name.end()) << ", " << derseralized_data_1.age << std::endl;

	std::cout << "data_2 after deserialization: " << (int)derseralized_data_2.type << ", " << derseralized_data_2.weight << ", " << derseralized_data_2.amount << std::endl;

}

