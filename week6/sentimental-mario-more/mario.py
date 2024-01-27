# TODO
from cs50 import get_int
def main ():

 b = True
 while b:
     n = get_int("size : ")

     if n > 0 and n < 9 :
        b = False
        PRINTBLOCKS(n)

def PRINTBLOCKS(n):

    for j in range(1,n+1,1):
        for i in range(n-j):
            print(" ",end="")

        for i in range(j):
            print("#",end="")

        print("  ",end="")
        
        for i in range(j):
            print("#",end="")
        print()
if __name__ == "__main__":
    main()







