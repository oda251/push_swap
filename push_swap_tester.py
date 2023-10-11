#!/usr/local/bin/python3
import random
import subprocess
import math

rang = 6
args = []

for i in range(500):
	numlist = random.sample(range(rang), rang)
	list_str = ' '.join([str(v) for v in numlist])
	args.append(int(subprocess.run([f'./push_swap {list_str} | wc -l'], stdout=subprocess.PIPE, shell=True).stdout))
print(f'max: {max(args)}')
print(f'min: {min(args)}')
print(f'avr: {math.floor(sum(args) / len(args))}')