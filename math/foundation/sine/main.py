import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 10, 100)
y = np.sin(x)

plt.plot(x, y, label='Sine Wave', color = 'blue')
plt.title("Simple Sine Wave")
plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.legend()
plt.show()