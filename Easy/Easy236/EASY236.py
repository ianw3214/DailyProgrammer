from random import randint

def createTetrisPattern():
    """
    (void) -> str
    the function creates a fifty piece tetris sequence using the
    random bag sequence used in original tetris games.

    >>>createTetrisPattern()
    LJOZISTTLOSZIJOSTJZILLTZISJOOJSIZLTZISOJTLIOJLTSZO

    """
    key = ["O", "I", "S", "Z", "L", "J", "T"]
    bag = key[:]
    finalString = ""
    for counter in range(50):
        currentSize = len(bag)
        if(currentSize==0):
            bag = key[:]
            currentSize = len(bag)
        thisPiece = randint(0, currentSize-1)
        finalString += bag.pop(thisPiece)
    return finalString
