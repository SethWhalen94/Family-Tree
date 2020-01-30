// Person.cpp - Implementation of the Person
// Date: 01/19/2020
// Created by: Seth Whalen
// Email: seth.whalen@alumni.ubc.ca

#include <stdio.h>
#include <iostream>
#include "Person.h"

//====== Constructors ========
Person::Person(Sex my_sex, const std::string& name) : sex(my_sex), name(name)
{
	father = NULL;
	mother = NULL;
};


//========Destructor==========
Person::~Person()
{
	father = NULL;
	mother = NULL;
	children.clear();
};

//========== Member Function Definitions ================

/**
		Set the father of this person.  This method automatically removes
			this person from the list of children of the previous father
			and adds it to the new father's children. It can be used to
			unset the parent of a person.

		@param the father object, NULL is allowed
		@return true if successful
	*/
bool Person::setFather(Person* new_father)
{
	if (this->father != NULL)
	{
		std::cout << "Inside setFather......\n\n";
		//this->father->findChild(this);		//Remove THIS person as a child of the current father
		this->father = new_father;				//Set THIS person's father as new_father
		if(new_father != NULL)
			new_father->addChild(this);				//Set THIS person as a child of new_father
	}
	else
	{
		this->father = new_father;
		new_father->addChild(this);
	}
	return true;
};


bool Person::setMother(Person* new_mother)
{
	std::cout << "Inside setMother......\n\n";
	if (this->mother != NULL)
	{
		//this->mother->removeChild(this);		//Remove THIS person as a child of the current mother
		this->mother = new_mother;				//Set THIS person's mother as new_mother
		if(new_mother != NULL)
			new_mother->addChild(this);				//Set THIS person as a child of new_mother
	}
	else
	{
		this->mother = new_mother;
	}

	return true;
};


/**
	Checks if this person has a given child.

	@param the child to check
	@return true if it does
*/
bool Person::hasChild(const Person* my_child) const
{
	//bool present = false;
	std::cout << "Inside hasChild......\n\n";

	for (Person* child : children)
	{
		if (my_child->name == child->name)
		{
			/*if(my_child->sex == child->sex)*/
				//Child has been found : return true
				return true;
		}
	}

	//This person does not have the child : return false
	return false;

};

/**
	Adds a child to the person's child list.  It automatically makes this
	object the child's parent and removes it from the old parent's children
	list.

	@param child to be added
	@return true if successful
*/
bool Person::addChild(Person* my_child)
{
	std::cout << "Inside addChild......\n\n";

	if (sex == MALE)
	{
		if (my_child->father != this)//must be a father
		{
			my_child->father = this;
			//Add child to THIS person's children
			children.push_back(my_child);
			return true;
		}
	}
	if (sex == FEMALE)
	{
	if (my_child->mother != this)   //Must be a mother
	{
		my_child->mother = this;
		//Add child to THIS person's children
		children.push_back(my_child);
		return true;

	}
	}

	//Check if THIS person had the child in their children
	if (this->hasChild(my_child) == false)
	{
		children.push_back(my_child);
	}

	return false;
};

/**
	Remove a child from this person's children list.  It automatically sets
	the corresponding parent of the child to NULL.

	@param child to be removed
	@return true if successful
*/
bool Person::removeChild(Person* my_child)
{
	std::cout << "Inside removeChild......\n\n";

	//Check if THIS person has a child/children
	bool child_present = this->hasChild(my_child);
	//People::size_type index;
	
	//If child exists in children, find location in People vector
	if (child_present)
	{
		People::iterator location = findChild(my_child);
		std::cout << "Location: " << *location << std::endl;
		std::cout << "my_child:" << my_child << std::endl;
		if (*location == my_child)
		{
			try
			{		
				//	Remove the child
				this->children.erase(location);
				//	Set child's parents to NULL
				my_child->setFather(NULL);
				my_child->setMother(NULL);
			}
			catch (int e)
			{
				std::cout << "Exception thrown. Error number: " << e << std::endl;
				return false;
			}
		}
	}
	return true;
};

//People::size_type getNumChildren() const { return children.size(); }
//Person* getChild(People::size_type index) const { return children.at(index); }

/**
	Remove all children of this person.  It automatically sets the children's
	corresponding parents to NULL.
*/
void Person::removeAllChildren()
{
	std::cout << "Inside removeAllChildren......\n\n";
	std::cout << "Printing out all of " << this->name << "'s children BEFORE removing all...\n";
	for (Person* child : children)
		std::cout << child->name << std::endl;


	for (Person* child : children)
	{
		child->setFather(NULL);
		child->setMother(NULL);
		children.erase(children.begin());

	}

	//	====== DEBUG CODE =========
	/*std::cout << "Printing out all of " << this->name << "'s children AFTER removing all...\n";
	for (Person* child : children)
		std::cout << child->name << std::endl;*/

};

