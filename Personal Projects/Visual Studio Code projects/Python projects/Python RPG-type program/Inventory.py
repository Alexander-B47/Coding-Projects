# Name: Alexander Bordenet
# Date: 2/5/2025
# Purpose: A simple RPG-type program that is to help me work on my Python skills.
# This will be displayed to the console because I am not familiar with GUIs yet.
# This will be the class that will handle the inventory of the character.
# It will use enums to help with the organization of the items.

#TODO: Create an Item class that will handle making the items for the inventory.
#TODO: Create a method to add an item to the inventory(list of item objects).

import Enums
from Character import Character
from Item import Item

# Inventory Class
class Inventory:
    
    # Constructor
    def __init__(self, character):
        self.character = character
        self.inventory = []

    # String representation of the object
    # Note: learn why this line of code works (based off something I saw online, the .join part)
    def __str__(self):
        return "Inventory:\n" + "\n".join(str(item) for item in self.inventory)
    
    # Needs to be figured out once I have successfully made a item class (including the inheritance part) DONE
    # Uses polymorphism to create an array(list?) of Item objects
    def addItem(self, item):
        self.inventory.append(item)

    def removeItems(self):
        self.inventory.clear()

    # Setters and Getters
    def setCharacter(self, character):
        self.character = character

    def setInventory(self, inventory):
        self.inventory = inventory

    def getCharacter(self):
        return self.character
    
    def getInventory(self):
        return self.inventory