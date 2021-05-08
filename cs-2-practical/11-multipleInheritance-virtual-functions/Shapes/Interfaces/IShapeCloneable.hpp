#pragma once

class IDescribableShape;
class IDescribableShapeCloneable
{
public:
	virtual IDescribableShape* clone() const = 0;
};

