// Simple.h
// By Antonio F. Huertas
// Specification and implementation file for class Simple.

#include <string>
using std::string;

class Simple
{
public:
	Simple();
	Simple(string anId, string aValue);
	void setId(string newId);
	void setValue(string newValue);
	string getId() const;
	string getValue() const;
private:
	string id, value;
};

Simple::Simple()
{
	id = "";
	value = "";
}

Simple::Simple(string anId, string aValue)
{
	id = anId;
	value = aValue;
}

void Simple::setId(string newId)
{
	id = newId;
}

void Simple::setValue(string newValue)
{
	value = newValue;
}

string Simple::getId() const
{
	return id;
}

string Simple::getValue() const
{
	return value;
}
