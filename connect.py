import numpy as np
import sys
import pygame
import math

YELLOW = (255,255,0)
BLACK = (0,0,0)
RED = (255,0,0)
BLUE = (0,0,255)
PURPLE = (255,255,255)
ROW = 6
COLUMN = 7
WIDTH = 700
HIGHT = 600
SQUARE_SIZE = 100
RADIUS = 50
screen = pygame.display.set_mode((WIDTH,HIGHT))

def make_board():
    board = np.zeros((ROW,COLUMN))
    return board
board = make_board()

def check_win(board,r,c):
    for c1 in range(COLUMN):
        if c1 + 3 < COLUMN and board[r][c1] == board[r][c1+1] == board[r][c1+2] == board[r][c1+3] != 0:
            pygame.draw.line(screen,PURPLE,(c1*SQUARE_SIZE + (int)(SQUARE_SIZE/2), r*SQUARE_SIZE + (int)(SQUARE_SIZE/2)),((c1+3)*SQUARE_SIZE + (int)(SQUARE_SIZE/2), (r)*SQUARE_SIZE + (int)(SQUARE_SIZE/2)),7)            
    for r1 in range(ROW):
        if r1 + 3 < ROW and board[r1][c] == board[r1+1][c] == board[r1+2][c] == board[r1+3][c] !=0:
            pygame.draw.line(screen,PURPLE,(c*SQUARE_SIZE + (int)(SQUARE_SIZE/2), r1*SQUARE_SIZE + (int)(SQUARE_SIZE/2)),((c)*SQUARE_SIZE + (int)(SQUARE_SIZE/2), (r1+3)*SQUARE_SIZE + (int)(SQUARE_SIZE/2)),7)
    for c in range(COLUMN-3):
        for r in range(ROW-3):
            if board[r][c] == board[r+1][c+1] == board[r+2][c+2] == board[r+3][c+3]!=0:
                pygame.draw.line(screen,PURPLE,(c*SQUARE_SIZE + (int)(SQUARE_SIZE/2), r*SQUARE_SIZE + (int)(SQUARE_SIZE/2)),((c+3)*SQUARE_SIZE + (int)(SQUARE_SIZE/2), (r+3)*SQUARE_SIZE + (int)(SQUARE_SIZE/2)),7)
    for c in range(COLUMN-3 ):
        for r in range(3, ROW):
            if board[r][c] == board[r-1][c+1] == board[r-2][c+2] == board[r-3][c+3]!=0:
                pygame.draw.line(screen,PURPLE,(c*SQUARE_SIZE + (int)(SQUARE_SIZE/2), r*SQUARE_SIZE + (int)(SQUARE_SIZE/2)),((c+3)*SQUARE_SIZE + (int)(SQUARE_SIZE/2), (r-3)*SQUARE_SIZE + (int)(SQUARE_SIZE/2)),7)
    pygame.display.update()

def update_position(board,col,color):
    for r in reversed(range(ROW)):
        if board[r][col] == 0:
            if(color == RED):
                board[r][col] = 1
            else:
                board[r][col] = 2
            pygame.draw.circle(screen,color,(col*SQUARE_SIZE + (int)(SQUARE_SIZE/2), r*SQUARE_SIZE + (int)(SQUARE_SIZE/2)),RADIUS-2)
            pygame.display.update()
            check_win(board,r,col)
            break

def draw_game():
    for r in range(ROW):
        for c in range(COLUMN):
            pygame.draw.rect(screen,BLUE,(c*SQUARE_SIZE,r*SQUARE_SIZE,SQUARE_SIZE,SQUARE_SIZE))
            pygame.draw.circle(screen,BLACK,(c*SQUARE_SIZE + (int)(SQUARE_SIZE/2), r*SQUARE_SIZE + (int)(SQUARE_SIZE/2)),RADIUS-4)

draw_game()
pygame.display.update()

turn = 0
game_end = 0
while not game_end:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
        if event.type == pygame.MOUSEBUTTONDOWN:
            if(turn == 0):
                p_mouse = event.pos[0]
                col = math.floor(p_mouse/100)
                update_position(board,col,RED)
            if(turn == 1):
                p_mouse = event.pos[0]
                col = math.floor(p_mouse/100)
                update_position(board,col,YELLOW)
            turn+=1
            turn = turn%2