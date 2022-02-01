#pragma once
#include <memory>
#include "DynamicObject.h"
#include "MyTools.h"
class IBomb : public DynamicObject
{
public:

	virtual uint16_t GetBombCost() const = 0; // стоимость бомбы в очках

	void Draw() const override;

private:

};

class Bomb : public IBomb
{
public:

	virtual uint16_t GetBombCost() const
	{
		return 20;
	}; // стоимость бомбы в очках

	void Draw() const override;

private:

};


class BombDecorator : public IBomb
{
private:
	DynamicObject* bomb;
	std::unique_ptr<Bomb> wrapee;
public:
	BombDecorator(std::unique_ptr<Bomb> wrapee);
	
	virtual uint16_t GetBombCost() const
	{
		return 20;
	}

	void Move(uint16_t time);

	void Draw() const;

	void SetPos(double nx, double ny);

	double GetY() const; 
	double GetX() const;

	void SetWidth(uint16_t widthN); 
	uint16_t GetWidth() const; 
	

	void SetSpeed(double sp); 
	void SetDirection(double dx, double dy); 
};