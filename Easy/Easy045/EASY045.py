def printCheckerBoard(width, height):
    """
    Print an checker patterned ASCII art board according
    to the input width and height

    @type width: int
    @type height: int
    @rtype: void

    >>>printCheckerBoard(3, 2)
    ----------
    -  -##-  -
    ----------
    -##-  -##-
    ----------

    """

    # print the first row according to width
    print("-" * (width*3+1))
    # loop through each row for the rest of the board
    for rowCounter in range(height):
        # print the first character of each row
        print('-', end="")
        if (rowCounter % 2 == 0):
            blank = False;
        else:
            blank = True;
        #loop through each column for the rest of the row
        for columnCounter in range(width):
            if blank:
                print("  -", end="")
            else:
                print("##-", end="")
            # switch the state of <blank>
            blank = not blank
        # print the filler row after printing the checkered row
        print("\n"+"-" * (width*3+1))
