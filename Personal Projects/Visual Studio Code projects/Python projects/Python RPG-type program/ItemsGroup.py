# Name: Alexander Bordenet
# Date: 2/6/25
# Purpose: A simple RPG-type program that is to help me work on my Python skills.
# This will be displayed to the console because I am not familiar with GUIs yet.
# This class will inherit from the Item class for the child classes: weapon, armor,potion, spell, special.
# Will use the rarity and itemType of the item class and will add __Type,
# damageType, and something else, probably.

#TODO: Determine what exactly damageType should do for each item
#TODO: Give each item its own methods like attack, drink, etc

from Item import Item
from Enums import weaponTypes, armorTypes, potionTypes, spellTypes, specialTypes , damageTypes

class Weapon(Item):

    def __init__(self, rarity, weaponType, damageType = damageTypes.PHYSICAL):
        super().__init__(rarity, 1)
        self.damageType = damageTypes(damageType)
        self.weaponType = weaponTypes(weaponType)

    def __str__(self):
        return str(super().getRarity()) + " " + str(self.getWeaponType())
    
    def getAdditionalAttributes(self):
        return self.weaponType
    
    def getDamageType(self):
        return self.damageType

    def setDamageType(self, damageType):
        self.damageType = damageTypes(damageType)
    
    def setWeaponType(self, weaponType):
        self.weaponType = weaponTypes(weaponType)
    
    def getWeaponType(self):
        return self.weaponType
    
class Armor(Item):

    def __init__(self, rarity, ArmorType, damageType = damageTypes.PHYSICAL):
        super().__init__(rarity, 2)
        self.damageType = damageTypes(damageType)
        self.armorType = armorTypes(ArmorType)

    def __str__(self):
        return str(super().getRarity()) + " " + str(self.getArmorType()) + " Armor"
    
    def getAdditionalAttributes(self):
        return self.armorType
    
    def getDamageType(self):
        return self.damageType
    
    def setDamageType(self, damageType):
        self.damageType = damageTypes(damageType)

    def setArmorType(self, armorType):
        self.armorType = armorTypes(armorType)
    
    def getArmorType(self):
        return self.armorType

class Potion(Item):
    
    def __init__(self, rarity, PotionType, damageType):
        super().__init__(rarity, 3)
        self.damageType = damageTypes(damageType) # Can be healing or magical, not physical
        self.potionType = potionTypes(PotionType)

    def __str__(self):
        return str(super().getRarity()) + " " + str(self.getPotionType()) + " Potion"
    
    def getAdditionalAttributes(self):
        return self.potionType
    
    def getDamageType(self):
        return self.damageType
    
    def setDamageType(self, damageType):
        self.damageType = damageTypes(damageType)

    def setPotionType(self, PotionType):
        self.potionType = potionTypes(PotionType)

    def getPotionType(self):
        return self.potionType

class Spell(Item):
    def __init__(self, rarity, SpellType, damageType):
        super().__init__(rarity, 4)
        self.damageType = damageTypes(damageType) # Can be healing or magical, not physical
        self.spellType = spellTypes(SpellType)

    def __str__(self):
        return str(super().getRarity()) + " " + str(self.getSpellType()) + " Spell"
    
    def getAdditionalAttributes(self):
        return self.spellType
    
    def getDamageType(self):
        return self.damageType

    def setDamageType(self, damageType):
        self.damageType = damageTypes(damageType)

    def setSpellType(self, spellType):
        self.spellType =  spellTypes(spellType)
    
    def getSpellType(self):
        return self.spellType

# TODO Figure this out later
class Special(Item):
    pass