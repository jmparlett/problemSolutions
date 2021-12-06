def buildboards(f):
    movelist = [int(i) for i in f.readline().split(",")]

    boardlist = []
    line=f.readline()
    while line != '':
        
        board = []
        for i in range(5):
            board.append([int(j) for j in f.readline().split() if j.isdigit()])
        #  printboard(board)
        # dump nl and save board
        line=f.readline()
        boardlist.append(board)
    return (boardlist,movelist)

def markboard(tile, board):
    '''takes tile num to mark, and board to mark it on'''
    for i in range(len(board)): # these could be replaced with range 5 but eh
        for j in range(len(board[i])):
            if board[i][j]==tile:
                board[i][j]=-1 # -1 will be our sentinal since its not present in any board
                return # each tile will only be on a given board once so we can stop once we've found it

def checkboard(board):
    '''takes a board to check and returns true if it is a winner false other wise'''
    # there is a vert win case possible iff there is a -1 in the first row
    for i in range(len(board[0])):
        if board[0][i]==-1:
            flag=True
            for j in range(len(board)):
                if board[j][i]!=-1:
                    flag=False
                    break
            if flag==True: # we've found a winner
                return True
    
    # there is horizontal win case iff there is a -1 in the first column
    for i in range(len(board)):
        if board[i][0]==-1:
            flag=True
            for j in range(len(board[i])):
                if board[i][j]!=-1:
                    flag=False
                    break
            if flag==True: # we've found a winner
                return True
    # no winners
    return False

def findboardsum(board):
    '''finds sum of winning board, ignoring sentinals'''
    S = 0
    for i in range(len(board)):
        for j in range(len(board[i])):
                if board[i][j]!=-1:
                    S+=board[i][j]
    return S

def printboard(board):
    '''prints a board'''
    print("------------------------------")
    for i in range(len(board)):
        print(board[i])
    print("------------------------------")



def p1(f):
    boardlist,marklist= buildboards(f)

    for mark in marklist:
        #mark each board and check if its a winner
        for board in boardlist:
            markboard(mark,board)
            if checkboard(board):
                printboard(board)
                print("finalboardscore: ",findboardsum(board)*mark)
                return

def p2(f):
    ''' 
    part 2 is similar to part one except now we'll just remove a board if it is a winner until
    we only have one board left.
    '''
    boardlist,marklist= buildboards(f)


    for mark in marklist:
        #mark each board and check if its a winner
        for board in boardlist:
            markboard(mark,board)

        # check for last winner
        if len(boardlist)==1 and checkboard(boardlist[0]): # we have the last winner
            printboard(boardlist[0])
            print("current mark: ",mark)
            print("len of board list: ",len(boardlist))
            print("finalboardscore: ",findboardsum(boardlist[0])*mark)
            return
   
        # now lets remove winners
        boardlist[:] = [board for board in boardlist if not checkboard(board)]
        
        if len(boardlist)==1 and checkboard(boardlist[0]): # we have the last winner
            printboard(boardlist[0])
            print("current mark: ",mark)
            print("len of board list: ",len(boardlist))
            print("finalboardscore: ",findboardsum(boardlist[0])*mark)
            return




if __name__ == "__main__":
    
    f = open("input","r")

    #  p1(f)

    p2(f)
