# Name: Alexander Bordenet
# Date: 2/7/25
# Purpose: A simple RPG-type program that is to help me work on my Python skills.
# This will be displayed to the console because I am not familiar with GUIs yet.


from Character import Character
from random import randint
from Enums import enemyTypes

class Enemy(Character):
    
    def __init__(self, strength, playerHealth, playerLevel, enemyType):
            self.enemyType = enemyTypes(enemyType)
            super().__init__("Enemy " + str(self.enemyType), # Name
                            round(playerHealth * strength),  # Health
                            round(10 * strength , 2),        # Attack
                            round(10 * strength, 2),         # Defence
                            randint(1, 100),                 # Luck
                            round(10 * strength , 2),        # Speed
                            playerLevel,                     # Level
                            50)                              # Experience 
            
            # Mods the experience to fit the enemyType
            if(self.enemyType == enemyTypes.SKELETON):
                  super().setExperience(75)
            elif(self.enemyType == enemyTypes.DEMON):
                  super().setExperience(100)
    
    def __str__(self):
          return super().__str__()
    

