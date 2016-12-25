# FRACTION SIMPLIFYING PROGRAM for Daily Programmer Challenge
# EASY #277

def simplify(inp):
    """Return the simplified fraction of the input

    Assumes <inp> is a string of the format 'int whitespace int'

    @type inp: str
    @rtype: str
    """
    numerator, denominator = tuple(inp.split())
    key = gcd(int(numerator), int(denominator))
    return str(int(numerator) // key) + " " + str(int(denominator) // key)


def gcd(a, b):
    """Return the greatest common denominator of two numbers

    @type a: int
    @type b: int
    @rtype: int
    """
    while b != 0:
        a, b = b, a % b
    return a


if __name__ == "__main__":
    assert simplify('10 20') == '1 2'
    assert simplify('1 20') == '1 20'
    assert simplify('6 9') == '2 3'
    assert simplify('13 13') == '1 1'
    assert simplify('30 6') == '5 1'