/**
	Get all ancestors of this person.
*/
void Person::getAncestors(People& results) const
{
	std::cout << "Inside getAncestors......\n\n";

	Person* temp_father = father;
	Person* temp_mother = mother;
	bool has_father = true;
	bool has_mother = true;
	bool hasparents = true;

	//	Base Case #1
	while (hasparents)
	{
		//	Base Case #2
		if (father != NULL)	//Must have a parent to have Ancestors
		{
			//	Recursively call getAncestors
			father->getAncestors(results);
			if (temp_father->getFather() == NULL)
				has_father = false;
			while (has_father)
			{
				if (temp_father->getFather() != NULL)
				{
					has_father = false;
				}
			}

			//	Add temp_father to results of Ancestors
			results.push_back(temp_father);
		}
		else
			has_father = false;
		//Go up mother's ancestoral tree
		//	Base Case #3
		if (mother != NULL)
		{
			mother->getAncestors(results);
			if (temp_mother->getMother() == NULL)
				has_mother = false;
			while (has_mother)
			{
				if (temp_mother->getMother() != NULL)
				{			
					has_mother = false;
				}
			}

			results.push_back(temp_mother);

		}
		else
			has_mother = false;
		if (has_father == false && has_mother == false)
			hasparents = false;
	}


};

/**
	Get all descendants of this person.
*/
void Person::getDescendants(People& results) const
{
	std::cout << "Inside getDescendants......\n\n";

	Person* temp_child;
	//	Check to see if this person has any Children
	if (this->children.size() > 0)
	{
		//	Check to see if the child has any Children
		for (Person* child : children)
		{
			temp_child = child;
			temp_child->getDescendants(results);
			results.push_back(temp_child);

			// continue until the child has no children
				//	Append childs name
		//++iter;
		}
		// Return
	//	Increment iterator to the next vector position that will hold the next child of the parent if another child exists.
	//	If the current childs position is equal to the end of the vector, then exit loop
	}
	/*else
		results.push_back(temp_child);*/


}

/**
	Get all siblings of this person.
*/
void Person::getSiblings(People& results) const
{
	std::cout << "Inside getSiblings......\n\n";

	if (father != NULL)
	{
		for (Person* child : father->children)
		{
			if (child != this)
			{
				results.push_back(child);
				//std::cout << child->name << std::endl;

			}
			//std::cout << child->name << std::endl;
		}
	}
	else if (mother != NULL)
	{
		for (Person* child : mother->children)
		{
			if (child != this)
			{
				results.push_back(child);
				//std::cout << child->name << std::endl;

			}
			//std::cout << child->name << std::endl;
		}
	}
	else
	{
		std::cout << "You do not have any parents...\n\n";
	}

};

/**
	Get all cousins of this person in the same generation.
*/
void Person::getCousins(People& results) const
{
	std::cout << "Inside getCousins......\n\n";

	People father_sibs;
	People mother_sibs;
	this->father->getSiblings(father_sibs);
	this->mother->getSiblings(mother_sibs);

	if (father_sibs.size() > 0)	//There must be at least 1 cousin on father's side
	{
		// For each sibling of the father, get one child and then get their siblings
		for (Person* sib : father_sibs)
		{
			if (sib->children.size() > 0)
			{
				for (Person* cousin : sib->children)
				{
					results.push_back(cousin);
				}
			}
		}

	}

	if (mother_sibs.size() > 0)
	{
		// For each sibling of the mother, get one child and then get their siblings
		for (Person* sib : mother_sibs)
		{
			if (sib->children.size() > 0)
			{
				for (Person* cousin : sib->children)
				{
					results.push_back(cousin);
				}
			}
		}
	}


};


//Use to read/write child
People::iterator Person::findChild(const Person* child)
{
	std::cout << "Inside findChild......\n\n";
	/*for (People::iterator iter = children.begin(); iter != children.end(); ++iter)
	{
		if (*iter == child)
		{
			std::cout << *iter << std::endl;
			return iter;
		}
	}*/

	People::iterator itr = std::find(children.begin(), children.end(), child);
	return itr;

};
//Use to read child
People::const_iterator Person::findChild(const Person* child) const
{
	std::cout << "Inside findChild for read only......\n\n";
	std::cout << "Child: " << child<< std::endl;
	
	People::const_iterator itr = std::find(children.begin(), children.end(), child);
	std::cout << "itr:" << *itr << std::endl;
	return itr;

};