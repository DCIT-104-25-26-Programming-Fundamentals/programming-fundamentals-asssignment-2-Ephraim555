# def isPrime(num):
#     if num <= 1:
#                 return False
#     for i in range(2, num):
#         if (num  % i) == 0:
#             print ("Not a prime number")
#             return False
#     else:
#         print("Is a prime number")
#         return True

# print(isPrime(1))


def grade(num):
    if num > 100 or num < 0:
         return "Error: Number not in expected range"
    if 80 <= num <= 100 :
        return "A"
    elif 70 <= num < 80:
         return "B"
    elif 60 <= num < 70:
         return "C"
    elif 50 <= num < 60:
         return "D"
    else:
         return "F"

print(grade(-8))