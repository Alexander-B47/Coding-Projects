# Name: Alexander Bordenet
# Date: 2/7/25 - 12/15/25
# Purpose: A simple RPG-type program that is to help me work on my Python skills.
# This will be displayed to the console because I am not familiar with GUIs yet.


from Character import Character
from random import randint
from Enums import enemyTypes, rarities


class Enemy(Character):


    def __init__(self, difficulty, playerLevel, enemyType):
        
      self.ENEMY_BASE_STATS = {
            enemyTypes.GOBLIN:   {"hp": 30, "atk": 6, "def": 4, "exp": 10},
            enemyTypes.SKELETON: {"hp": 45, "atk": 8, "def": 6,  "exp": 15},
            enemyTypes.DEMON:    {"hp": 80, "atk": 12, "def": 10, "exp": 30},
            enemyTypes.DRAGON:   {"hp": 150, "atk": 20, "def": 15, "exp": 50},
            enemyTypes.OUTER_BEING: {"hp": 1000, "atk": 100, "def": 100, "exp": 1000}
      }

        
      stats = self.ENEMY_BASE_STATS[enemyType]

      if(enemyType == enemyTypes.OUTER_BEING):
            difficulty *= 3  # Outer Beings are much stronger than anything else
            self.speed = randint(20,30)
            self.luck = randint(70, 100)
      else:
            self.speed = randint(5, 15)
            self.luck = randint(1, 100)    

      hp = self.scaleStats(stats["hp"], playerLevel) * difficulty
      atk = self.scaleStats(stats["atk"], playerLevel) * difficulty
      defense = self.scaleStats(stats["def"], playerLevel) * difficulty

      self.name=f"{enemyType.name.title()}"
      self.health=int(hp)
      self.attack=int(atk)
      self.defense=int(defense)
      self.level=playerLevel
      self.experience=self.calculate_xp(playerLevel, enemyType)    
       

      super().__init__(
            name=self.name,
            health=self.health,
            attack=self.attack,
            defense=self.defense,
            luck=self.luck,
            speed=self.speed,
            level=playerLevel,
            experience=self.experience
      )

    def __str__(self):
          return super().__str__()
    
    def calculate_xp(self, level, enemyType):
        return int (20 * level * (list(enemyTypes).index(enemyType) + 1))

    # Mehod to calculate how strong each enemy is based on the player's level and enemy type
    def scaleStats(self, base, level, growth=1.15):
      return int(base * (growth ** (level - 1)) + 1)

    def generateRarity(self):
          # Only has seven of the eight rarities, still have not figured out what special will do
          # common, uncommon, rare, very rare, epic, legendary, mythical
          weights = [60, 30, 15, 7.5 , 3.25, 1.7, 0.05]
            

