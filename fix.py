
def operation(sign, a, b):
    tab = {
        "+": lambda a, b: a + b,
        "-": lambda a, b: a - b,
        "*": lambda a, b: a * b,
        "/": lambda a, b: a / b,
    }

    return tab[sign](a, b)

def evalFix(str, is_prefix=False): # a * b + c * d => + * a b * c d
    tab = str.split()
    stack = []

    if is_prefix: tab.reverse()

    for item in tab:
        if item.isdigit():
            stack.append(item)
        else:
            num2 = int(stack.pop())
            num1 = int(stack.pop())
            wynik = operation(item, num1, num2)
            stack.append(wynik)
    
    return stack.pop()

prefix = "+ * 1 2 * 3 4"
postfix = "10 2 * 2 2 * +"

print(evalFix(prefix, True))
print(evalFix(postfix))
