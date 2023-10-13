# Quick Start for Numpy

In this document `np` is used for `numpy`.

## Array

### Array Creation

To create an array manually: `a = np.array([1, 2], [2, 3], dtype=float)`

To systematically create array, these function may be useful:

- `np.linspace(start, stop, num=50, endpoint=True, retstep=False, dtype=None, axis=0)` 
- `np.arange(start, stop, step, dtype=None)`, arrange evenly spaced array. The final element is included unless rounding errors occur. There is no endpoint options. __NOTE__ In practise the final step many times in not included.
- `np.zeros(shape, dtype=float, order='C')`
- `np.ones(shape, dtype=None, order='C')`
- `coeff_matrix = np.vstack((top, bottom))` Stack numpy arrays in sequence vertically (row wise). Note the double brackets.

### Serialisation

The numpy ndarray can be saved to a binary file with command `np.save(file:string, array:ndarray)`

### Matrix Operation

```
matA = np.array([1, 2], [2, 3], dtype=float)
matB = np.array([1, 2], [2, 3], dtype=float)
matA.T # Transpose, equivalent to a.transpose()
matA.dot(matB) # Matrix multiplication
matA@matB # Matrix multiplication
matA.matmul(matB) # Matrix multiplication
```

`*, /, +, -` are element-wise operations.

### Array Indexing

```
# Create a matrix using the np.arange and np.reshape functions
A = np.arange(1/4, 17/4, 1/4).reshape((4, 4))
print(A)

# Print some elements and slices of A
print(A[1, 3])
print(A[0, :])    # row 0, all elements
print(A[:, 2])    # all elements, column 2
print(A[2:, :-1]) # rows 2 to the last, columns 0 to the second-to-last

print(A[0::2, 1]) # every second row starting from 0, column 1
```

### np.linalg 

This package contains linear algebra functions.

- `np.linalg.inv(A)` Compute the (multiplicative) inverse of a matrix.
- `np.linalg.solve(A, b)` Solve a linear matrix equation, or system of linear scalar equations.
- `np.linalg.eig(A)` Compute the eigenvalues and right eigenvectors of a square array.



