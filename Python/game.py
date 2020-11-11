import numpy as np
from matplotlib import pyplot as plt
import matplotlib.animation as manimation
def life(grid, generations):
    def roll_matrix(x, y):
        return np.roll(np.roll(grid, y, axis = 0), x, axis = 1)
    for _ in range(generations):
        neighbours = roll_matrix(1, 0) + roll_matrix(0, 1) + roll_matrix(-1, 0) \
            + roll_matrix(0, -1) + roll_matrix(1, 1) + roll_matrix(-1, -1) \
            + roll_matrix(1, -1) + roll_matrix(-1, 1)
        grid = np.logical_or(np.logical_and(grid, neighbours == 2), neighbours == 3)
        grid = grid.astype(int)
        yield grid

grid = np.zeros((40, 40))

# R-pentomino
grid[3, 2:4] = 1
grid[4, 1:3] = 1
grid[5, 2] = 1

for x in life(grid, 40):
    print("\n", x)

FFMpegWriter = manimation.writers['ffmpeg']
data = dict(title='Game of life')
writer = FFMpegWriter(fps=10, metadata=data)
fig = plt.figure()
fig.patch.set_facecolor('black')
with writer.saving(fig, "game_of_life.mp4", 200):
    plt.spy(grid)
    plt.axis('off')
    writer.grab_frame()
    plt.clf()
    for x in life(grid, 800):
        plt.spy(x)
        plt.axis('off')
        writer.grab_frame()
        plt.clf()
