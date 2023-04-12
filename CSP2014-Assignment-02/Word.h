#pragma once

#include <string>

/* James Boyd, Student ID: 10629572, 12/4/2023
A structure to store the details of a word from a dictionary file provided 
by the user. The structure has three properties, all of type String: name, type
and definition. There are no methods. */
//struct Word
//{
//	std::string name, type, definition;
//};

class Word
{
	std::string name, type, definition;

	// Default constructor
	Word() {}

	// Overloaded constructor allowing name, type and definition properties to be set
	Word(string nameToSet, string typeToSet, string definitionToSet) 
	{
		// set properties
	}
	

	// Setters and Getters
	private: string getName()
	{
		return name;
	}

	private: void setName(string nameToSet)
	{
		this->name = nameToSet;
	}

	private: string getType()
	{
		return type;
	}

	private: void setType(string typeToSet)
	{
		this->type = typeToSet;
	}

	private: string getDefinition() 
	{
		return definition;
	}

	private: string setDefinition(string definitionToSet)
	{
		this->definition = definitionToSet;
	}
};
