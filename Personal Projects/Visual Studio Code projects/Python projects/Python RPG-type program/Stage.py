# Name: Alexander Bordenet
# Date: 2/2/2025
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

    # Constructor
    def __init__ (self, numberOfEnemies,playerCharacter):
        self.numberOfEnemies = numberOfEnemies
        self.playerCharacter = playerCharacter
        
        # The strength of the enemies will be based on the player's level 
        # It will be used as a scale factor
        self.enemyStrength =  random.uniform(0.5, 0.8) + (self.playerCharacter.getLevel() / 10) 
        self.enemies = self.createEnemies()
    
    # String representation of the object
    def __str__ (self):
        return "\nStage name: _PLACEHOLDER_" + "\
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
    def createEnemies(self):
        enemies = []
    
        # Define the enemy types and their corresponding weights
        enemy_choices = [enemyTypes.GOBLIN, enemyTypes.SKELETON, enemyTypes.DEMON]
        weights = [3, 2, 1]  # Goblins appear 3 times as often, Skeletons 2 times, Demons 1 time
    
        for i in range(self.numberOfEnemies):
            curEnemyStrength = self.calcDifficulty()
        
            # Use random.choices() to select an enemy type based on weights
            typeOfEnemy = random.choices(enemy_choices, weights=weights, k=1)[0]

            # Create the enemy
            enemies.append(Enemy(
                curEnemyStrength, 
                self.playerCharacter.getHealth(), 
                self.playerCharacter.getLevel(), 
                typeOfEnemy
            ))

        return enemies
    
    # Setters and Getters
    def setNumberOfEnemies(self, numberOfEnemies):
        self.numberOfEnemies = numberOfEnemies

    def getNumberOfEnemies(self):
        return self.numberOfEnemies
    
    # None for playerCharacter because it is not needed
    
