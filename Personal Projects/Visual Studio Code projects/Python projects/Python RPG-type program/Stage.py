# Name: Alexander Bordenet
# Date: 2/2/2025 - 12/15/25
# Purpose: A simple RPG-type program that is to help me work on my Python skills.
# This will be displayed to the console because I am not familiar with GUIs yet.
# This will be the class that will be used to create the stages in the game.

# I should learn inheritance and if Python has lambda functions.
# Each stage can be inherited from this stage class.
# Lambda functions can be used for something. I am not sure what yet.

from Character import Character
import random
from Enums import enemyTypes
from Enemy import Enemy

# Stage Class
class Stage:

    STAGE_NAMES = ["Fleeting Forest",
                   "Incomprehensible Cosmos",
                   "Creepy Crypts",
                   "Demon's Domain",
                   "Dragon Den",
                   "Terrifying Tower"]
    
    ENEMY_CHOICES = [enemyTypes.GOBLIN, enemyTypes.SKELETON, enemyTypes.DEMON, enemyTypes.DRAGON, enemyTypes.OUTER_BEING]

    # Constructor
    def __init__ (self, numberOfEnemies, playerCharacter):
        self.numberOfEnemies = numberOfEnemies
        self.playerCharacter = playerCharacter
        self.stageName = self.STAGE_NAMES[random.randint(0,5)]
        


        # The strength of the enemies will be based on the player's level 
        # It will be used as a scale factor
        self.enemyStrength =  random.uniform(0.5, 0.8) + (self.playerCharacter.getLevel() / 10) 
        
        if(self.stageName == "Incomprehensible Cosmos"):
            self.enemyStrength *= 1.5  # Cosmic stages have stronger enemies
            self.enemies = self.createEnemies(specialStage=1)
        else:
            self.enemies = self.createEnemies()
    
    # String representation of the object
    def __str__ (self):
        return f"\nStage name: {self.stageName}" + "\
        \nNumber of Enemies: " + str(self.numberOfEnemies)

    # Method to display the enemies
    # This will be used to show the player the enemies they will be facing
    def displayEnemies(self): 
        for i in range(len(self.enemies)):
            print(str(self.enemies[i]) + "\n")
    
    # Method to calculate the difficulty of each enemy
    # Adds variety to the enemies the player will face by using a random number to act as a multiplier
    def calcDifficulty(self):
        return random.uniform(0.001, 2.5) * (self.enemyStrength) 

    # Method to create enemies that are stored in a list
    # New python feature learned: weights, randomchoices
    def createEnemies(self, specialStage=0):
        enemies = []
    
        # Define the enemy types and their corresponding weights
        #goblin, skeleton, demon, dragon, outer being

        if(specialStage == 1):
            weights = [0, 0, 0, 0, 100] # Equal weights for all enemy types in special stage
        else:
            weights = [50, 30, 16.5, 3.49, 0.01] # Weights must sum to 100
    
        for i in range(self.numberOfEnemies):
            curEnemyStrength = self.calcDifficulty()
        
            # Use random.choices() to select an enemy type based on weights
            typeOfEnemy = random.choices(Stage.ENEMY_CHOICES, weights=weights, k=1)[0]

            # Create the enemy
            enemies.append(Enemy(
                curEnemyStrength,
                self.playerCharacter.getLevel(), 
                typeOfEnemy
            ))

        return enemies
    
    # Setters and Getters
    def setNumberOfEnemies(self, numberOfEnemies):
        self.numberOfEnemies = numberOfEnemies

    def getNumberOfEnemies(self):
        return self.numberOfEnemies

    def setEnemyStrength(self, enemyStrength):
        self.enemyStrength = enemyStrength

    def getEnemyStrength(self):
        return self.enemyStrength    
    
    # None for playerCharacter because it is not needed
    
