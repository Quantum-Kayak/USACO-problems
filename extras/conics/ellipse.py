import pygame
pygame.init()

screen = pygame.display.set_mode((400, 300))

background = (255, 255, 255)
color = (170, 191, 255)

cx, cy = 200, 150
a, b = 100, 50  # radii

running = True
while running:
    screen.fill(background)

    for x in range(cx - a, cx + a):
        for y in range(cy - b, cy + b):
            # Normalize to ellipse equation
            dx = (x - cx) / a
            dy = (y - cy) / b
            if dx**2 + dy**2 <= 1:
                screen.set_at((x, y), color)

    pygame.display.flip()

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

pygame.quit()
