
#include <iostream>

#include "Bomb.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Bomb::Draw() const
{
    MyTools::ScreenSingleton::getInstance().SetColor(CC_LightMagenta);
    ScreenSingleton::getInstance().GotoXY(x, y);
    cout << "*";
}

void BombDecorator::Move(uint16_t time)
{
    wrapee->Move(time * 1.6);
}

void BombDecorator::Draw() const
{
    wrapee->Draw();
    // Некоторое изменение внешнего вида бомбы
   MyTools::ScreenSingleton::getInstance().GotoXY(wrapee->GetX(), wrapee->GetY() - 1);
    cout << "|";
}

BombDecorator::BombDecorator(std::unique_ptr<Bomb> wrapee) : wrapee(std::move(wrapee)) 
{

}

void BombDecorator::SetPos(double nx, double ny)
{
    x = nx; y = ny;
}

double BombDecorator::GetY() const 
{ 
    return wrapee->GetY(); 
}

double BombDecorator::GetX() const 
{ 
    return wrapee->GetX(); 
}

void BombDecorator::SetWidth(uint16_t widthN)
{ 
    wrapee->SetWidth(widthN); 
}

uint16_t BombDecorator::GetWidth() const 
{
    return wrapee->GetWidth();
}

void BombDecorator::SetSpeed(double sp)
{
    wrapee->SetSpeed(sp);
}

void BombDecorator::SetDirection(double dx, double dy)
{ 
    wrapee->SetDirection(dx, dy);
}