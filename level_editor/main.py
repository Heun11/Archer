import pygame
pygame.init()

WIDTH = 1024
HEIGHT = 640

size = [int(input("w>")), int(input("h>"))]
level = [[0 for i in range(size[0])] for j in range(size[1])]

if size[0]>size[1]:
    block_size = int(1024/size[1])
else:
    block_size = int(1024/size[0])

screen = pygame.display.set_mode((WIDTH,HEIGHT))
pygame.display.set_caption('Archer Map Editor')
clock = pygame.time.Clock()

def update():
    screen.fill((20,20,20))
    
    for i in range(size[1]):
        for j in range(size[0]):
            if level[i][j]==0:
                pygame.draw.rect(screen, (50,50,50), pygame.Rect(j*block_size,i*block_size, block_size-1,block_size-1))
            
    pygame.display.update()

running = True
while running:
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			running = False

		if event.type == pygame.KEYDOWN:
			if event.key == pygame.K_ESCAPE:
				running = False


	update()
	clock.tick(60)
	# print(clock.get_fps())