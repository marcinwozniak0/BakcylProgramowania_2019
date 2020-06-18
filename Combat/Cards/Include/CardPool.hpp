 #pragma once
 #include <vector>
 #include "LimitedDeck.hpp"
 #include "Monster.hpp"
 #include "Spell.hpp"

 struct CardPool
 {
   const Monster _monsterCardPool[10] = {
    Monster(1, 1, "Goblin", 0, "Stupid goblin", 1),
    Monster(2, 8, "Spider", 0, "Spider goes brrr", 3),
    Monster(2, 1, "Hamster", 0, "What a cutie", 1),
    Monster(3, 7, "Snake", 0, "Sssssssss", 4),
    Monster(6, 6, "Dragon", 0, "Dragon - git", 6),
    Monster(9, 9, "Mountain Giant", 0, "BIG BOI", 9),
    Monster(3, 0, "Sheep", 0, "Beep beep", 1),
    Monster(4, 1, "Orc", 0, "heh", 2),
    Monster(4, 5, "Arcanist", 0, "Worth stats for cost", 4),
    Monster(25, 20, "Duck", 0, "The ULTIMATE unit", 10)};

    const Spell _SpellCardPool[5] = {
     Spell(-2, "Fire slap", 0, "Slap your enemy for only 1 mana", 1),
     Spell(-4, "Firebolt", 0, "pew pew", 2),
     Spell(-8, "Fireball", 0, "Chufff", 6),
     Spell(2, "Light touch", 0, "BAD TOUCH,BAD TOUCH", 1),
     Spell(6, "Big heal", 0, "You feel warm on your skin", 3) };
 };
