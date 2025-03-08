# Name: Alexander Bordenet
# Date: 1/29/2025
# Purpose: A simple RPG-type program that is to help me work on my Python skills.
# This will be displayed to the console because I am not familiar with GUIs yet.
# This will be the main file which should be run to start the game.

from Character import Character
from Stage import Stage
from SavingDataNEW import SavingData
from Item import Item
from Enums import rarities, weaponTypes, armorTypes, potionTypes, spellTypes, itemTypes
from ItemsGroup import Weapon, Armor, Potion, Spell
from Inventory import Inventory

def stageTest(character):
    stage1 = Stage(10, character)
    print(str(stage1) + "\n")
    stage1.displayEnemies()

def inventoryTest(character):
    item = Weapon(rarities.RARE, weaponTypes.SWORD)
    item2 = Armor(rarities.RARE, armorTypes.HEAVY)
    item3 = Potion(rarities.SPECIAL, potionTypes.DOT)
    item4 = Spell(rarities.RARE, spellTypes.HEAL)

    inv = Inventory(character)
    inv.addItem(item)
    inv.addItem(item2)
    inv.addItem(item3)
    inv.addItem(item4)

    print(str(inv))

def saveTest(character, inv):
    saveData = SavingData("saveFile.json")
    saveData.setPlayer(character)
    saveData.setInventory(inv)

    saveData.saveData()

    # To clear the items so there isn't any duplicates
    inv.removeItems()

    saveData.loadData()

    character2 = saveData.getPlayer()
    inv2 = saveData.getInventory()

    print(character2)
    print(inv2)

# Character class note: the parameters are as follows:
# name , health , attack , defense , luck , speed , level , experience
def main():
    character = Character("Alex" , 100, 10, 5, 100, 1000, 1 , 0)
    inv = Inventory(character)
    i = Spell(rarities.UNCOMMON, spellTypes.FIRE)
    i2 = Weapon(rarities.MYTHICAL, weaponTypes.DAGGER)
    inv.addItem(i)
    inv.addItem(i2)
    #inventoryTest(character) 
    saveTest(character, inv)   
    
main()