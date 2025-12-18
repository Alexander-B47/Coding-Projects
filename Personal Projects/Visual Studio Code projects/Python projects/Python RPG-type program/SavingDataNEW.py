# Name: Alexander Bordenet
# Date: 2/7/25
# Purpose: A simple RPG-type program that is to help me work on my Python skills.
# This will be displayed to the console because I am not familiar with GUIs yet.
# This is a new way to save my character's data because I did not want
# to try and change my SavingData class to work with the inventory

#NOTE: This version of SavingData should create a .json file because after research
#NOTE: And talking with ChatGPT (Does not write the code for me) it seems like a better
#NOTE: way to save the data than using a .txt file as a string


import json
from Character import Character
from Item import Item
from Enums import damageTypes, itemTypes, rarities, weaponTypes, armorTypes, potionTypes, spellTypes
from ItemsGroup import Weapon, Armor, Spell, Potion
from Inventory import Inventory

class SavingData:
    def __init__(self, fileName):
        self.fileName = fileName
        self.playerData = None
        self.Inventory = None

    #Saves player data, including inventory, to a JSON file.
    def saveData(self):
        
        data = {
            "name": self.playerData.name,
            "health": self.playerData.getHealth(),
            "attack": self.playerData.getAttack(),
            "defense": self.playerData.getDefense(),
            "luck": self.playerData.getLuck(),
            "speed": self.playerData.getSpeed(),
            "level": self.playerData.getLevel(),
            "experience": self.playerData.getExperience(),
            "inventory": [
                {
                    # Save the enums(rarity,itemType,item-specific type, and damageType) as strings
                    "rarity": item.getRarity().name,
                    "itemType": item.getItemType().name,  
                    "subType": item.getAdditionalAttributes().name,
                    "damageType": item.getDamageType().name
                }
                for item in self.Inventory.getInventory()
            ]
        }

        with open(self.fileName, "w") as file:
            json.dump(data, file, indent=4)  # Pretty print for readability

    #Loads player data and inventory from a JSON file.
    def loadData(self):
        
        with open(self.fileName, "r") as file:
            data = json.load(file)

        # Create Player Object
        self.playerData = Character(data["name"], data["health"], data["attack"], 
                                    data["defense"], data["luck"], data["speed"], 
                                    data["level"], data["experience"])

        # Create Inventory Object using the loaded player
        self.setInventory(Inventory(self.playerData))

        # Load Inventory
        for item_data in data["inventory"]:
            # Convert string back to Enum
            itemType = itemTypes[item_data["itemType"]]  
            rarity = rarities[item_data["rarity"]]
            if(itemType == itemTypes.WEAPON):
                subType = weaponTypes[item_data["subType"]]
                damageType = damageTypes[item_data["damageType"]]
                item = Weapon(rarity, subType, damageType )
            elif(itemType == itemTypes.ARMOR):
                subType = armorTypes[item_data["subType"]]
                damageType = damageTypes[item_data["damageType"]]
                item = Armor(rarity, subType, damageType)
            elif(itemType == itemType.POTION):
                subType = potionTypes[item_data["subType"]]
                damageType = damageTypes[item_data["damageType"]]
                item = Potion(rarity, subType, damageType)
            elif(itemType == itemType.SPELL):
                subType = spellTypes[item_data["subType"]]
                damageType = damageTypes[item_data["damageType"]]
                item = Spell(rarity, subType, damageType)
            else:
                item = Item(rarity, itemType)
            self.Inventory.addItem(item)
            

    def setPlayer(self, character):
        self.playerData = character

    def setInventory(self, inventory):
        self.Inventory = inventory

    def getPlayer(self):
        return self.playerData
    
    def getInventory(self):
        return self.Inventory
