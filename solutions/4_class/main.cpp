#include <stdio.h>

class Class
{
public:
  void print(); // member function = method
  Class(); 		// constructor
private:
  int variable; // member variable = instance variable
};

// implementation of constructor
Class::Class():
  variable(999)
{

}

// implementation of member function
void Class::print()
{
  printf("Die Variable ist ... moment ... %i\n", this->variable);
}

int main() {
  Class *test = new Class();

  Class &pInstance = *test;

	pInstance.print();

	delete test;

  return 0;
}
