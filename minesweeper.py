import random
def print_board(board):
    for row in board:
        print " ".join(row)

def print_result(board):
    for i in range(nummine):
      board[ship_rowlist[i]][ship_collist[i]]="*"
    print_board(board)

def random_rowlist(board):
    return random.sample(xrange(0, len(board) - 1), nummine)

def random_collist(board):
    return random.sample(xrange(0, len(board) - 1), nummine)
        
board = []

size=int(raw_input("What' the size of the grid?(Input an integer)"))
for x in range(size):
    board.append(["O"] * size)

nummine=size/3   
print "Let's play MineSweeper!"
print_board(board)
ship_rowlist = random_rowlist(board)
ship_collist = random_collist(board)
turn=0
while turn<size/2:
    print "Turn %d"%(turn+1)
    guess_row = int(raw_input("Guess Row:"))
    guess_col = int(raw_input("Guess Col:"))

    if guess_row in ship_rowlist and guess_col in ship_collist:
        print "You won!"
        break
    else:
        if (guess_row < 0 or guess_row > size-1) or (guess_col < 0 or guess_col > size-1):
            print "Out of bounds"
        elif(board[guess_row][guess_col] == "X"):
            print "You guessed that one already."
        else:
            board[guess_row][guess_col] = "X"
            turn=turn+1
    print_board(board)
print "Game Over"
print_result(board)