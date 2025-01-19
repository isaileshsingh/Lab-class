import numpy as np
import matplotlib.pyplot as plt

# Define the line: two endpoints
point1 = np.array([1, 0, 0])  # Start of the line
point2 = np.array([0, 1, 0])  # End of the line

# Convert both points to homogeneous coordinates
homogeneous_point1 = np.append(point1, 1)
homogeneous_point2 = np.append(point2, 1)

# Rotation angle in radians (90 degrees)
theta = np.radians(90)

# Rotation matrix for Z-axis
rotation_matrix_z = np.array([
    [np.cos(theta), -np.sin(theta), 0, 0],
    [np.sin(theta), np.cos(theta),  0, 0],
    [0,             0,              1, 0],
    [0,             0,              0, 1]
])

# Rotate both endpoints
rotated_point1_homogeneous = rotation_matrix_z @ homogeneous_point1
rotated_point2_homogeneous = rotation_matrix_z @ homogeneous_point2

# Extract the rotated points (ignore the last dimension)
rotated_point1 = rotated_point1_homogeneous[:3]
rotated_point2 = rotated_point2_homogeneous[:3]

# Print results
print("Original Line Endpoints:")
print("Point 1:", point1)
print("Point 2:", point2)

print("\nRotated Line Endpoints:")
print("Point 1:", rotated_point1)
print("Point 2:", rotated_point2)

# Visualization
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot the original line
ax.plot([point1[0], point2[0]], [point1[1], point2[1]], [point1[2], point2[2]],
        label='Original Line', color='blue')

# Plot the rotated line
ax.plot([rotated_point1[0], rotated_point2[0]],
        [rotated_point1[1], rotated_point2[1]],
        [rotated_point1[2], rotated_point2[2]],
        label='Rotated Line', color='red')

# Labels and legend
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.legend()
plt.show()
