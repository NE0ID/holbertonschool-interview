#!/usr/bin/python3
""" lockboxes - method that determines if all the boxes can be opened """


def canUnlockAll(boxes):
    unlocked = [boxes[0]]
    keys = []

    for box in unlocked:
        for key in box:
            if key not in keys:
                keys.append(key)

        for key in keys:
            if boxes[key] not in unlocked:
                unlocked.append(boxes[key])

    if len(unlocked) == len(boxes):
        return True
    return False
