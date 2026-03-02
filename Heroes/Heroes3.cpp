#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "military_buildings_simple.h"

using namespace std;

string lower_str(string s)
{
    transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return (char)tolower(c); });
    return s;
}

void help()
{
    cout << "Commands:\n";
    cout << "  help                 - show commands\n";
    cout << "  list                 - show available buildings\n";
    cout << "  cost <name>          - show building cost\n";
    cout << "  ability <name>       - show building ability\n";
    cout << "  exit                 - quit\n\n";

    cout << "Example:\n";
    cout << "  cost guardhouse\n";
    cout << "  ability griffinbastion\n\n";
}

void list_buildings()
{
    cout << "Available Castle military buildings:\n";
    cout << "  guardhouse / guardhouseup\n";
    cout << "  archertower / archertowerup\n";
    cout << "  griffintower / griffintowerup\n";
    cout << "  griffinbastion\n";
    cout << "  barracks / barracksup\n";
    cout << "  monastery / monasteryup\n";
    cout << "  traininggrounds / traininggroundsup\n";
    cout << "  portalofglory / portalofgloryup\n\n";
}

template <class T>
void print_cost()
{
    T b;
    cout << "Gold: " << b.get_gold()
        << " | Stone(ore): " << b.get_stone()
        << " | Wood: " << b.get_wood() << endl;
}

template <class T>
void print_ability()
{
    T b;
    b.ability();
}

bool handle_cost(const string& name)
{
    if (name == "guardhouse") return print_cost<Guardhouse>(), true;
    if (name == "guardhouseup") return print_cost<GuardhouseUp>(), true;

    if (name == "archertower") return print_cost<ArcherTower>(), true;
    if (name == "archertowerup") return print_cost<ArcherTowerUp>(), true;

    if (name == "griffintower") return print_cost<GriffinTower>(), true;
    if (name == "griffintowerup") return print_cost<GriffinTowerUp>(), true;
    if (name == "griffinbastion") return print_cost<GriffinBastion>(), true;

    if (name == "barracks") return print_cost<Barracks>(), true;
    if (name == "barracksup") return print_cost<BarracksUp>(), true;

    if (name == "monastery") return print_cost<Monastery>(), true;
    if (name == "monasteryup") return print_cost<MonasteryUp>(), true;

    if (name == "traininggrounds") return print_cost<TrainingGrounds>(), true;
    if (name == "traininggroundsup") return print_cost<TrainingGroundsUp>(), true;

    if (name == "portalofglory") return print_cost<PortalOfGlory>(), true;
    if (name == "portalofgloryup") return print_cost<PortalOfGloryUp>(), true;

    return false;
}

bool handle_ability(const string& name)
{
    if (name == "guardhouse") return print_ability<Guardhouse>(), true;
    if (name == "guardhouseup") return print_ability<GuardhouseUp>(), true;

    if (name == "archertower") return print_ability<ArcherTower>(), true;
    if (name == "archertowerup") return print_ability<ArcherTowerUp>(), true;

    if (name == "griffintower") return print_ability<GriffinTower>(), true;
    if (name == "griffintowerup") return print_ability<GriffinTowerUp>(), true;
    if (name == "griffinbastion") return print_ability<GriffinBastion>(), true;

    if (name == "barracks") return print_ability<Barracks>(), true;
    if (name == "barracksup") return print_ability<BarracksUp>(), true;

    if (name == "monastery") return print_ability<Monastery>(), true;
    if (name == "monasteryup") return print_ability<MonasteryUp>(), true;

    if (name == "traininggrounds") return print_ability<TrainingGrounds>(), true;
    if (name == "traininggroundsup") return print_ability<TrainingGroundsUp>(), true;

    if (name == "portalofglory") return print_ability<PortalOfGlory>(), true;
    if (name == "portalofgloryup") return print_ability<PortalOfGloryUp>(), true;

    return false;
}

int main()
{
    cout << "Heroes 3 - Castle military buildings\n";
    cout << "Type 'help' to see commands.\n\n";

    string line;
    while (true)
    {
        cout << "> ";
        getline(cin, line);

        string cmd, arg;
        stringstream ss(line);
        ss >> cmd >> arg;

        cmd = lower_str(cmd);
        arg = lower_str(arg);

        if (cmd == "help") help();
        else if (cmd == "list") list_buildings();
        else if (cmd == "cost") {
            if (arg.empty()) { cout << "Usage: cost <name>\n"; continue; }
            if (!handle_cost(arg)) cout << "Unknown building. Type 'list'.\n";
        }
        else if (cmd == "ability") {
            if (arg.empty()) { cout << "Usage: ability <name>\n"; continue; }
            if (!handle_ability(arg)) cout << "Unknown building. Type 'list'.\n";
        }
        else if (cmd == "exit") break;
        else if (!cmd.empty()) cout << "Unknown command. Type 'help'.\n";
    }

    return 0;
}