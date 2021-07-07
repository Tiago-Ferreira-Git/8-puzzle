import random
from subprocess import call
import os
from pathlib import Path

program_name = "./main"

o = list()
#o.append("time")
#o.append("valgrind")
o.append(program_name)

string = "ABCDEFGH_"
for number_of_plays in range(0,200,1):
    checker = bool()
    final_string = ""
    random_indices = list()
    while len(random_indices) != 9:
        x = random.randint(0,8)
        for i in random_indices:
            if x == i:
                checker = True
        if checker != True:
            random_indices.append(x)
        checker = False

    for i in range(0,len(random_indices)):
        final_string += string[random_indices[i]]
    print(final_string)
    o.append(final_string)
    call(o)
    o.remove(final_string)
    print("\n\n")
    
    