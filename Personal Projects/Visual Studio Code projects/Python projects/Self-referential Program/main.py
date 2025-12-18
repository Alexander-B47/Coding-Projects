def main():
    i = 0
    
    saveFile = open("selfReferential" + str(i) + ".py", "w")
    saveFile.write("def main():\n")
    saveFile.write(" print(\"Hello, World!\")\n")
    saveFile.write("main()\n")
    saveFile.close()

main()
                   
