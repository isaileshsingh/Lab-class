import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Function to perform scaling
# Scales the points along x, y, and z axes based on the scaling factors sx, sy, sz
def scale(points, sx, sy, sz):
    scaling_matrix = np.array([
        [sx, 0, 0, 0],
        [0, sy, 0, 0],
        [0, 0, sz, 0],
        [0, 0, 0, 1]
    ])
    return apply_transformation(points, scaling_matrix)

# Function to perform translation
# Moves the points by tx, ty, tz along the x, y, and z axes respectively
def translate(points, tx, ty, tz):
    translation_matrix = np.array([
        [1, 0, 0, tx],
        [0, 1, 0, ty],
        [0, 0, 1, tz],
        [0, 0, 0, 1]
    ])
    return apply_transformation(points, translation_matrix)

# Function to perform rotation about the z-axis
# Rotates the points counterclockwise by the specified angle (in degrees) around the z-axis
def rotate_z(points, angle):
    radians = np.radians(angle)  # Converts the angle to radians since trigonometric functions use radians
    cos_a, sin_a = np.cos(radians), np.sin(radians)
    rotation_matrix = np.array([
        [cos_a, -sin_a, 0, 0],
        [sin_a, cos_a, 0, 0],
        [0, 0, 1, 0],
        [0, 0, 0, 1]
    ])
    return apply_transformation(points, rotation_matrix)

# Function to apply a transformation matrix to points
# This function uses homogeneous coordinates to perform transformations
# Homogeneous coordinates are achieved by appending a row of ones to the points array
def apply_transformation(points, transformation_matrix):
    # np.vstack combines the points array with a row of ones to create homogeneous coordinates
    homogeneous_points = np.vstack((points, np.ones((1, points.shape[1]))))
    # The @ operator performs matrix multiplication between the transformation matrix and the points
    transformed_points = transformation_matrix @ homogeneous_points
    # Returns the transformed points, excluding the homogeneous row
    return transformed_points[:3, :]

# Define the points of a square in the xy-plane
line = np.array([
    [0, 0, 5, 5],  # x-coordinates
    [0, 5, 5, 0],  # y-coordinates
    [0, 0, 0, 0]   # z-coordinates
])

# Apply transformations
scaled_line = scale(line, 2, 1, 1)  # Scales the line along x by 2, y by 1, and z by 1
translated_line = translate(line, 1, 1, 0)  # Moves the line by 1 unit along x and y
rotated_line = rotate_z(line, 45)  # Rotates the line 45 degrees around the z-axis

# Plot the original and transformed lines
fig = plt.figure(figsize=(10, 7))
ax = fig.add_subplot(111, projection='3d')

# Original line
ax.plot(line[0], line[1], line[2], label="Original Line", color="blue")

# Scaled line
ax.plot(scaled_line[0], scaled_line[1], scaled_line[2], label="Scaled Line", color="green")

# Translated line
ax.plot(translated_line[0], translated_line[1], translated_line[2], label="Translated Line", color="red")

# Rotated line
ax.plot(rotated_line[0], rotated_line[1], rotated_line[2], label="Rotated Line", color="purple")

# Set labels and legend
ax.set_xlabel("X")
ax.set_ylabel("Y")
ax.set_zlabel("Z")
ax.legend()
plt.show()
