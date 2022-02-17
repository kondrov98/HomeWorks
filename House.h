#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"

class House : public DestroyableGroundObject
{
public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

	friend class  HouseBuilderA;

private:

	const uint16_t score = 40;
	char look[7][14] = { {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
						 {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
						 {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
						 {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
						 {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
						 {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
						 {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '} };
};

class HouseBuilder
{
private:

public:
	virtual ~HouseBuilder() = default;
	virtual void createWalls() = 0;    //стены
	virtual void createFence() = 0;    //забор
	virtual void createSmallWindow() = 0;
	virtual void createBigWindow() = 0;
	virtual void createRoof() = 0;
	virtual void createPipe() = 0;
};

class HouseBuilderA: public HouseBuilder
{
private:
	House* house;
public:

	HouseBuilderA(House* house): house(house)
	{
	
	}
	~HouseBuilderA()
	{
	
	}
	
	void createWalls()
	{
		for (short i = 2; i <= 11; i++)
		{
			for (short j = 6; j >= 3; j--)
			{
				house->look[j][i] = '#';
			}
		}
	}

	void createFence()
	{
		for (short i = 0; i <= 13; i += 13)
		{
			for (short j = 6; j >= 5; j--)
			{
				house->look[j][i] = '#';
			}
		}
	}

	void createSmallWindow()
	{
		for (short i = 6; i <= 7; i++)
		{
			for (short j = 5; j >= 4; j--)
			{
				house->look[j][i] = ' ';
			}
		}
	}

	void createBigWindow()
	{
		for (short i = 5; i <= 8; i++)
		{
			for (short j = 5; j >= 3; j--)
			{
				house->look[j][i] = ' ';
			}
		}
	}

	void createRoof()
	{
		for (short j = 2; j >= 0; j--)		
		{
			for (short i = 1 - (j - 2); i <= 12 + (j - 2); i++)
			{
				house->look[j][i] = '#';
			}
		}
	}

	void createPipe()
	{
		for (short j = 2; j >= 0; j--)
		{
			for (short i = 10; i <= 11; i++)
			{
				house->look[j][i] = '#';
			}
		}
	}

};

class HouseDirector
{
private:

public:
	virtual ~HouseDirector() = default;
	virtual void Construct(HouseBuilder* Builder) = 0;
};

class HouseDirectorA : public HouseDirector
{
private:

public:
	~HouseDirectorA()
	{

	}

	void Construct(HouseBuilder* Builder)
	{
		Builder->createWalls();
		Builder->createSmallWindow();
		Builder->createRoof();
	}

};

class HouseDirectorB : public HouseDirector
{
private:

public:

	~HouseDirectorB()
	{

	}
	void Construct(HouseBuilder* Builder)
	{
		Builder->createWalls();
		Builder->createSmallWindow();
		Builder->createRoof();
		Builder->createFence();
	}

};

class HouseDirectorC : public HouseDirector
{
private:

public:
	~HouseDirectorC()
	{

	}

	void Construct(HouseBuilder* Builder)
	{
		Builder->createWalls();;
		Builder->createSmallWindow();
		Builder->createRoof();
		Builder->createFence();
		Builder->createPipe();
	}

};

class HouseDirectorD : public HouseDirector
{
private:

public:
	~HouseDirectorD()
	{

	}

	void Construct(HouseBuilder* Builder)
	{
		Builder->createWalls();
		Builder->createBigWindow();
		Builder->createRoof();
	}
};

class HouseDirectorE : public HouseDirector
{
private:

public:
	~HouseDirectorE()
	{

	}

	void Construct(HouseBuilder* Builder)
	{
		Builder->createWalls();
		Builder->createBigWindow();
		Builder->createRoof();
		Builder->createFence();
	}
};

class HouseDirectorF : public HouseDirector
{
private:

public:
	~HouseDirectorF()
	{

	}

	void Construct(HouseBuilder* Builder)
	{
		Builder->createWalls();
		Builder->createBigWindow();
		Builder->createRoof();
		Builder->createFence();
		Builder->createPipe();
	}
};
