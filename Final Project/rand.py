import math


def next_prime(seed):
    if(seed <= 1):
        return 2
    if(seed==2):
        return 3
    if(seed%2==0):
        seed+=1
    seed += 2
    while(1):
        check = True
        for i in range(2, seed-1):
            if(seed%i==0):
                check = False
        if(check == False):
            seed+=2
        else:
            break
    return seed

def random(number_to_generate, seed):
    for i in range(number_to_generate, 0, -1):
        primed_seed = (seed*seed)+(next_prime(seed)*(seed+next_prime(seed)))*i
        while len(str(primed_seed)) < 6:
            seed = primed_seed
            primed_seed = (seed * seed) + (next_prime(seed) * (seed + next_prime(seed)))
        str_seed = str(primed_seed)
        str_seed = str_seed[len(str_seed)//2:-1*(len(str_seed)//4)]
        print(int(str_seed))
        seed = int(str_seed)
    return 0

seed = int(input("Seed please: "))
number_to_generate = int(input("How many numbers do you want to be generated? "))
random(number_to_generate, seed)
