import random

numbertoname={0:"rock",1:"Paper",2:"Scissors"}
nametonumber={"rock":0,"Paper":1,"Scissors":2}
def rpsls(name):
        player_number = nametonumber[name]
        comp_number = random.randrange(0, 3)
   
        print "Player chooses", name
        print "Computer chooses", numbertoname[comp_number]
   
        if (comp_number + 1) % 3 == player_number:
            print "Player wins!"
        elif (comp_number + 2) % 3== player_number:
            print "Player wins!"
        elif comp_number == player_number:
            print "Player and computer tie!"
        else:
            print "Computer wins!"
        print ""    

rpsls("rock")    