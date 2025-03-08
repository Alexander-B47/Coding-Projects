# Name: Alexander Bordenet
# Date: 2/11/25
# Purpose: To be blackJack

import random

def buildDeck(deck):
    for _ in range(4):
        for i in range(1, 14):
            if(i > 10):
                deck.append(10)
            else:
                deck.append(i)
    return deck

def addToHand(deck):
    i = random.randint(0,len(deck)-1)
    return deck.pop(i)

def dealCard(deck , hand):
    i = addToHand(deck)
    hand.append(i)
    return hand

def sumHand(hand):
    sum = 0
    for i in range(len(hand)):
        if(hand[i] == 1):
            if(sum+11 > 21):
                sum+=hand[i]
            else:
                sum+=11
        else:
            sum+= hand[i]
    return sum

def dealerHit(deck, dealer):
    if(sumHand(dealer) < 17):
        dealer = dealCard(deck,dealer)
    return dealer

def determineWinOrLose(player, dealer):
    pHand = sumHand(player)
    dHand = sumHand(dealer)

    if(dHand < 21 and pHand > dHand): # Player's hand is greater
        return True
    elif(dHand < 21 and pHand < dHand): # Dealer's hand is greater
        return False
    else:
        return False

def playGame():
    deck = []
    deck = buildDeck(deck)
    cont = True
    win = False
    player = []
    dealer = []
    
    while(cont):
        player = dealCard(deck, player)
        dealer = dealerHit(deck, dealer)
        print("Player's hand: " + " ".join(str(card) for card in player))
        print("dealer's hand: " + str(dealer[0]))
        print("Player's sum:  " +str(sumHand(player)) + "\n")
        #print("Dealer's sum:  " + str(sumHand(dealer))) # For debugging
        if(sumHand(dealer) > 21):
            cont = False
            win = True
            print("\nDealer Bust!")
        elif(sumHand(player) > 21):
            cont = False
            win = False
            print("\nYou Bust!")
        else:
            choice = str(input("Stay(s) or Hit(h)?: "))
            if(choice.capitalize() == "S"):
                cont = False
                win = determineWinOrLose(player, dealer)
            elif(choice.capitalize() == "H"):
                cont = True
            else:
                print("Invalid option!")
                cont = False
                win = False
            print("\n")
    
    if(win):
        print("You Win!")
        print("You had: " + str(sumHand(player)))
        print("Dealer had: " + str(sumHand(dealer)) + "\n")
    if(not win):
        print("You lost!")
        print("You had: " + str(sumHand(player)))
        print("Dealer had: " + str(sumHand(dealer)) + "\n")

def main():
    keepPlaying = True
    while(keepPlaying):
        print("\nBlackJack!\n")
        playGame()
        choice = str(input("Play again? (y/n): "))
        if(choice.capitalize() == "Y"):
            keepPlaying = True
        elif(choice.capitalize() == "N"):
            keepPlaying = False
        else:
            print("Invalid Option!")
            keepPlaying = False
main()