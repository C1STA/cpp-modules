#include <iostream>
#include "Serializer.hpp"

int main(void)
{
  Data driver;

  driver.name = "Lewis Hamilton";
  driver.number = 44;

  uintptr_t raw = Serializer::serialize(&driver);
  Data*     driver_deserialized  = Serializer::deserialize(raw);

  std::cout << "Original pointer : " << &driver << std::endl;
  std::cout << "Deserialized ptr : " << driver_deserialized   << std::endl;
  std::cout << "Pointers match   : " << (driver_deserialized == &driver ? "yes" : "no") << std::endl;
  std::cout << "Data             : " << driver_deserialized->name << " #" << driver_deserialized->number << std::endl;

  return 0;
}
