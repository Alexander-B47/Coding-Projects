# Name: Alexander Bordenet
# Date: 2/11/25 - 5/22/25
# Purpose: To be blackJack
# Update: Is now a working blackJack class, so it can be used in other projects.

# TODO: Could make changes to the game logic to allow for it to pass the results of the game to another class.

import random
class BlackJack:
    
    
    def __init__(self):
        pass

    def buildDeck(self, deck):
        for _ in range(4):
            for i in range(1, 14):
                if(i > 10):
                    deck.append(10)
                else:
                    deck.append(i)
        return deck

    def addToHand(self, deck):
        i = random.randint(0,len(deck)-1)
        return deck.pop(i)

    def dealCard(self, deck , hand):
        i = self.addToHand(deck)
        hand.append(i)
        return hand

    def sumHand(self, hand):
        sum = 0
        for i in range(len(hand)):
            if(hand[i] == 1): # Check whether the current ace should be treated as a 1 or 11.
                if(sum+11 > 21):
                    sum+=hand[i]
                else:
                    sum+=11
            else: # Not an ace, so you can just add it to the sum
                sum+= hand[i]
        return sum

    def dealerHit(self, deck, dealer): # Dealer will hit until 17 or greater (usual is 16, but I like 17 more.)
        if(self.sumHand(dealer) < 17):
            dealer = self.dealCard(deck,dealer)
        return dealer

    def determineWinOrLose(self, player, dealer):
        pHand = self.sumHand(player)
        dHand = self.sumHand(dealer)

        if(dHand < 21 and pHand > dHand): # Player's hand is greater
            return True
        elif(dHand < 21 and pHand < dHand): # Dealer's hand is greater
            return False
        else:
            return False

    def playGame(self):
        deck = []
        deck = self.buildDeck(deck)
        cont = True # continue
        win = False # win/lose determinate
        player = [] # player hand
        dealer = [] # dealer hand
        
        while(cont):
            player = self.dealCard(deck, player)
            dealer = self.dealerHit(deck, dealer)
            print("Player's hand: " + " ".join(str(card) for card in player))
            print("dealer's hand: " + str(dealer[0]))
            #print("Player's sum:  " +str(sumHand(player)) + "\n") # For debugging
            #print("Dealer's sum:  " + str(sumHand(dealer))) # For debugging
            
            if(self.sumHand(dealer) > 21): # Dealer busts
                cont = False
                win = True
                print("\nDealer Bust!")
            elif(self.sumHand(player) > 21): # Player busts
                cont = False
                win = False
                print("\nYou Bust!")
            else: # Neither occured
                choice = str(input("Stay(s) or Hit(h)?: "))
                if(choice.capitalize() == "S"):
                    cont = False
                    win = self.determineWinOrLose(player, dealer)
                elif(choice.capitalize() == "H"):
                    cont = True
                else:
                    print("Invalid option!")
                    cont = False
                    win = False
                print("\n")
        
        if(win):
            print("You Win!")
            print("You had: " + str(self.sumHand(player)))
            print("Dealer had: " + str(self.sumHand(dealer)) + "\n")
        if(not win):
            print("You lost!")
            print("You had: " + str(self.sumHand(player)))
            print("Dealer had: " + str(self.sumHand(dealer)) + "\n")


def main():
    currentGame = BlackJack()
    keepPlaying = True
    while(keepPlaying):
        print("\nBlackJack!\n")
        currentGame.playGame()
        choice = str(input("Play again? (y/n): "))
        if(choice.capitalize() == "Y"):
            keepPlaying = True
        elif(choice.capitalize() == "N"):
            keepPlaying = False
        else:
            print("Invalid Option!")
            keepPlaying = False

main()