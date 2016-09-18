def getBitStringPopulation(inputNum):
    """Takes the bitstring of a number and counts the number of 1s in the string

    @type inputNum: int
    @rtype: int

    >>>getBitstringPopulation(23)
    4

    """
    # get the bitstring representation of the number first
    currentNum = inputNum;
    bitString = "";
    while currentNum >= 1:
        if currentNum % 2 == 1:
            bitString += "1"
        else:
            bitString += "0"
        currentNum = currentNum // 2
    # The resulting bitstring is reversed but we only need the number counts so
    # it has no significant impact
    return bitString.count("1")
