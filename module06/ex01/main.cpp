#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int	main(void)
{
	Data		data("42 Yerevan");
	uintptr_t	raw = serialize(&data);
	Data		*dataPtr = deserialize(raw);

	std::cout << BLACK << "\n// INPUT CODE\n" << std::endl;
	std::cout << "// Data       data(\"42 Yerevan\");" << std::endl;
	std::cout << "// uintptr_t  raw = serialize(&data);" << std::endl;
	std::cout << "// Data       *dataPtr = deserialize(raw);" << std::endl;
	std::cout << "\n// Result should be the same!" << std::endl;
	std::cout << "// (Serialization/deserialization keep the same value inside data and same address)" << std::endl;
	std::cout << "\n// OUTPUT\n" << RESET << std::endl;

	std::cout << YELLOW << "\e[4m  ADRESSES                              " << RESET << std::endl;
	std::cout << "   data: "<< &data << std::endl;
	std::cout << "dataPtr: "<< dataPtr << std::endl;	
	std::cout << std::endl;

	std::cout << YELLOW << "\e[4m  VALUES                                " << RESET << std::endl;
	std::cout << "   data: " << data.getValue() << std::endl;
	std::cout << "dataPtr: " << (*dataPtr).getValue() << std::endl;
	std::cout << std::endl;
	return (0);
}
