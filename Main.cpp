#include <string>
#include <vector>
#include <iostream>

#include "Person.h"

//enum Sex { MALE, FEMALE };
int main(void)
{
	//	Me
	Person Seth(Person::Sex::MALE, "Seth");
	
	//  Parents
	Person Jen(Person::Sex::FEMALE, "Jen");
	Person Jack(Person::Sex::MALE, "Jack");


	//	Grandparents
	Person Jen_father(Person::Sex::MALE, "Jen_father");
	Person Jack_father(Person::Sex::MALE, "Jack_father");

	//	Great Grandparents
	Person Jen_father_father(Person::Sex::MALE, "Jen_father_father");
	Jen_father_father.addChild(&Jen_father);
	Person Jack_father_mother(Person::Sex::FEMALE, "Jack_father_mother");
	Jack_father_mother.addChild(&Jack_father);

	// Great Great Grandparents
	Person Jen_father_father_mother(Person::Sex::FEMALE, "Jen_father_father_mother");
	Jen_father_father_mother.addChild(&Jen_father_father);
	Person Jack_father_mother_father(Person::Sex::MALE, "Jack_father_mother_father");
	Jack_father_mother_father.addChild(&Jack_father_mother);



	//  Siblings
	Person Alan(Person::Sex::MALE, "Alan");
	Person Alex(Person::Sex::MALE, "Alex");
	Person Alice(Person::Sex::FEMALE, "Alice");
	Person Spielberg(Person::Sex::FEMALE, "Spielberg");

	//	Uncle
	Person Uncle(Person::Sex::MALE, "Uncle");
	//	Auntie
	Person Auntie(Person::Sex::FEMALE, "Auntie");
	//	cousins
	Person cuz1(Person::Sex::MALE, "cuz1");
	Person cuz2(Person::Sex::MALE, "cuz2");
	Person cuz3(Person::Sex::MALE, "cuz3");
	Person cuz4(Person::Sex::MALE, "cuz4");

	//  Set Parents
	Seth.setFather(&Jack);
	Seth.setMother(&Jen);

	//  Set children
	Jack.addChild(&Alan);
	Jack.addChild(&Alex);
	Jack.addChild(&Alice);
	Jack.addChild(&Spielberg);
	Jen.addChild(&Alan);
	Jen.addChild(&Alex);
	Jen.addChild(&Alice);
	Jen.addChild(&Spielberg);

	//	Add cousins to uncle
	Uncle.addChild(&cuz1);
	Uncle.addChild(&cuz2);

	//	Add cousins to Auntie
	Auntie.addChild(&cuz3);
	Auntie.addChild(&cuz4);

	//	Jack and Uncle have same father
	Jack_father.addChild(&Jack);
	Jack_father.addChild(&Uncle);

	//	Jen and Auntie have same father
	Jen_father.addChild(&Jen);
	Jen_father.addChild(&Auntie);

	


	//People cousins;
	//Seth.getCousins(cousins);

	//std::cout << "Does Jack have Seth? "<< Jack.hasChild(&Seth) << std::endl;

	/*People ancestors;
	Seth.getAncestors(ancestors);
	for (Person* anc : ancestors)
	{
		std::cout << anc->name << std::endl;
	};*/

	People descendants;
	Jack_father_mother_father.getDescendants(descendants);
	for (Person* dec : descendants)
	{
		std::cout << dec->name << std::endl;
	};

	////	Show siblings
	//People Spiel_sibs;

	//Spielberg.getSiblings(Spiel_sibs);

	//std::cout << "Does Jack have Alan? "<< Jack.hasChild(&Alan) << std::endl;
	//std::cout << "Does Jack have Alex? " << Jack.hasChild(&Alex) << std::endl;
	//std::cout << "Does Jack have Alice? " << Jack.hasChild(&Alice) << std::endl;
	//std::cout << "Does Jack have Spielberg? " << Jack.hasChild(&Spielberg) << std::endl << std::endl;


	//Jack.removeChild(&Spielberg);

	//std::cout << "Does Jack have Alan? " << Jack.hasChild(&Alan) << std::endl;
	//std::cout << "Does Jack have Alex? " << Jack.hasChild(&Alex) << std::endl;
	//std::cout << "Does Jack have Alice? " << Jack.hasChild(&Alice) << std::endl;
	//std::cout << "Does Jack have Spielberg? " << Jack.hasChild(&Spielberg) << std::endl << std::endl;

	//Jack.removeAllChildren();

	//std::cout << "Does Jack have Alan? " << Jack.hasChild(&Alan) << std::endl;
	//std::cout << "Does Jack have Alex? " << Jack.hasChild(&Alex) << std::endl;
	//std::cout << "Does Jack have Alice? " << Jack.hasChild(&Alice) << std::endl;
	//std::cout << "Does Jack have Spielberg? " << Jack.hasChild(&Spielberg) << std::endl << std::endl;



	//
	/*if (Seth.getFather() == NULL)
	{
		std::cout << "My father is NULL" << std::endl;
	}
	if (Seth.getMother() == NULL)
		std::cout << " and my mother is NULL" << std::endl;*/

		
	return 0;
}