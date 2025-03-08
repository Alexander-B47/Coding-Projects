# Name: Alexander Bordenet
# Date: 2/6/25
# Purpose: A simple RPG-type program that is to help me work on my Python skills.
# This will be displayed to the console because I am not familiar with GUIs yet.
# This will be the file that will contain the parent top level class for items.
# It will all be pass as the method body because it will be filled in after the 
# class has been inherited from. 

from Enums import rarities, itemTypes

# Damage should be used for how much damage it will either: heal the player, damage the enemy, or protect the player

class Item:

    def __init__(self, rarity, itemType):
        self.rarity = rarities(rarity)
        self.itemType = itemTypes(itemType)
    
    def __str__(self):
        return str(self.rarity) + " " + str(self.getItemType())
    
    def getAdditionalAttributes(Self):
        return {}

    def setItemType(self, itemType):
        self.itemType = itemType

    def setRarity(self, rarity):
        self.rarity = rarities(rarity)

    def getItemType(self):
        return self.itemType

    def getRarity(self):
        return self.rarity

