import numpy as np
import matplotlib.pyplot as plt

# Define the endpoints of the line
point1 = np.array([1, 2, 3])  # Start point of the line
point2 = np.array([4, 5, 6])  # End point of the line

# Scaling factors for x, y, z
scaling_factors = np.array([2, 0.5, 1.5])

# Convert points to homogeneous coordinates
homogeneous_point1 = np.append(point1, 1)
homogeneous_point2 = np.append(point2, 1)

# Define the scaling matrix
scaling_matrix = np.array([
    [scaling_factors[0], 0, 0, 0],
    [0, scaling_factors[1], 0, 0],
    [0, 0, scaling_factors[2], 0],
    [0, 0, 0, 1]
])

# Apply the scaling transformation to both endpoints
scaled_point1 = scaling_matrix @ homogeneous_point1
scaled_point2 = scaling_matrix @ homogeneous_point2

# Extract the scaled coordinates (ignore the last dimension)
scaled_point1 = scaled_point1[:3]
scaled_point2 = scaled_point2[:3]

# Print the results
print("Original Line Endpoints:")
print("Point 1:", point1)
print("Point 2:", point2)

print("\nScaled Line Endpoints:")
print("Point 1:", scaled_point1)
print("Point 2:", scaled_point2)

# Visualization
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Original line
ax.plot([point1[0], point2[0]], [point1[1], point2[1]], [point1[2], point2[2]], label='Original Line', color='blue')

# Scaled line
ax.plot([scaled_point1[0], scaled_point2[0]], [scaled_point1[1], scaled_point2[1]], [scaled_point1[2], scaled_point2[2]], label='Scaled Line', color='red')

# Labels and legend
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.legend()
plt.show()
