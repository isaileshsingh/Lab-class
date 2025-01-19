import numpy as np

# Original point (x, y, z)
point = np.array([2, 3, 4])

# Translation values (tx, ty, tz)
translation_values = np.array([5, -2, 3])

# Convert point to homogeneous coordinates
homogeneous_point = np.append(point, 1)

# Translation matrix
translation_matrix = np.array([
    [1, 0, 0, translation_values[0]],
    [0, 1, 0, translation_values[1]],
    [0, 0, 1, translation_values[2]],
    [0, 0, 0, 1]
])

# Apply the translation
translated_point_homogeneous = translation_matrix @ homogeneous_point

# Extract the translated point (ignore the last dimension)
translated_point = translated_point_homogeneous[:3]

# Print results
print("Original point:", point)
print("Translated point:", translated_point)
