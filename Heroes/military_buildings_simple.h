#ifndef _MILITARY_BUILDINGS_SIMPLE_H_
#define _MILITARY_BUILDINGS_SIMPLE_H_

#include <iostream>
using namespace std;

class buildings
{
protected:
    int gold;
    int stone;
    int wood;

public:
    buildings()
    {
        gold = 0;
        stone = 0;
        wood = 0;
    }

    ~buildings() {}

    int get_gold() { return gold; }
    int get_stone() { return stone; }
    int get_wood() { return wood; }

    void ability()
    {
        cout << "No ability" << endl;
    }
};


class Guardhouse : public buildings
{
public:
    Guardhouse() { gold = 500; stone = 10; }

    void ability() { cout << "+14 Pikemen per week" << endl; }
};

class GuardhouseUp : public Guardhouse
{
public:
    GuardhouseUp() { gold = 1000; stone = 5; }

    void ability() { cout << "Recruit Halberdiers instead" << endl; }
};


class ArcherTower : public buildings
{
public:
    ArcherTower() { gold = 1000; wood = 5; stone = 5; }

    void ability() { cout << "+9 Archers per week" << endl; }
};

class ArcherTowerUp : public ArcherTower
{
public:
    ArcherTowerUp() { gold = 1000; wood = 5; stone = 5; }

    void ability() { cout << "Recruit Marksmen instead" << endl; }
};
class GriffinTower : public buildings
{
public:
    GriffinTower() { gold = 1000; stone = 5; }

    void ability() { cout << "+7 Griffins per week" << endl; }
};

class GriffinTowerUp : public GriffinTower
{
public:
    GriffinTowerUp() { gold = 1000; stone = 5; }

    void ability() { cout << "Recruit Royal Griffins instead" << endl; }
};

class GriffinBastion : public buildings
{
public:
    GriffinBastion() { gold = 1000; }

    void ability() { cout << "Raises Griffin growth by +3 per week" << endl; }
};



class Barracks : public buildings
{
public:
    Barracks() { gold = 2000; stone = 5; }

    void ability() { cout << "+4 Swordsmen per week" << endl; }
};

class BarracksUp : public Barracks
{
public:
    BarracksUp() { gold = 2000; stone = 5; }

    void ability() { cout << "Recruit Crusaders instead" << endl; }
};



class Monastery : public buildings
{
public:
    Monastery() { gold = 3000; wood = 5; stone = 5; }

    void ability() { cout << "+3 Monks per week" << endl; }
};

class MonasteryUp : public Monastery
{
public:
    MonasteryUp() { gold = 1000; wood = 2; stone = 2; }

    void ability() { cout << "Recruit Zealots instead" << endl; }
};




class TrainingGrounds : public buildings
{
public:
    TrainingGrounds() { gold = 5000; wood = 20; }

    void ability() { cout << "+2 Cavaliers per week" << endl; }
};

class TrainingGroundsUp : public TrainingGrounds
{
public:
    TrainingGroundsUp() { gold = 3000; wood = 10; }

    void ability() { cout << "Recruit Champions instead" << endl; }
};


class PortalOfGlory : public buildings
{
public:
    PortalOfGlory() { gold = 20000; wood = 10; stone = 10; }

    void ability() { cout << "+1 Angel per week" << endl; }
};

class PortalOfGloryUp : public PortalOfGlory
{
public:
    PortalOfGloryUp() { gold = 20000; wood = 10; stone = 10; }

    void ability() { cout << "Recruit Archangels instead" << endl; }
};

#endif