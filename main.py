def isPrime(num):
    if num <= 1:
                return False
    for i in range(2, num):
        if (num  % i) == 0:
            print ("Not a prime number")
            return False
    else:
        print("Is a prime number")
        return True

print(isPrime(1))