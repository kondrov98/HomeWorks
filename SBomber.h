#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"

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
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    void __fastcall DeleteStaticObj(GameObject* pObj);

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
    virtual  C finding_the_right_iterators(T begin, T end) = 0;
};

class BombIterator: public Iterator<std::vector < DynamicObject*>::iterator, std::vector < Bomb*>>
{
private:
    std::vector < DynamicObject*> DyO;
    std::vector < DynamicObject*>::iterator DyOIt;
    std::vector < Bomb*> Bombs;
public:
    BombIterator(std::vector <DynamicObject*> DynOb) : DyO(DynOb)
    {
     
    }

    virtual  std::vector < DynamicObject*>::iterator begin()
    {
        DyOIt = DyO.begin();
        while (dynamic_cast<Bomb*>(*DyOIt) == nullptr)
        {
            DyOIt++;
        }
        return DyOIt;
    }
    
    virtual  std::vector < DynamicObject*>::iterator end()
    {
        DyOIt = DyO.end();
        while (dynamic_cast<Bomb*>(*DyOIt) == nullptr)
        {
            DyOIt--;
        }

        return DyOIt;
    }


    virtual   std::vector < Bomb*> finding_the_right_iterators(std::vector < DynamicObject*>::iterator begin, std::vector < DynamicObject*>::iterator end)
    {
        while (begin != end)
        {
            Bomb* pBomb = dynamic_cast<Bomb*>(*begin);
            if ( pBomb != nullptr)
            {
                Bombs.push_back(pBomb);
            }
            begin++;
        }

        return Bombs;
    }
};
