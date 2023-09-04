#!/usr/bin/python3
""" Hbtn - Minimum operations: Return minimum operations to reach n """


def minOperations(n):
    """ """
    copyAll = 0
    paste = 0
    character = 1
    stock = 0

    if (n <= 0):
        return (0)

    while (character < n):
        if ((n % character) == 0):
            copyAll += 1
            stock = character
        paste += 1
        character += stock
    return (copyAll + paste)
