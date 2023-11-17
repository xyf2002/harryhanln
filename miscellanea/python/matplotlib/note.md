# Matplotlib quick start

matplotlib works best with jupyter notebook. The examples here are tailored to matplotlib in jupyter notebook, although it probably still works with regular python interpretor.

## Quick Start

This code will create a line plot with various attributes.

```python
import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpl

# This is a matplotlib peculiarity: just include it.
fig, ax = plt.subplots()  # Create a figure containing a single axes.
ax.plot([1, 2, 3, 4], [1, 4, 2, 3], label='test', color='red')  # Plot some data on the axes.
ax.set_xlabel('x label')  # Add an x-label to the axes.
ax.set_ylabel('y label')  # Add a y-label to the axes.
ax.set_title("Simple Plot")  # Add a title to the axes.
ax.legend()  # Add a legend.
ax.show()
ax.savefig('test.png') # save the figure to file
```

If the jupyter notebook is not showing the figure, try: 

```python
%matplotlib inline
```
