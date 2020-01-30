//
//#include "../Digital_Scapes_Program_test/Person[3363].h"
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//
//
//// Pseudo Code
//void Person::getDescendants(People& results) const
//{
//	Person* temp_child;
//	//	Check to see if this person has any Children
//	if (this->children.size() > 0)
//	{
//		//	Check to see if the child has any Children
//		for (Person* child : children)
//		{
//			temp_child = child;
//			temp_child->getDescendants(results);
//			results.push_back(temp_child);
//
//				// continue until the child has no children
//					//	Append childs name
//			//++iter;
//		}
//			// Return
//		//	Increment iterator to the next vector position that will hold the next child of the parent if another child exists.
//		//	If the current childs position is equal to the end of the vector, then exit loop
//	}
//	else
//		results.push_back(temp_child);
//}
//void Person::getDescendants(People& results) const
//{
//	std::cout << "Inside getDescendants......\n\n";
//
//	People::const_iterator iter = children.begin();
//	Person* temp_child;
//	bool has_child = true;
//	while (has_child)
//	{
//		if (children.size() > 0)	//Must have a parent to have Ancestors
//		{
//			getDescendants(children.fin)
//			if (temp_child->children.size() == NULL)
//				has_child = false;
//			while (has_father)
//			{
//				if (temp_child->getFather() != NULL)
//				{
//					has_father = false;
//				}
//
//			}
//
//			results.push_back(temp_child);
//		}
//		else
//			has_father = false;
//		//Go up mother's ancestoral tree
//		if (mother != NULL)
//		{
//			mother->getAncestors(results);
//			if (temp_mother->getMother() == NULL)
//				has_mother = false;
//			while (has_mother)
//			{
//				if (temp_mother->getMother() != NULL)
//				{
//
//					has_mother = false;
//				}
//
//			}
//
//			results.push_back(temp_mother);
//
//		}
//		else
//			has_mother = false;
//		if (has_father == false && has_mother == false)
//			hasparents = false;
//	}
//
//
//}