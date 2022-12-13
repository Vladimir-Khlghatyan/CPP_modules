#include "Zombie.hpp"

int	main(void)
{
	// creating a class on the heap
	Zombie *Heap;
	Heap = newZombie("Heap");
	Heap->announce();
	delete Heap;

	// creating a class on the stack
	randomChump("Stack");

	return (0);
}