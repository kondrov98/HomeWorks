#pragma once

#include "MyTools.h"

class  Visitor
{
private:

public:
    ~Visitor() = default;
    virtual void log(class Bomb& bomb) const = 0;
    virtual void log(class Plane& plane) const = 0;
};

class LogVisitor : public Visitor
{
private:

public:

    LogVisitor()
    {

    }

    ~LogVisitor()
    {

    }

    void log(class Bomb& bomb) const;

    void log(class Plane& plane) const;
    
};