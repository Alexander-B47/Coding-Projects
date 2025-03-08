# Name: Alexander Bordenet
# Date: 2/3/2025
# Purpose: A simple RPG-type program that is to help me work on my Python skills.
# This will be displayed to the console because I am not familiar with GUIs yet.
# This will be the class that will handle the saving of data.
# A file will be created to store the data for the game.
# It will be read from and written to.

from Character import Character

# SavingData Class
class SavingData:

    # Constructor
    def __init__ (self, fileName):
        self.fileName = fileName
        self.playerData = None
        self.inventory = None

    # Method to save the data
    # This function will write the data to a file
    def saveData(self):
        saveFile = open(self.fileName, "w")
        saveFile.write(str(self.playerData))
        saveFile.close()

    # Method to load the data
    # This function will read the data from a file
    def loadData(self):
        playerStats = []
        loadFile = open(self.fileName, "r")
        for line in loadFile:
            line = line.strip("\n")
            playerStats.append(line)
        loadFile.close()
        for i in range(len(playerStats)):
            tempArray = playerStats[i].split(":")
            playerStats[i] = tempArray[1]
        self.playerData = Character(playerStats[0],     # Name 
                                    int(playerStats[1]),# Health 
                                    int(playerStats[2]),# Attack
                                    int(playerStats[3]),# Defence
                                    int(playerStats[4]),# Luck
                                    int(playerStats[5]),# Speed
                                    int(playerStats[6]),# Level
                                    int(playerStats[7]))# Experience

    # Setters and Getters
    def setFileName(self, fileName):
        self.fileName = fileName
    
    def setPlayerData(self, playerData):
        self.playerData = playerData

    def setInventory(self, inventory):
        self.inventory = inventory

    def getFileName(self):
        return self.fileName
    
    def getPlayerData(self):
        return self.playerData
    
    def getInventory(self):
        return self.inventory