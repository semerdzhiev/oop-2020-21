#pragma once
#include <ostream>
#include <istream>

class ISerializable
{
public:
	virtual void load(std::istream& in) = 0;
	virtual void save(std::ostream& out) const = 0;

protected:
	~ISerializable() {};
};
