// **************************************************************************** 
// File: Name.cpp 
// Author: Sergio Ortiz Paz 
// Created: Tue Feb 18 23:43:13 2020 
// Description: ARCHIVO DE IMPLEMENTACIÓN 
// **************************************************************************** 


#include "Name.h"
#include <iostream>

using namespace std;


Name::Name() {
	first = " ";
	last = " ";
	middle = " ";
}

Name::Name(
		string firstName,
		string middleName,
		string lastName)
{
	first = firstName;
	middle = middleName;
	last = lastName;
}

void Name::SetName(
		string firstName,
		string middleName,
		string lastName)
{
	first = firstName;
	last = lastName;
	middle = middleName;
}

void Name::ReadName()
{
	cout << "Enter first name: ";
	cin >> first;
	cout << "Enter middle name: ";
	cin >> middle;
	cout << "Enter last name: ";
	cin >> last;
}


string Name::FirstName() const
{
	return first;
}

string Name::LastName() const
{
	return last;
}

string Name::MiddleName() const
{
	return middle;
}

char Name::MiddleInitial() const
{
	return middle[0];
}

RelationType Name::ComparedTo(Name otherName)
{
	//Implement later
}































