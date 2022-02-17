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
	virtual bool  isInside(double xn) const = 0;
};

class Crater : public interfaceCrater
{
public:

	bool  isInside(double xn) const;
	
	void Draw() const override;

private:

};

class WinterCrater : public interfaceCrater
{
public:

	bool  isInside(double xn) const;

	void Draw() const override;

private:

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
		return new Crater;
	}

	MyTools::ConsoleColor Color() const
	{
		return CC_Green;
	}


private:


};


class WinterGroundWinter : public Ground
{
public:
	interfaceCrater* create_a_crater() const
	{
		return new WinterCrater;
	}

	MyTools::ConsoleColor Color() const
	{
		return CC_White;
	}
private:

};