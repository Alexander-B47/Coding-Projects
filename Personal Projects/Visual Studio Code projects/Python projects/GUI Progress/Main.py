# Name: Alexander Bordenet
# Date: 2/19/25
# Purpose: To work on my understanding of GUIs in Python.

from tkinter import * # GUI Class

def main():
    root = Tk() # Makes Window, I think
    
    root.title("GUI Example!")

    #label = Label(root, text="Testing Label For GUI!!!") # Makes a Label in the Root(window)
    #label.pack() # I am unsure what this one does
    
    Label(root, text="First Name").grid(row=0)
    Label(root, text="Last Name").grid(row=1)

    e1 = Entry(root)
    e2 = Entry(root)
    e1.grid(row=0, column=1)
    e2.grid(row=1, column=1)


    button = Button(root, text="Press Me!", width=25, command=root.destroy).grid(row=2, column=0) # Makes a button in the Root(window)
                                                                            # Will Destroy(close) the window when pressed
    #button.pack() # I guess this means you "pack" it into the window?

    root.mainloop() # Keeps Window open, I think
    


main()