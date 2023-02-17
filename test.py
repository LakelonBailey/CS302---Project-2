from random import randint
import os
import subprocess
from time import time
import sys

def run(command, input_data=None):
    kwargs = {
        'capture_output': True,
        'text': True
    }
    if input_data:
        kwargs['input'] = input_data
    result = subprocess.run(
        command.split(' '),
        **kwargs
    )
    return result.stdout

def time_command(command, input_data=None):
    start_time = time()
    run(command, input_data)
    end_time = time()
    total_time = end_time - start_time
    return f"{total_time:.4f}"

def quantities():
    return list(map(lambda n: 10**n, range(1, 8)))

def compile():
    run('make clean')
    run('make')

def create_inputs():

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

def test():
    print("|----------|----------|---------------|")
    print("|   Mode   |   Size   | Elapsed Time  |")
    print("|----------|----------|---------------|")
    sorts = ['stl', 'qsort', 'merge', 'quick']
    for sort in sorts:
        for quantity in quantities():
            input_file = f"inputs/input_{quantity}"
            quantity_str = f"{quantity:.2e}"
            with open(input_file, 'r') as f:
                time = time_command(f"./volsort -n -m {sort}", input_data=f.read())
                print(f"|{sort.upper():^10}|{quantity_str:^10}|{time:^15}|")
        print("|----------|----------|---------------|")

try:
    print('Compiling...')
    compile()
    print('Creating inputs...')
    create_inputs()
    print('Testing...')
    test()
except KeyboardInterrupt:
    print('\nStopping...')
    sys.exit()
