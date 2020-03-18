#2018/11/30
#综合楼B开始着手进行大作业

import pygame
import sys
import os

pygame.init()

size=640,480

screen = pygame.display.set_mode(size)

pygame.display.flip()

for event in pygame.event.get():
    if event.type == pygame.QUIT:
        sys.exit()

print()
print(os.getcwd())
bat = pygame.image.load("bat.png").convert()

screen.blit(bat,batrect)