n = int(input())
height = boxesUsed = prevBoxes = 0

while n > boxesUsed:

    height += 1
    thisStepBoxes = prevBoxes + height
    boxesUsed += thisStepBoxes
    prevStepBoxes = thisStepBoxes

    if n < boxesUsed:
        height -= 1

print(height)