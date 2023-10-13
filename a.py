import random

rang = 30
nums = random.sample(range(rang), rang)
print(' '.join([str(v) for v in nums]))