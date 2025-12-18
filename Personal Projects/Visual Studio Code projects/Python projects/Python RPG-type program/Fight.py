#Name: Alexander Bordenet
# Date 2/10/25 - 12/15/25
# Purpose: 

# This class with act as a driver class that will handle the fighting between enemies (Turn-based?)

import math
from random import randint
from Stage import Stage
from Inventory import Inventory
from Character import Character
from Enemy import Enemy

class StageFight():
    
    def __init__(self, stage: Stage, playerInventory: Inventory):
        self.stage = stage
        self.playerInventory = playerInventory

    ##TODO: Make this involve luck, speed, crits, misses, etc.
    # TODO: Refine evasion mechanics, make it so there is variance based on speed difference, incorporate blitz tiers of speed and stuff
    def calculate_damage(self, attacker, defender):
        
        scale = 200 + randint(-10,10)  # Adding some randomness to the scale for variability

        # If the defender's speed is more than double the attacker's speed, they evade the attack
        if(attacker.getSpeed() < defender.getSpeed() / 2): 
            #print(f"{defender.getName()} evades the attack due to high speed!")
            return 0
        
        base = attacker.getAttack() * math.exp(-(defender.getDefense()) / scale)
        variance = randint(-2, 4)
        
        return round(max(5, (base + variance)),0)

    def experienceGained(self, player , experience):
        player.setExperience(player.getExperience() + experience)
        player.levelUp()

    def stageFight(self):
        numEnemies = len(self.stage.enemies)
        for i in range(numEnemies):
            print(f"\n--- Fighting Enemy {i+1} of {numEnemies} ---")
            self.fight(i)

    ##TODO: Add speed mechanic to determine who goes first, how many attacks per turn, etc.
        ##TODO: Add inventory usage (potions, etc.)
        ##TODO: make this a loop to fight all enemies in the stage
        ##TODO: Make this more modular and cleaner
        ##TODO: Add more use for weapons and armor and their types and effects on the combat.
    def fight(self, numEnemy):
        player = self.playerInventory.getCharacter()
        enemy = self.stage.enemies[numEnemy]
        turnCount = 1
        startingHealth = player.getHealth()

        print(f"A {enemy.getName()} appears!")
        print(str(enemy) + "\n")
        if(self.stage.stageName == "Incomprehensible Cosmos"):
            print("You feel the world bending around you... The enemy is beyond comprehension!")
            print("You feel yourself weakening as you face this cosmic horror. (-50% attack and defense)")

        
        while player.getHealth() > 0 and enemy.getHealth() > 0:
            
            
            # Player turn
            playerDmg = self.calculate_damage(player, enemy)
            enemy.setHealth(enemy.getHealth() - playerDmg)

            # Enemy turn
            enemyDmg = self.calculate_damage(enemy, player)
            player.setHealth(player.getHealth() - enemyDmg)

            
            if(turnCount % 10 == 11):
                print(f"\n-- Turn {turnCount} --")
                print(f"You deal {playerDmg} damage. {enemy.getName()} has {enemy.getHealth()} health remaining.")
                print(f"The enemy hits you for {enemyDmg}. You have {player.getHealth()} health remaining.")

            # Enemy defeated
            if enemy.getHealth() <= 0:
                print("Enemy defeated!")
                self.experienceGained( player , enemy.experience)
                print(f"You gained {enemy.experience} experience points.\nYour current experience is now {player.getExperience()}.\n")
            
            # Player defeated
            if player.getHealth() <= 0:
                print("You have been defeated...")
            
            turnCount += 1
        
        print(f"Fight over. It took {turnCount} turns. ")
        print(f"You started with {startingHealth} health and ended with {player.getHealth()} health.")

        