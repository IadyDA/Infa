#ifndef _STUD_H_
#define _STUD_H_
#include <iostream>
#include <string>
using namespace std;

class Units
{
private:
    int attack;
    int defense;
    int damage;
    int health;
    int speed;
    int growth;
    string ability;

public:
    Units() : attack(0), defense(0), damage(0), health(0), speed(0), growth(0), ability("None")
    {
    }

    // GETTERS
    int getAttack() const { return attack; }
    int getDefense() const { return defense; }
    int getDamage() const { return damage; }
    int getHealth() const { return health; }
    int getSpeed() const { return speed; }
    int getGrowth() const { return growth; }
    string getAbility() const { return ability; }

    // SETTERS with validation
    void setAttack(int value) {
        if (value >= 0) attack = value;
        else cout << "Error: Attack cannot be negative!" << endl;
    }

    void setDefense(int value) {
        if (value >= 0) defense = value;
        else cout << "Error: Defense cannot be negative!" << endl;
    }

    void setDamage(int value) {
        if (value >= 0) damage = value;
        else cout << "Error: Damage cannot be negative!" << endl;
    }

    void setHealth(int value) {
        if (value >= 0) health = value;
        else cout << "Error: Health cannot be negative!" << endl;
    }

    void setSpeed(int value) {
        if (value >= 0 && value <= 20) speed = value;
        else cout << "Error: Speed must be between 0 and 20!" << endl;
    }

    void setGrowth(int value) {
        if (value >= 0) growth = value;
        else cout << "Error: Growth cannot be negative!" << endl;
    }

    void setAbility(const string& value) { ability = value; }

    void displayStats()
    {
        cout << "Attack: " << attack << endl
             << "Defense: " << defense << endl
             << "Damage: " << damage << endl
             << "Health: " << health << endl
             << "Speed: " << speed << endl
             << "Growth: " << growth << endl
             << "Ability: " << ability << endl;
    }

    void Pikeman()
    {
        setAttack(4);
        setDefense(5);
        setDamage(2);
        setHealth(10);
        setSpeed(4);
        setGrowth(28);
        setAbility("No ability");
        cout << "Pikeman" << endl;
        displayStats();
    }

    void Archers()
    {
        setAttack(6);
        setDefense(3);
        setDamage(3);
        setHealth(10);
        setSpeed(4);
        setGrowth(18);
        setAbility("can shoot");
        cout << "Archers" << endl;
        displayStats();
    }

    void Griffins()
    {
        setAttack(8);
        setDefense(8);
        setDamage(5);
        setHealth(25);
        setSpeed(6);
        setGrowth(17);
        setAbility("Can fly");
        cout << "Griffins" << endl;
        displayStats();
    }

    void Swordsmen()
    {
        setAttack(10);
        setDefense(12);
        setDamage(8);
        setHealth(35);
        setSpeed(5);
        setGrowth(8);
        setAbility("No ability");
        cout << "Swordsmen" << endl;
        displayStats();
    }

    void Monks()
    {
        setAttack(12);
        setDefense(7);
        setDamage(11);
        setHealth(30);
        setSpeed(5);
        setGrowth(6);
        setAbility("Can shoot");
        cout << "Monks" << endl;
        displayStats();
    }

    void Cavaliers()
    {
        setAttack(15);
        setDefense(15);
        setDamage(20);
        setHealth(100);
        setSpeed(7);
        setGrowth(4);
        setAbility("No ability");
        cout << "Cavaliers" << endl;
        displayStats();
    }

    void Angels()
    {
        setAttack(20);
        setDefense(20);
        setDamage(50);
        setHealth(200);
        setSpeed(12);
        setGrowth(2);
        setAbility("Can fly");
        cout << "Angels" << endl;
        displayStats();
    }
};

class UpgradeUnits : public Units
{
public:
    void Halberdier()
    {
        setAttack(6);
        setDefense(8);
        setDamage(3);
        setHealth(10);
        setSpeed(5);
        setGrowth(28);
        setAbility("No ability");
        cout << "Halberdier" << endl;
        displayStats();
    }

    void Marksman()
    {
        setAttack(8);
        setDefense(5);
        setDamage(4);
        setHealth(10);
        setSpeed(5);
        setGrowth(18);
        setAbility("Can shoot, Double shot");
        cout << "Marksman" << endl;
        displayStats();
    }

    void RoyalGriffin()
    {
        setAttack(10);
        setDefense(10);
        setDamage(6);
        setHealth(30);
        setSpeed(9);
        setGrowth(17);
        setAbility("Can fly, Unlimited retaliations");
        cout << "Royal Griffin" << endl;
        displayStats();
    }

    void Crusader()
    {
        setAttack(12);
        setDefense(12);
        setDamage(12);
        setHealth(35);
        setSpeed(6);
        setGrowth(8);
        setAbility("Attack twice");
        cout << "Crusader" << endl;
        displayStats();
    }

    void Inquisitor()
    {
        setAttack(14);
        setDefense(10);
        setDamage(13);
        setHealth(35);
        setSpeed(7);
        setGrowth(6);
        setAbility("Can shoot, No melee penalty");
        cout << "Inquisitor" << endl;
        displayStats();
    }

    void Champion()
    {
        setAttack(16);
        setDefense(16);
        setDamage(25);
        setHealth(100);
        setSpeed(9);
        setGrowth(4);
        setAbility("Jousting bonus");
        cout << "Champion" << endl;
        displayStats();
    }

    void Archangel()
    {
        setAttack(30);
        setDefense(30);
        setDamage(50);
        setHealth(250);
        setSpeed(18);
        setGrowth(2);
        setAbility("Can fly, Resurrects allies");
        cout << "Archangel" << endl;
        displayStats();
    }
};


#endif
