name = input("What Is Your Full Name Sir : ")
age = int(input("What Is Your Age Sir : "))
location = input("What Is Your Location : ")
agree = input("Enter 'yes' or 'no': ").strip().lower()

if agree in ["yes", "true", "1"]:
    boolean_value = True
elif agree in ["no", "false", "0"]:
    boolean_value = False
else:
    print("Invalid input. Please enter 'yes' or 'no'.")

print("Thanks For Joining Us ")
