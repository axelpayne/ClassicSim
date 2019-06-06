#pragma once

#include "TestSpellWarrior.h"

class TestBattleShout: public TestSpellWarrior {
public:
    TestBattleShout(EquipmentDb* equipment_db);

    void test_all();

private:
    BattleShout* battle_shout();

    void test_name_correct() override;
    void test_spell_cooldown() override;
    void test_stance_cooldown() override;
    void test_how_spell_observes_global_cooldown() override;
    void test_whether_spell_causes_global_cooldown() override;
    void test_resource_cost() override;
    void test_is_ready_conditions() override;

    void when_battle_shout_is_performed();
};