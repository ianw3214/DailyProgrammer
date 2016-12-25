#   SCRABBLE PROGRAM for Daily Programmer Challenge
#   EASY #294

points = {'?': 0, 'a': 1, 'b': 3, 'c': 3, 'd': 2, 'e': 1, 'f': 4, 'g': 2,
          'h': 4, 'i': 1, 'j': 8, 'k': 5, 'l': 1, 'm': 3, 'n': 1, 'o': 1,
          'p': 3, 'q': 10, 'r': 1, 's': 1, 't': 1, 'u': 1, 'v': 4, 'w': 4,
          'x': 8, 'y': 4, 'z': 10}

def scrabble(letters, goal):
    """Return a boolean to show if the goal word can be reached
    with input letters

    @type letters: str
    @type goal: str
    @rtype: Boolean
    """
    # Add all the letters on the rack to the dictionary
    letter_bank = {}
    for char in letters:
        if char in letter_bank:
            letter_bank[char] += 1
        else:
            letter_bank[char] = 1
    # loop through the characters in the string and determine if the goal can
    # be reached
    for char in goal:
        if char in letter_bank:
            if letter_bank[char] != 0:
                letter_bank[char] -= 1
            elif '?' in letter_bank:
                if letter_bank['?'] != 0:
                    letter_bank['?'] -= 1
                else:
                    return False
            else:
                return False
        elif '?' in letter_bank:
            if letter_bank['?'] != 0:
                letter_bank['?'] -= 1
            else:
                return False
        else:
            return False
    return True


def longest(letters):
    """Return the longest possible word from the enable1 dictionary using the
    input letters

    Returns an empty list if the letters can not make a word

    @type letters: str
    @rtype: str
    """
    # EXTRACT THE VALID WORDS FROM THE DICTIONARY
    words = []
    f = open('enable1.txt', 'r')
    for word in f:
        if scrabble(letters, word.rstrip()):
            words.append(word.rstrip())
    # IF MATCHING WORDS FOUND, RETURN THE LONGEST ONE
    if len(words) > 0:
        return max(words, key=len)
    else:
        return []


def find_score(word):
    """find the score for the word according to the score of each letter

    @type word: str
    @rtype: int
    """
    total_score = 0
    for char in word:
        total_score += points[char]
    return total_score


def find_wild(letters, word):
    """Return the word with its letters correctly replaced with wild cards

    Assumes <word> can be made with <letters>

    @type letters: str
    @type word: str
    @rtype: str
    """
    split_word = list(word)
    letters = list(letters)
    for i in range(len(split_word)):
        if split_word[i] not in letters:
            split_word[i] = '?'
        else:
            letters.remove(split_word[i])
    return ''.join(split_word)


def highest(letters):
    """Return the word with the highest possible points

    Returns an empty list if the letters can not make a word

    @type letters: str
    @rtype: str
    """
    # EXTRACT THE VALID WORDS FROM THE DICTIONARY
    words = {}
    f = open('enable1.txt', 'r')
    for word in f:
        if scrabble(letters, word.rstrip()):
            words[word] = find_score(find_wild(letters, word.rstrip()))
    # Return the key with max value
    return max(words, key=words.get).rstrip()

if __name__ == "__main__":

    # SCRABBLE TESTS
    assert scrabble("ladilmy", "daily") == True
    assert scrabble("eerriin", "eerie") == False
    assert scrabble("orrpgma", "program") == True
    assert scrabble("orppgma", "program") == False

    # SCRABBLE TESTS WITH WILD CARD
    assert scrabble("pizza??", "pizzazz") == True
    assert scrabble("piizza?", "pizzazz") == False
    assert scrabble("a??????", "program") == True
    assert scrabble("b??????", "program") == False

    # LONGEST WORD TESTS
    assert longest("dcthoyueorza") ==  "coauthored"
    assert longest("uruqrnytrois") == "turquois"
    assert longest("rryqeiaegicgeo??") == "greengrocery"
    assert longest("udosjanyuiuebr??") == "subordinately"
    assert longest("vaakojeaietg????????") == "ovolactovegetarian"

    # HIGHEST SCORE TEST
    assert highest("dcthoyueorza") ==  "zydeco"
    assert highest("uruqrnytrois") == "squinty"
    assert highest("rryqeiaegicgeo??") == "reacquiring"
    assert highest("udosjanyuiuebr??") == "jaybirds"
    assert highest("vaakojeaietg????????") == "straightjacketed"
