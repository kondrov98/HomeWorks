#pragma once

#include <vector>
#include <functional>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "MyTools.h"

class Massivs
{
    public:
    Massivs(){}
    ~Massivs() {}
    int16_t getScore() const
    {
        return score;
    }

    int16_t getBombsNumber() const
    {
        return bombsNumber;
    }

    void setScore(int16_t _score)
    {
        score += _score;
    }

    void setBombsNumber()
    {
        bombsNumber--;
    }

    void addStatic(GameObject* obj)
    {
        vecStaticObj.push_back(obj);
    }

    void forEachStatic(std::function<void(GameObject&)>cb)
    {
        for (auto* obj : vecStaticObj)
        {
            if (obj != nullptr)
            {
                cb(*obj);
            }
        }
    } 

    void addDynamic(DynamicObject* obj)
    {
        vecDynamicObj.push_back(obj);
    }

    void forEachDynamic(std::function<void(DynamicObject&)>cb)
    {
        for (auto* obj : vecDynamicObj)
        {
            if (obj != nullptr)
            {
                cb(*obj);
            }
        }
    }


    void removeStatic(GameObject* obj)
    {
        auto it = vecStaticObj.begin();
        for (; it != vecStaticObj.end(); it++)
        {
            if (*it == obj)
            {
                vecStaticObj.erase(it);
                break;
            }
        }
    }

    void removeDynamic(DynamicObject* obj)
    {
        auto it = vecDynamicObj.begin();
        for (; it != vecDynamicObj.end(); it++)
        {
            if (*it == obj)
            {
                vecDynamicObj.erase(it);
                break;
            }
        }
    }

    Ground* FindGround() const;
    Plane* FindPlane() const;
    LevelGUI* FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    private:
    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    uint16_t bombsNumber=10;
    int16_t score;
};

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
    void CommandExecutor(commands* cmd);

private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void CheckDestoyableObjects(Bomb* pBomb);

    
    


    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t  deltaTime, fps;
    Massivs* m; 
};

class commands
{
private:
    
public:
    virtual     ~commands() {}
    virtual void  Execute() = 0;
};

class CommandDeleteDynamicObj : public commands
{
private:
    DynamicObject* obj;
    Massivs* m;
public:

    CommandDeleteDynamicObj(DynamicObject* obj, Massivs* m) : obj(obj), m(m)
    {

    }

     void Execute() override
    {
        m->removeDynamic(obj);
    }
};

class CommandDeleteStaticObj :public commands
{
private:
    GameObject* obj;
    Massivs* m;
public:

    CommandDeleteStaticObj(GameObject* obj, Massivs* m) : obj(obj), m(m)
    {

    }

    void Execute() override
    {
        m->removeStatic(obj);
    }
};

class CommandDropBomb :public commands
{
private:
    Massivs* m;
public:
    CommandDropBomb(Massivs* m)         
    {

    }
    void Execute() override
    {
        if (m->getBombsNumber() > 0)
        {
            MyTools::LoggerSingleton::getInstance().WriteToLog(string(__FUNCTION__) + " was invoked");

            Plane* pPlane = m->FindPlane();
            double x = pPlane->GetX() + 4;
            double y = pPlane->GetY() + 2;

            IBomb* pBomb = new BombDecorator(std::make_unique<Bomb>());
            pBomb->SetDirection(0.3, 1);
            pBomb->SetSpeed( 2);
            pBomb->SetPos(x, y);
            pBomb->SetWidth(SMALL_CRATER_SIZE);

            m->addDynamic(pBomb);
            m->setBombsNumber();
            m->setScore( -pBomb->GetBombCost());
        }
    }
};