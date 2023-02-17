from random import randint
import os
import subprocess
from time import time
import sys

# Simpler version of subprocess.run()
def run(command, input_data=None):
    kwargs = {
        'capture_output': True,
        'text': True
    }
    if input_data is not None:
        kwargs['input'] = input_data
    return subprocess.run(
        command.split(' '),
        **kwargs
    ).stdout

# Time command and return formatted time string in seconds
def time_command(command, input_data=None):
    start_time = time()
    run(command, input_data)
    end_time = time()
    total_time = end_time - start_time
    return f"{total_time:.4f}"

# Gather quantities of inputs
def quantities():
    return list(map(lambda n: 10**n, range(1, 8)))

# Clean and recreate executable
def make():
    print('Compiling...')
    run('make clean')
    run('make')

# Create input files with different quantities of numbers
def create_inputs():
    print('Creating inputs...')

    # Ensure directory exists
    if not os.path.exists("inputs"):
        os.mkdir("inputs")

    # Create input files
    for quantity in quantities():
        file_string = f"inputs/input_{quantity}"
        if os.path.exists(file_string):
            continue

        nums = list(map(lambda _: str(randint(1, 10000)), range(quantity)))
        nums_string = "\n".join(nums)
        with open(file_string, "w") as f:
            f.write(nums_string)

# Test each input file against each sorting algorithm
def test():
    print('Testing...')
    print("|----------|----------|---------------|")
    print("|   Mode   |   Size   | Elapsed Time  |")
    print("|----------|----------|---------------|")

    # Loop through sorts and quantities
    sorts = ['stl', 'qsort', 'merge', 'quick']
    for sort in sorts:
        for quantity in quantities():

            # Gather and print results
            input_file = f"inputs/input_{quantity}"
            quantity_str = f"{quantity:.2e}"
            with open(input_file, 'r') as f:
                time = time_command(f"./volsort -n -m {sort}", input_data=f.read())
                print(f"|{sort.upper():^10}|{quantity_str:^10}|{time:^15}|")

        print("|----------|----------|---------------|")

try:
    make()
    create_inputs()
    test()
except KeyboardInterrupt:
    print('\nStopping...')
    sys.exit()
