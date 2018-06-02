#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include "Random.h"
#include <QVector>

class Weapon: public Item {
public:
    Weapon(QString name, int type, int min, int max, float speed,
           QVector<QPair<QString, QString>> stats,
           QMap<QString, QString> info,
           QVector<QMap<QString, QString>> procs):
        Item(name, stats, info, procs) {
        this->random = new Random(min, max);
        this->weapon_type = type;
        this->min_dmg = min;
        this->max_dmg = max;
        this->weapon_speed = speed;
    }

    virtual ~Weapon() {
        delete random;
    }

    virtual int get_weapon_slot() const = 0;
    int get_weapon_type() const;
    int get_min_dmg() const;
    int get_max_dmg() const;
    int get_random_dmg() const;
    float get_base_weapon_speed() const;
    float get_wpn_dps() const;

protected:
    Random* random;
    int weapon_type;
    int min_dmg;
    int max_dmg;
    float weapon_speed;
private:
};

#endif // WEAPON_H
