#Name: Alexander Bordenet
#Date: 10/25/25
#Purpose: A program to generate Fibonacci numbers up to a specified count.

def generateFib(count):
    fibSoFar = [0, 1]
    if count <= 0:
        return []
    elif count == 1:
        return [0]
    elif count == 2:
        return fibSoFar
    else:
        cur = 2
        while len(fibSoFar) < count:
            nextFib = fibSoFar[cur-1] + fibSoFar[cur-2]
            fibSoFar.append(nextFib)
            cur += 1

    return fibSoFar


def main():
    count = int(input("Enter the number of Fibonacci number to generate: "))
    fibNumbers = generateFib(count)
    print(f"Fibonacci numbers up to count {count}: {fibNumbers}")


main()




