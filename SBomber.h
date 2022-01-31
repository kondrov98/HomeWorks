#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "MyTools.h"

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
    commands* pcommands;
};

class commands
{
private:

public:
    virtual     ~commands() {}
    virtual void ComDeleteDynamicObj() = 0;
    virtual void ComDeleteStaticObj() = 0;
    virtual void ComDropBomb() = 0;
};

class CommandDeleteDynamicObj: public commands
{

    DynamicObject* pBomb;
    std::vector<DynamicObject*> vecDynamicObj;
public:
      CommandDeleteDynamicObj (DynamicObject* pBomb, std::vector<DynamicObject*> &vecDynamicObj):pBomb(pBomb), vecDynamicObj(vecDynamicObj)
      {
         
      }


      void ComDeleteDynamicObj() override
      {
          auto it = vecDynamicObj.begin();
          for (; it != vecDynamicObj.end(); it++)
          {
              if (*it == pBomb)
              {
                  vecDynamicObj.erase(it);
                  break;
              }
          }
      }
};

class CommandDeleteStaticObj:commands
{
private:
    GameObject* pObj;
    std::vector<GameObject*> vecStaticObj;
public:
      CommandDeleteStaticObj (GameObject* pObj, std::vector<GameObject*> &vecStaticObj):pObj(pObj), vecStaticObj(vecStaticObj)
      {
         
      }


     void ComDeleteStaticObj() override
      {
         auto it = vecStaticObj.begin();
         for (; it != vecStaticObj.end(); it++)
         {
             if (*it == pObj)
             {
                 vecStaticObj.erase(it);
                 break;
             }
         }
      }
};

class CommandDropBomb:commands
{
private:
    const Plane* pPlane;
    std::vector<DynamicObject*> vecDynamicObj;
    uint16_t bombsNumber;
    short SpeedBomb;
    uint16_t Crater_Size;
    int16_t score;
public:
      CommandDropBomb (const Plane* pPlane, std::vector<DynamicObject*>& vecDynamicObj, const uint16_t &bombsNumber, short SpeedBomb, uint16_t Crater_Size,  int16_t &score):
                       pPlane(pPlane), vecDynamicObj(vecDynamicObj), bombsNumber(bombsNumber), SpeedBomb(SpeedBomb), Crater_Size(Crater_Size), score(score)
      {
         
      }
      void ComDropBomb() override
      {
          if (bombsNumber > 0)
          {
              MyTools::LoggerSingleton::getInstance().WriteToLog(string(__FUNCTION__) + " was invoked");

              Plane* pPlane; //= FindPlane();
              double x = pPlane->GetX() + 4;
              double y = pPlane->GetY() + 2;

              Bomb* pBomb = new Bomb;
              pBomb->SetDirection(0.3, 1);
              pBomb->SetSpeed(SpeedBomb);
              pBomb->SetPos(x, y);
              pBomb->SetWidth(Crater_Size);

              vecDynamicObj.push_back(pBomb);
              bombsNumber--;
              score -= Bomb::BombCost;
          }
      }
};

