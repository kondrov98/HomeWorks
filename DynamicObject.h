#pragma once

#include <stdint.h>

#include "GameObject.h"
#include "MyTools.h"
#include "Visitor.h"


class DynamicObject : public GameObject 
{
public:

    DynamicObject() : speed(0.0), xDirction(0.0), yDirection(0) { }

    void SetSpeed(double sp) { speed = sp; }
    void SetDirection(double dx, double dy) { xDirction = dx; yDirection = dy; }
    
    struct Dirction
    {
        double Direction_x, Direction_y;
    }dirction;

    virtual void Move(uint16_t time) { x += xDirction * speed * time * 0.001; y += yDirection * speed * time * 0.001; };

    double GetSpeed()
    {
      return speed;
    }

    Dirction GetDirection()
    {
        dirction.Direction_x = xDirction;
        dirction.Direction_y = yDirection;
        return dirction;
    }

    virtual void Accept(const Visitor& v) = 0;

protected:

    double speed;
    double xDirction, yDirection;

};


