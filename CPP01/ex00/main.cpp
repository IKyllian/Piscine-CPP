#include "Zombie.hpp"

int main(void)
{
	std::string names[5] = {"Zombiac", "Zoro", "Carl", "Tim", "George"};
	Zombie *zombie1 = NULL;


	zombie1 = zombie1->newZombie("Alfred");


	delete zombie1;
	
	return (0);
}