#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

# define BLACK		"\33[1;30m"

// void	ft_tests(void)
// {
// 	// Constructors
// 	std::cout << std::endl;
// 	std::cout << BLACK << "CONSTRUCTORS:" << RESET << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	std::cout << std::endl;

// 	// Create Materia
// 	std::cout << BLACK << "CREATE MATERIA:" << RESET << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	me->equip(src->createMateria("ice"));
// 	me->equip(src->createMateria("cure"));
// 	me->equip( src->createMateria("fire")); // null argument
// 	std::cout << std::endl;

// 	// Use on a new character
// 	std::cout << BLACK << "USE ON A NEW CHARACTER:" << RESET << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	ICharacter* petros = new Character("Petros");
// 	me->use(0, *petros);
// 	me->use(1, *petros);
// 	std::cout << std::endl;
// 	me->use(2, *petros); // Use an empty / non existing slot in inventory
// 	me->use(-1, *petros);
// 	me->use(10, *petros);
// 	std::cout << std::endl;

// 	// Deep copy character
// 	std::cout << BLACK << "DEEP COPY CHARACTER:" << RESET << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	Character	*poghos = new Character("Poghos");
// 	poghos->equip(src->createMateria("cure"));
// 	poghos->equip(src->createMateria("ice"));
// 	poghos->equip(src->createMateria("wood"));
// 	Character	*poghos_copy = new Character(*poghos);
// 	std::cout << std::endl;

// 	// Deep copy vs its source character
// 	std::cout << BLACK << "DEEP COPY VS SOURCE:" << RESET << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	poghos->unequip(0); // this shows that they have different materia pointers equipped
// 	poghos_copy->unequip(1); //this will produce a leak if we don't store the address somewhere else before
// 	poghos_copy->equip(src->createMateria("cure"));
// 	poghos_copy->equip(src->createMateria("ice"));
// 	std::cout << std::endl;

// 	poghos->use(0, *petros);
// 	poghos->use(1, *petros);
// 	poghos->use(2, *petros);
// 	poghos->use(3, *petros);
// 	std::cout << std::endl;
// 	poghos_copy->use(0, *petros);
// 	poghos_copy->use(1, *petros);
// 	poghos_copy->use(2, *petros);
// 	poghos_copy->use(3, *petros);
// 	std::cout << std::endl;

// 	// Unequip tests:
// 	std::cout << BLACK << "UNEQUIP:" << RESET << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	me->unequip(-1); // unequip an empty / non existing slot in inventory
// 	me->unequip(10);
// 	me->unequip(5);
// 	std::cout << std::endl;
// 	me->use(1, *poghos);
// 	me->unequip(1); // Unequip a valid slot in inventory (cure unequipped)
// 	me->use(1, *poghos); // try to use it
// 	std::cout << std::endl;

// 	// Destructors
// 	std::cout << BLACK << "DESTRUCTORS:" << RESET << std::endl;
// 	std::cout << "-----------------------" << std::endl;
// 	delete petros;
// 	delete me;
// 	delete src;
// 	delete poghos;
// 	delete poghos_copy;
// 	std::cout << std::endl;
// }


