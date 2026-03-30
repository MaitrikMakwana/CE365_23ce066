import re

# precedence of operators
precedence = {
    '+':1,
    '-':1,
    '*':2,
    '/':2,
    '^':3
}

# function to convert infix to postfix
def infix_to_postfix(expression):
    stack = []
    output = []

    tokens = re.findall(r'\d+|\+|\-|\*|\/|\^|\(|\)', expression)

    for token in tokens:

        if token.isdigit():
            output.append(token)

        elif token == '(':
            stack.append(token)

        elif token == ')':
            while stack and stack[-1] != '(':
                output.append(stack.pop())
            stack.pop()

        else:  # operator
            while (stack and stack[-1] != '(' and
                   precedence[token] <= precedence[stack[-1]]):
                output.append(stack.pop())
            stack.append(token)

    while stack:
        output.append(stack.pop())

    return output


# function to generate quadruple table
def generate_quadruple(postfix):
    stack = []
    temp_count = 1
    quadruples = []

    for token in postfix:

        if token.isdigit():
            stack.append(token)

        else:
            op2 = stack.pop()
            op1 = stack.pop()

            temp = f"t{temp_count}"
            temp_count += 1

            quadruples.append((token, op1, op2, temp))
            stack.append(temp)

    return quadruples


# main program
expr = input("Enter expression: ")

postfix = infix_to_postfix(expr)
quadruples = generate_quadruple(postfix)

print("\nQuadruple Table:")
print("Operator\tOperand1\tOperand2\tResult")

for q in quadruples:
    print(f"{q[0]}\t\t{q[1]}\t\t{q[2]}\t\t{q[3]}")