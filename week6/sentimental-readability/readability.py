# TODO
from cs50 import get_string

def main ():

    #get text from user
     text = get_string("Text: ")

     no_of_letters = count_letters(text)
     no_of_words = count_words(text)
     no_of_scentences = count_scentences(text)


     l = no_of_letters* (100/ no_of_words)

     s = no_of_scentences *(100/ no_of_words)

     index =round((0.0588 * l) - (0.296 * s) - 15.8)

     if index > 16:

        print("Grade 16+")

     elif index < 1:
        print("Before Grade 1")
     else:
         print(f"Grade {index}")



#function to count no of letters
def count_letters(text):
  counter=0
  for c in text :
     # condition to count alpha only
     if c != 32 and  (c >= "a" and c <= 'z') or (c >= "A" and c <= "Z"):
       counter +=1


  return counter

#function to count no of words
def count_words( text):


     counter=1
     for c in text :
        #condition to check spaces
        if c == " ":
            counter += 1
     return counter

# function to count the no of scentences
def count_scentences (text ):
    counter=0
    for c in text :
        #condition to check . ! ?
        if c == "." or c == "?" or c == "!" :
           counter +=1
    return counter

if __name__ == "__main__":
    main()