void	ft_tests(void)
{
	// Constructors
	std::cout << std::endl;
	std::cout << BLACK << "CONSTRUCTORS:" << RESET << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << BLACK << "IMateriaSource* src = new MateriaSource();" << RESET << std::endl; ///
	IMateriaSource* src = new MateriaSource();
	std::cout << BLACK << "src->learnMateria(new Ice());" << RESET << std::endl; ///
	src->learnMateria(new Ice());
	std::cout << BLACK << "src->learnMateria(new Cure());" << RESET << std::endl; ///
	src->learnMateria(new Cure());
	std::cout << BLACK << "ICharacter* me = new Character('me');" << RESET << std::endl; ///
	ICharacter* me = new Character("me");
	std::cout << std::endl;

	// Create Materia
	std::cout << BLACK << "CREATE MATERIA:" << RESET << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << BLACK << "me->equip(src->createMateria('ice'));" << RESET << std::endl; ///
	me->equip(src->createMateria("ice"));
	std::cout << BLACK << "me->equip(src->createMateria('cure'));" << RESET << std::endl; ///
	me->equip(src->createMateria("cure"));
	std::cout << BLACK << "me->equip( src->createMateria('ire')); // null argument" << RESET << std::endl; ///
	me->equip(src->createMateria("fire")); // null argument
	std::cout << std::endl;

	// Use on a new character
	std::cout << BLACK << "USE ON A NEW CHARACTER:" << RESET << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << BLACK << "ICharacter* petros = new Character('Petros');" << RESET << std::endl; ///
	ICharacter* petros = new Character("Petros");
	std::cout << BLACK << "me->use(0, *petros);" << RESET << std::endl; ///
	me->use(0, *petros);
	std::cout << BLACK << "me->use(1, *petros);" << RESET << std::endl; ///
	me->use(1, *petros);
	std::cout << std::endl;
	std::cout << BLACK << "me->use(2, *petros); // Use an empty / non existing slot in inventory" << RESET << std::endl; ///
	me->use(2, *petros); // Use an empty / non existing slot in inventory
	std::cout << BLACK << "me->use(-1, *petros);" << RESET << std::endl; ///
	me->use(-1, *petros);
	std::cout << BLACK << "me->use(10, *petros);" << RESET << std::endl; ///
	me->use(10, *petros);
	std::cout << std::endl;

	// Deep copy character
	std::cout << BLACK << "DEEP COPY CHARACTER:" << RESET << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << BLACK << "Character *poghos = new Character('Poghos');" << RESET << std::endl; ///
	Character	*poghos = new Character("Poghos");
	std::cout << BLACK << "poghos->equip(src->createMateria('cure'));" << RESET << std::endl; ///
	poghos->equip(src->createMateria("cure"));
	std::cout << BLACK << "poghos->equip(src->createMateria('ice'));" << RESET << std::endl; ///
	poghos->equip(src->createMateria("ice"));
	std::cout << BLACK << "poghos->equip(src->createMateria('wood'));" << RESET << std::endl; ///
	poghos->equip(src->createMateria("wood"));
	std::cout << BLACK << "Character *poghos_copy = new Character(*poghos);" << RESET << std::endl; ///
	Character	*poghos_copy = new Character(*poghos);
	std::cout << std::endl;

	// Deep copy vs its source character
	std::cout << BLACK << "DEEP COPY VS SOURCE:" << RESET << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << BLACK << "poghos->unequip(0); // this shows that they have different materia pointers equipped" << RESET << std::endl; ///
	poghos->unequip(0); // this shows that they have different materia pointers equipped
	std::cout << BLACK << "poghos_copy->unequip(1); //this will produce a leak if we don't store the address somewhere else before" << RESET << std::endl; ///
	poghos_copy->unequip(1); //this will produce a leak if we don't store the address somewhere else before
	std::cout << BLACK << "poghos_copy->equip(src->createMateria('cure'));" << RESET << std::endl; ///
	poghos_copy->equip(src->createMateria("cure"));
	std::cout << BLACK << "poghos_copy->equip(src->createMateria('ice'));" << RESET << std::endl; ///
	poghos_copy->equip(src->createMateria("ice"));
	std::cout << std::endl;

	std::cout << BLACK << "poghos->use(0, *petros);" << RESET << std::endl; ///
	poghos->use(0, *petros);
	std::cout << BLACK << "poghos->use(1, *petros);" << RESET << std::endl; ///
	poghos->use(1, *petros);
	std::cout << BLACK << "poghos->use(2, *petros);" << RESET << std::endl; ///
	poghos->use(2, *petros);
	std::cout << BLACK << "poghos->use(3, *petros);" << RESET << std::endl; ///
	poghos->use(3, *petros);
	std::cout << std::endl;

	std::cout << BLACK << "poghos_copy->use(0, *petros);" << RESET << std::endl; ///
	poghos_copy->use(0, *petros);
	std::cout << BLACK << "poghos_copy->use(1, *petros);" << RESET << std::endl; ///
	poghos_copy->use(1, *petros);
	std::cout << BLACK << "poghos_copy->use(2, *petros);" << RESET << std::endl; ///
	poghos_copy->use(2, *petros);
	std::cout << BLACK << "poghos_copy->use(3, *petros);" << RESET << std::endl; ///
	poghos_copy->use(3, *petros);
	std::cout << std::endl;

	// Unequip tests:
	std::cout << BLACK << "UNEQUIP:" << RESET << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << BLACK << "me->unequip(-1); // unequip an empty / non existing slot in inventory" << RESET << std::endl; ///
	me->unequip(-1); // unequip an empty / non existing slot in inventory
	std::cout << BLACK << "me->unequip(10);" << RESET << std::endl; ///
	me->unequip(10);
	std::cout << BLACK << "me->unequip(5);" << RESET << std::endl; ///
	me->unequip(5);
	std::cout << std::endl;

	std::cout << BLACK << "me->use(1, *poghos);" << RESET << std::endl; ///
	me->use(1, *poghos);
	std::cout << BLACK << "me->unequip(1); // Unequip a valid slot in inventory (cure unequipped)" << RESET << std::endl; ///
	me->unequip(1); // Unequip a valid slot in inventory (cure unequipped)
	std::cout << BLACK << "me->use(1, *poghos); // try to use it" << RESET << std::endl; ///
	me->use(1, *poghos); // try to use it
	std::cout << std::endl;

	// Destructors
	std::cout << BLACK << "DESTRUCTORS:" << RESET << std::endl;
	std::cout << "-----------------------" << std::endl;
	delete petros;
	delete me;
	delete src;
	delete poghos;
	delete poghos_copy;
	std::cout << std::endl;
}
