import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("results.csv")
df = df.sort_values("size")

plt.figure(figsize=(8, 6))

plt.plot(df['size'], df['best'], 'g')
plt.plot(df['size'], df['avg'], 'b')
plt.plot(df['size'], df['worst'], 'r')

plt.plot(df['size'], df['size'] * np.log2(df['size']), 'k--')
plt.legend(['best case', 'avg case', 'worst case', 'reference: nlogn'])
plt.title('Insertion Sort')
plt.xlabel('Input Size')
plt.ylabel('Number of Comparisons')
plt.ylim(0, 12500)
plt.xlim(0, 1000)
plt.grid()
plt.savefig('plot.png')
plt.show()
