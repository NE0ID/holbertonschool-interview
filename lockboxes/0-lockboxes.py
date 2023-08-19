#!/usr/bin/python3
""" lockboxes - method that determines if all the boxes can be opened """


def canUnlockAll(boxes):
    unlocked = [boxes[0]]
    keys = []
    index = 1

    for box in boxes:
        for key in box:
            if key not in keys:
                keys.append(key)
    print(keys)
    while index is not len(boxes):
        for key in keys:
            if index == key:
                unlocked.append(boxes[index])
                print(unlocked)
            else:
                continue
        index += 1

    if len(unlocked) == len(boxes):
        return True
    return False
