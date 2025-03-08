# Name: Alexander Bordenet
# Date: 2/4/2025
# Purpose: A simple RPG-type program that is to help me work on my Python skills.
# This will be displayed to the console because I am not familiar with GUIs yet.
# This will be the file that will contain all the enums for the game.
# This will hopefully result in cleaner and more understandable code. 

from enum import Enum

class classes(Enum):
    WARRIOR = 1
    MAGE = 2

    def __str__(self):
        return str(self.name)

class enemyTypes(Enum):
    GOBLIN = 1
    SKELETON = 2
    DEMON = 3

    def __str__(self):
        return str(self.name)

class itemTypes(Enum):
    WEAPON = 1
    ARMOR = 2
    POTION = 3
    SPELL = 4
    SPECIAL = 5

    def __str__(self):
        return str(self.name)

class weaponTypes(Enum):
    SWORD = 1
    AXE = 2
    MACE = 3
    SHIELD = 4
    DAGGER = 5
    SPECIAL = 6

    def __str__(self):
        return str(self.name)
    
class armorTypes(Enum):
    LIGHT = 1
    MEDIUM = 2
    HEAVY = 3
    SPECIAL = 4

    def __str__(self):
        return str(self.name)
    
class potionTypes(Enum):
    HEAL = 1
    DOT = 2
    BUFF = 3
    SPECIAL = 4

    def __str__(self):
        return str(self.name)

class spellTypes(Enum):
    FIRE = 1
    LIGHTNING = 2
    WATER = 3
    HEAL = 4
    BUFF = 5
    SPECIAL = 6

    def __str__(self):
        return str(self.name)
    

class rarities(Enum):
    COMMON = 1
    UNCOMMON = 2
    RARE = 3
    VERY_RARE = 4
    EPIC = 5
    LEGENDARY = 6
    MYTHICAL = 7
    SPECIAL = 8

    def __str__(self):
        return str(self.name)
    
# Need to figure out how to handle special items and what they would actually do    
class specialTypes(Enum):
    SPECIAL = 1
    SUPER_SPECIAL = 2
    UNIQUE = 3

    def __str__(self):
        return str(self.name)
