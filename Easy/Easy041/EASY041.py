def addBorder(sentence):
    """
    (string) -> void
    accepts a string as input and prints the string again with an ASCII art border

    >>>addBorder("hello")
    *********
    * hello *
    *********
    """
    length = len(sentence) + 4
    for i in range(length):
        print('*', end="")
    print('\n* ', end="")
    print(sentence, end="")
    print(' *\n', end="")
    for i in range(length):
        print('*', end="")
    print('')
