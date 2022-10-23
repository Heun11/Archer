import pygame, random, json
pygame.init()

load = input("load? ")
file = input("name of the file: ")
layout = []

num_to_img = []
num_to_name_img = []
size_of_square = 50

if load == "":
	width = int(input("width: "))
	height = int(input("height: "))
	num_of_layers = int(input("number of layers: "))

	for a in range(num_of_layers):
		layout.append([])
		for b in range(height):
			layout[a].append([])
			for c in range(width):
				layout[a][b].append(0)

else:
	with open(file, "r") as f:
		content = f.readlines()
		size = content[0].split()
		width = int(size[0])
		height = int(size[1])
		num_of_layers = int((len(content) - 1) / (height + 1))

		for a in range(num_of_layers):
			layout.append([])
			for b in range(height):
				layout[a].append([])
				line = content[a * (height + 1) + 2 + b].split()
				for i in line:
					layout[a][b].append(int(i))

	print("If you want to rewrite change or add any image to any layer, do it now")

	with open(file.split(".")[0] + ".json", "r") as f:
		content = json.load(f)

		for i in range(len(content)):
			num_to_name_img.append({})
			num_to_img.append({})
			for j in content[i]:
				num_to_name_img[i][int(j)] = content[i][j]
				num_to_img[i][int(j)] = pygame.transform.scale(pygame.image.load(content[i][j]), (size_of_square, size_of_square))

for i in range(num_of_layers):
	print(f"Add image with the number with form <num> <image.img> for layer {i + 1}, if you are done press ENTER")
	if load == "":
		num_to_img.append({})
		num_to_name_img.append({})
	while True:
		inp = input()
		if inp == "":
			break
		else:
			splitted_inp = inp.split()
			num_to_img[i][int(splitted_inp[0])] = pygame.transform.scale(pygame.image.load(splitted_inp[1]), (size_of_square, size_of_square))
			num_to_name_img[i][int(splitted_inp[0])] = splitted_inp[1]

win = pygame.display.set_mode((width * size_of_square + 300, height * size_of_square))

current_layer = None

selected_img = []
for i in range(num_of_layers):
	selected_img.append(0)

def save():
	with open(file, "w") as f:
		f.write(f"{width} {height}")

		for i in range(len(layout)):
			f.write("\n")
			for j in range(len(layout[i])):
				f.write("\n")
				for k in range(len(layout[i][j])):
					f.write(f"{layout[i][j][k]} ")
	json_file = file.split(".")

	with open(f"{json_file[0]}.json", "w") as f:
		json.dump(num_to_name_img, f)

def draw_window(mouse, click, keys):
	global current_layer, selected_img, layout
	win.fill((0, 0, 0))

	pygame.draw.rect(win, (10, 10, 10), pygame.Rect(100, 0, width*size_of_square, height*size_of_square))

	for i in range(num_of_layers):
		pygame.draw.rect(win, (128, 128, 128), pygame.Rect(0, i * height*size_of_square/num_of_layers, 100, height*size_of_square/num_of_layers - 1))
		if pygame.Rect.colliderect(mouse, pygame.Rect(0, i * height*size_of_square/num_of_layers, 100, height*size_of_square/num_of_layers - 1)) and click:
			current_layer = i

	pygame.draw.rect(win, (240, 240, 240), pygame.Rect(width*size_of_square - size_of_square*2 + 300, height*size_of_square - size_of_square*2, size_of_square*2, size_of_square*2))

	if pygame.Rect.colliderect(mouse, pygame.Rect(width*size_of_square - size_of_square*2 + 300, height*size_of_square - size_of_square*2, size_of_square*2, size_of_square*2)) and click:
		save()

	if current_layer != None:
		pygame.draw.rect(win, (240, 240, 240), pygame.Rect(width*size_of_square - size_of_square + 300, height*size_of_square - size_of_square*3 - 1, size_of_square, size_of_square))
		if pygame.Rect.colliderect(mouse, pygame.Rect(width*size_of_square - size_of_square + 300, height*size_of_square - size_of_square*3 - 1, size_of_square, size_of_square)) and click:
			for y in range(len(layout[current_layer])):
				for x in range(len(layout[current_layer][y])):
					layout[current_layer][y][x] = 0

		for x, i in enumerate(num_to_img[current_layer]):
			win.blit(num_to_img[current_layer][i], (width*size_of_square + 300 - size_of_square * (2 - x // height + 1), (x % height) * size_of_square))
			if pygame.Rect.colliderect(mouse, pygame.Rect(width*size_of_square + 300 - size_of_square * (2 - x // height + 1), (x % height) * size_of_square, size_of_square, size_of_square)) and click:
				selected_img[current_layer] = i

		for y in range(len(layout[current_layer])):
			for x in range(len(layout[current_layer][y])):
				if pygame.Rect.colliderect(mouse, pygame.Rect(100 + x*size_of_square, y*size_of_square, size_of_square, size_of_square)) and click:
					if selected_img[current_layer] == layout[current_layer][y][x]:
						layout[current_layer][y][x] = 0
					else:
						layout[current_layer][y][x] = selected_img[current_layer]

	for i in range(num_of_layers):
		for y in range(len(layout[i])):
			for x in range(len(layout[i][y])):
				if layout[i][y][x] != 0:
					win.blit(num_to_img[i][layout[i][y][x]], (100 + x*size_of_square, y*size_of_square))

	pygame.display.update()

def main():
	run = True 
	clock = pygame.time.Clock()
	while run:
		clock.tick(60)
		click = False
		mx, my = pygame.mouse.get_pos()
		mouse = pygame.Rect(mx, my, 1, 1)
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				run = False
			if event.type == pygame.MOUSEBUTTONDOWN:
				click = True
		keys = pygame.key.get_pressed()
		draw_window(mouse, click, keys)
	pygame.quit()
if __name__ == "__main__":
	main()
