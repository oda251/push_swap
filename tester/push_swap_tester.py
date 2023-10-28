#!/usr/local/bin/python3
import random
import os
import subprocess
import math
from colorama import Fore, Style

main_path = "./push_swap"
checker_path = "./checker"

if (not os.path.exists(main_path)):
	print(f'{main_path} does not exist')
	exit()
if (not os.path.exists(checker_path)):
	print(f'{checker_path} does not exist')
	exit()

test_times = 1000
num_size = int(input('input num_size: '))
args = []

for i in range(test_times):
	numlist = random.sample(range(num_size), num_size)
	list_str = ' '.join([str(v) for v in numlist])
	print(f'testing {i + 1} / {test_times}\t', end='')
	result = subprocess.run([f'{main_path} {list_str}'], capture_output=True, shell=True, text=True)
	c_result = subprocess.run([f'{checker_path} {list_str}'], capture_output=True, shell=True, text=True, input=result.stdout).stdout
	if not (c_result == 'OK\n' or c_result == ''):
		print("")
		print(Fore.RED + Style.BRIGHT + '[ KO detected ]' + Style.RESET_ALL + Fore.RESET)
		print(f'input: {list_str}')
		exit()
	else:
		print('\t' + Fore.GREEN + Style.BRIGHT + '[ OK ]' + Style.RESET_ALL + Fore.RESET)
	args.append(int(result.stdout.count('\n')))
print(Fore.GREEN + Style.BRIGHT + '[ ALL OK ]' + Fore.RESET + Style.RESET_ALL)
print(f'max: {max(args)}')
print(f'min: {min(args)}')
print(f'avr: {math.floor(sum(args) / len(args))}')