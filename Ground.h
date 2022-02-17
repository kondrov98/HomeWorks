#pragma once

#include <vector>

#include "GameObject.h"
#include "MyTools.h"

//=============================================================================================================

enum CraterSize 
{ 
	SMALL_CRATER_SIZE = 9 
};

//=============================================================================================================

class interfaceCrater :public GameObject 
{
private:

public:
	bool  isInside(double xn) const;

	void Draw() const override;

};




//=============================================================================================================

class Ground : public GameObject
{
private:
	bool  isInsideAnyCrater(double x) const;

	std::vector<interfaceCrater*> vecCrates;

public:
	virtual interfaceCrater* create_a_crater() const = 0;

	virtual MyTools::ConsoleColor Color() const = 0;


    void Draw() const override;

	void  AddCrater(double xn);
};

class CommonGround : public Ground
{
public:

	interfaceCrater* create_a_crater() const
	{
		return new interfaceCrater;
	}

	MyTools::ConsoleColor Color() const
	{
		return MyTools::CC_Green;
	}


private:


};


class WinterGround : public Ground
{
public:
	interfaceCrater* create_a_crater() const
	{
		return new interfaceCrater;
	}

	MyTools::ConsoleColor Color() const
	{
		return MyTools::CC_White;
	}
private:

};