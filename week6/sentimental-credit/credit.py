def main():
    card_number = is_numeric()
    checksum = sum(card_number)
    Card_Type(card_number, checksum)


def is_numeric():
    while True:
        number = input("Number: ")
        if number.isnumeric():
            break

    return number


def sum(card_number):
    pair_sum = 0
    impair_sum = 0
    sum=0
    card_number = reversed([int(digit) for digit in card_number])
    for i, digit in enumerate(card_number):
        if (i + 1) % 2 == 0:
            odd_digit = digit * 2
            if odd_digit > 9:
                impair_sum += int(odd_digit / 10) + odd_digit % 10
            else:
                impair_sum += odd_digit
        else:
            pair_sum += digit
    sum = pair_sum + impair_sum
    return sum


def Card_Type(card_number, checksum):
    start = int(card_number[0:2])
    lenght = len(card_number)
    checksum_last_digit = checksum % 10

    if checksum_last_digit == 0:
        if lenght == 15 and start in [34, 37] :
            print("AMEX")
        elif lenght in [13, 16] and (int(card_number[0]) == 4) :
            print("VISA")
        elif lenght == 16 and (start in range(51, 56)) :
            print("MASTERCARD")
        else:
            print("INVALID")
    else:
        print("INVALID")


main()