#include "Bomb.h"
#include "Plane.h"
#include "Visitor.h"


void LogVisitor::log( Bomb& bomb) const
{
    MyTools::LoggerSingleton::getInstance().WriteToLog("Bomb Speed = " + std::to_string(bomb.GetSpeed()) + 
                                                    ";\nThe direction of the bomb on the x axis" + std::to_string(bomb.GetDirection().Direction_x) + 
                                                    ";\nThe direction of the bomb on the y axis" + std::to_string(bomb.GetDirection().Direction_y) + ";");
}

void LogVisitor::log(Plane& plane) const
{
    MyTools::LoggerSingleton::getInstance().WriteToLog("Bomb Speed = " + std::to_string(plane.GetSpeed()) + 
                                                    ";\nThe direction of the plane on the x axis" + std::to_string(plane.GetDirection().Direction_x) + 
                                                    ";\nThe direction of the plane on the y axis" + std::to_string(plane.GetDirection().Direction_y)+";");
}