def justify(flag, string):
    """
    (bool, str) -> void

    the function takes a boolean flag and prints the
    string justified based on what the flag points to.
    true->left
    false->right

    >>>justify(1, "hello")
    hello
    >>>justify(0, "hello")
                   hello
    """
    if(flag == 1):
        print(string.ljust(20))
    else:
        print(string.rjust(20))
