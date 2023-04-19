# Quick Start for Numpy

In this document `np` is used for `numpy`.

## Array

### Array Creation

- `np.linspace(start, stop, num=50, endpoint=True, retstep=False, dtype=None, axis=0)` 
- `np.arange(start, stop, step, dtype=None)` Stop is not included.
- `np.zeros(shape, dtype=float, order='C')`
- `np.ones(shape, dtype=None, order='C')`
- `coeff_matrix = np.vstack((top, bottom))` Stack numpy arrays in sequence vertically (row wise). Note the double brackets.
