import random

COLORS = ["WHITE", "RED", "YELLOW", "GREEN", "BLUE"]

def give_random_sequence():
    computerColors = []
    for n in range(4):
        computerColors.append(random.choice(COLORS))
    return computerColors

def match_sequence(userSequence):
    computerSequence = give_random_sequence()
    for i in range(4):
        if userColors[i] == computerColors[i]:
            pegs_in_right_position += 1
        elif userColors[i] in computerColors:
            pegs_misplaced += 1

computer_sequence = give_random_sequence()
def start_game():
    for n in range(10):
        userColors = []
        for n in range(4):
            userColors.append(input().upper())
        match_sequence(userColors)
