#ifndef _STUD_H_
#define _STUD_H_
#include <iostream>

using namespace std;


class buildings
{
protected:
    int gold;
    int stone;
    int wood;
public:
    buildings ()
    {
        cout << "building created" << endl;
    }

    int get_gold()
    {
        return gold;
    }
    int get_stone()
    {
        return stone;
    }
    int get_wood()
    {
        return wood;
    }
    void set(int gold_, int stone_, int wood_)
    {
        gold = gold_;
        stone = stone_;
        wood = wood_;
    }
};

class Tavern: public buildings
{
public:
    Tavern() {
        cout << "Tavern is created" << endl;
        gold = 500;
    }
};

class Well: public buildings
{
public:
    Well() {
        cout << "Well is created" << endl;
        gold = 500;
    }
};

class Estate: public buildings
{
public:
    Estate() {
        cout << "Estate is created" << endl;
        gold = 1000;
    }
};

class EstateUp: public Estate
{
public:
    EstateUp() {
        cout << "Estate is upgraded" << endl;
        gold = 1000;
    }
};

class Blacksmith: public buildings
{
public:
    Blacksmith() {
        cout << "Blacksmith is created" << endl;
        gold = 1500;
    }
};

class Marketplace: public buildings
{
public:
    Marketplace() {
        cout << "Marketplace is created" << endl;
        gold = 500;
    }
};

class MarketplaceUp: public Marketplace
{
public:
    MarketplaceUp() {
        cout << "Marketplace is upgraded" << endl;
        gold = 500;
    }
};

class Fortifications: public buildings
{
public:
    Fortifications() {
        cout << "Fortifications is created" << endl;
        gold = 2000;
        stone = 20;
    }
};

class FortificationsUp: public Fortifications
{
public:
    FortificationsUp() {
        cout << "Fortifications is upgraded" << endl;
        gold = 4000;
    }
};

class Citadel: public buildings
{
public:
    Citadel() {
        cout << "Citadel is created" << endl;
        gold = 2500;
        stone = 10;
    }
};

class CitadelUp: public Citadel
{
public:
    CitadelUp() {
        cout << "Citadel is upgraded" << endl;
        gold = 5000;
    }
};

class Castle: public buildings
{
public:
    Castle() {
        cout << "Castle is created" << endl;
        gold = 5000;
        stone = 20;
    }
};

#endif
