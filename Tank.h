#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"



class ITank : public DestroyableGroundObject
{
public:

	virtual bool isInside(double x1, double x2) const =0;

	virtual uint16_t GetScore() const = 0;

	virtual void Draw() const =0 ;
};


class Tank : public ITank
{
public:

	bool isInside(double x1, double x2) const override;

	uint16_t GetScore() const override { return score; }

	void Draw() const override;

private:

	const uint16_t score = 30;
};

class TankAdaptee {
public:

    TankAdaptee() : x(0.0), y(0.0), width(0) { }

    void Paint();
    bool  isInRange(double x1, double x2) const;

     uint16_t GetScore() const { return score; }

     void SetPos(double nx, double ny) { x = nx; y = ny; }
     double GetY() const { return y; }
     double GetX() const { return x; }

     void SetWidth(uint16_t widthN) { width = widthN; }
     uint16_t GetWidth() const { return width; }

protected:

    double x, y;
    uint16_t width;
    const uint16_t score = 30;
};

class TankAdapter : public ITank
{
private:
    TankAdaptee* adaptee;
public:

    bool isInside(double x1, double x2) const
    {
        adaptee->isInRange(x1,x2);
    }

    uint16_t GetScore() const
    {
        adaptee->GetScore();
    }

    void Draw() const
    {
        adaptee->Paint();
    }

    void SetPos(double nx, double ny)
    {
        adaptee->SetPos(nx, ny);
    }

    double GetY() const
    {
        adaptee->GetY();
    }

    double GetX() const
    {
        adaptee->GetX();
    }

    void SetWidth(uint16_t widthN)
    {
        adaptee->SetWidth(widthN);
    }

    uint16_t GetWidth() const
    {
        adaptee->GetWidth();
    }
};