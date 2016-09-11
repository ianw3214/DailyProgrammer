numbers = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
tens = ["ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"]
teens = ["eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]

def printSong():
    """
    () -> void
    function that prints the bottles of beer song

    >>>printSong():
    Ninety-nine bottles of beer
    Ninety-eight bottles of beer
    Ninety-seven bottles of beer
    ....

    """
    for i in reversed(range(1,100)):
        if(i % 10 == 0):
            key = i//10
            print(tens[key-1] + " bottles of beer")
        elif(i > 20):
            doubleKey = i//10
            singleKey = i % 10
            print(tens[doubleKey-1] + "-" + numbers[singleKey-1] + " bottles of beer")
        elif(i<20 and i>10):
            key = i % 10
            print(teens[key-1] + " bottles of beer")
        elif(i>1):
            print(numbers[i-1] + " bottles of beer")
        else:
            print("one bottle of beer")
