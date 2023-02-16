from random import randint


for n in range(1, 8):
    quantity = 10**n
    nums = list(map(lambda _: str(randint(1, 10000)), range(quantity)))
    nums_string = "\n".join(nums)
    file_string = f"inputs/input_{quantity}"
    with open(file_string, "w") as f:
        f.write(nums_string)
