#!/usr/bin/python3
""" lockboxes - method that determines if all the boxes can be opened """


def canUnlockAll(boxes):
    unlocked = [boxes[0]]
    keys = []

    """for box in boxes:"""

    for box in unlocked:
        for key in box:
            if key not in keys:
                if key <= len(boxes):
                    keys.append(key)
        print(keys)
        for key in keys:
            if boxes[key] not in unlocked:
                unlocked.append(boxes[key])

    if len(unlocked) == len(boxes):
        return True
    return False
