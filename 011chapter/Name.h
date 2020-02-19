// **************************************************************************** 
// File: Name.h 
// Author: Sergio Ortiz Paz 
// Created: Tue Feb 18 23:34:41 2020 
// Description: ARCHIVO DE ESPECIFICACIÓN 
// **************************************************************************** 

#include <iostream>
#include <string>

using namespace std;

enum RelationType{BEFORE, SAME, AFTER};

class Name
{
	public:
		Name();
		Name(
				string firstName,
				string middleName,
				string lastName);
		
		void SetName(
				string firstName,
				string middleName,
				string lastName);

		void ReadName();
		string FirstName() const;
		string LastName() const;
		string MiddleName() const;
		char MiddleInitial() const;
		RelationType ComparedTo(Name otherName) const;
	
	private:
		string first;
		string last;
		string middle;

};

