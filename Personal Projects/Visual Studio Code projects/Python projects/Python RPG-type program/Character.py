# Name: Alexander Bordenet
# Date: 1/30/2025
# Purpose: A simple RPG-type program that is to help me work on my Python skills.
# This will be displayed to the console because I am not familiar with GUIs yet.
# This will be the class that will be used to create the characters in the game.

#IMPORTANT: The inventory for the character will be kept as a seperate object (Inventory)
# The reason being that I was unsure how I want to handle the inventory and character
# Whether the character should inherit Inventory(remove the mentions of Character from Inventory),
# and then call the super() for the initialization, string representation, and addItems
# Other option, the one I am using right now, just keep them seperate and have specify
# The character that the inventory is for by passing a Character object into it.
# Will allow for just importing Inventory because it keeps a copy of the Character inside of it.

# Character Class
class Character:
    
    # Constructor
    def __init__(self, name, health, attack, defense, luck, speed, level, experience):
        self.name = name
        self.health = health
        self.attack = attack
        self.defense = defense
        self.luck = luck
        self.speed = speed
        self.level = level
        self.experience = experience

    # String representation of the object
    def __str__(self):
        return "Name: " + self.name + "\
        \nHealth: " + str(self.health) + "\
        \nAttack: " + str(self.attack) + "\
        \nDefense: " + str(self.defense) + "\
        \nLuck: " + str(self.luck) + "\
        \nSpeed: " + str(self.speed) + "\
        \nLevel: " + str(self.level) + "\
        \nExperience: " + str(self.experience)
    
    # Level-up calculator
    def levelUp(self):
        pass #TODO

    # Setters and Getters
    def setName(self, name):
        self.name = name

    def setHealth(self, health):
        self.health = health

    def setAttack(self, attack):
        self.attack = attack

    def setLuck(self, luck):
        self.luck = luck

    def setSpeed(self, speed):
        self.speed = speed

    def setDefense(self, defense):
        self.defense = defense

    def setLevel(self, level):
        self.level = level

    def setExperience(self, experience):
        self.experience = experience

    def getName(self):
        return self.name

    def getHealth(self):
        return self.health

    def getAttack(self):
        return self.attack

    def getDefense(self):
        return self.defense

    def getLuck(self):
        return self.luck

    def getSpeed(self):
        return self.speed
    
    def getLevel(self):
        return self.level
    
    def getExperience(self):
        return self.experience