def printList(n):
    """
    (int) -> void
    prints list of number and replaces numbers divisible by 3 with Fizz
    and numbers divisible by 5 with Buzz. Numbers divisible by both
    are replaced with FizzBuzz.
    >>>printList(15)
    1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz
    """
    for num in range(1,n):
        if num % 3 == 0:
            if num % 5 == 0:
                print("FizzBuzz")
            else:
                print("Fizz")
        elif num % 5 == 0:
            print("Buzz")
        else:
            print(num)

printList(20)
