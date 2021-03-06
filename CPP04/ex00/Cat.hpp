#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public :

		Cat();
		Cat(const Cat &src);
		virtual ~Cat();

		Cat& operator=(const Cat &src);

		std::string getType(void) const;
		virtual void makeSound() const;
};

#endif