def isTornNumber(input):
    """
    (int) -> bool

    The function takes an integer input and evaluates whether it is a torn number or not.
    A torn number is a 4 digit number with all different numbers that when seperated from
    ABCD to AB and CD, the square of the sum will be the same as the original number.
    ABCD -> AB & CD -> (AB+CD)^2 -> ABCD

    >>>isTornNumber(3025)
    True
    >>>isTornNumber(1234)
    False
    """
    inpStr = str(input)
    # return false if the input is not 4 digits
    if( len(inpStr) != 4):
        return False
    # return false if there are repeating digits
    if( inpStr[0]==inpStr[1] or inpStr[0]==inpStr[2] or inpStr[0]==inpStr[3] or \
        inpStr[1]==inpStr[2] or inpStr[1]==inpStr[3] or inpStr[2]==inpStr[3]):
        return False
    # seperate the input string into two parts and convert them back to integers
    num1 = int(inpStr[:2])
    num2 = int(inpStr[2:])
    sum = num1 + num2
    sum *= sum
    # Evaluate the result
    if(sum == input):
        return True
    else:
        return False

def getTornNumbers():
    """
    (void) -> list<int>

    The function goes through all 4 digit numbers and returns any torn
    numbers in a list.
    A torn number is a 4 digit number with all different numbers that when seperated from
    ABCD to AB and CD, the square of the sum will be the same as the original number.
    """
    returnList = []
    # Start the loop from the first number without repeating digits
    # End the loop at the last number without repeating digits
    for currentNum in range(1023, 9876):
        if (isTornNumber(currentNum)):
            returnList += [currentNum]
    return returnList
