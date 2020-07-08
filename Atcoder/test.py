
import numpy as np


ans = [
  [
    [1, 2, 4],
    [5, 7, 8]
  ],
  [
    [11, 21, 42],
    [51, 72, 82]
  ]
]

ans = np.array(ans)
print(ans[:,:, 2])