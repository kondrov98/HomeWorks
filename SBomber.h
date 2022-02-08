#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "Commander.h"

class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void CheckDestoyableObjects(Bomb* pBomb);

    void DeleteDynamicObj(DynamicObject * pBomb);
    void DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
};

template < typename T, typename C>
class Iterator
{
private:

public:
    virtual  T begin() = 0;
    virtual  T end() = 0;
    virtual  C finding_the_right_iterators() = 0;
};

class BombIterator: public Iterator<std::vector < DynamicObject*>::iterator, std::vector < Bomb*>>
{
private:
    std::vector < DynamicObject*> vecDynamicObj;
    std::vector < DynamicObject*>::iterator vecDynamicObject_Iterator;
    std::vector < Bomb*> vecBombs;
public:
    BombIterator(std::vector <DynamicObject*> vecDynamicObj) : vecDynamicObj(vecDynamicObj)
    {
     
    }

    virtual  std::vector < DynamicObject*>::iterator begin()
    {
        vecDynamicObject_Iterator = vecDynamicObj.begin();
        while (dynamic_cast<Bomb*>(*vecDynamicObject_Iterator) == nullptr && vecDynamicObject_Iterator != vecDynamicObj.end()-1)
        {
            vecDynamicObject_Iterator+=1;
        }
        return vecDynamicObject_Iterator;
    }
    
    virtual  std::vector < DynamicObject*>::iterator end()
    {
        vecDynamicObject_Iterator = vecDynamicObj.end()-1;
        while (dynamic_cast<Bomb*>(*vecDynamicObject_Iterator) == nullptr && vecDynamicObject_Iterator!=vecDynamicObj.begin())
        {
            vecDynamicObject_Iterator-=1;
        }

        return vecDynamicObject_Iterator+1;
    }


    virtual   std::vector < Bomb*> finding_the_right_iterators()
    {
        std::vector < DynamicObject*>::iterator begin = this->begin();
        std::vector < DynamicObject*>::iterator end = this->end();
        while (begin != end)
        {
            Bomb* pBomb = dynamic_cast<Bomb*>(*begin);
            if ( pBomb != nullptr)
            {
                vecBombs.push_back(pBomb);
            }
            begin+=1;
        }

        return vecBombs;
    }
};
