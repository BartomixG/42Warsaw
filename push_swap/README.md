*This project has been created as part of the 42 curriculum by bgorski.*

# Push_swap

## Description

Push_swap is a program that gives instructions on how to sort a sequence of unique integers in ascending order. Sorting algorithm is based on **Radix sort**, but during Push_swap project there are only two stacks avaliable:
- stack_a with the sequece of nubers
- stack_b as a buffer
That's why my radix algorithm must have been work in binary (base-2) representation.

---
### How does sorting algorithm work?
First of all, during the node creating process, each node has two atributes: value and position (it's a rank what the number should have in the sorted stack)*. **The algorithm doesn't work on number's values but their final position.** It saves the amount of operations when some value is greater then a size of input. Sorting begins with checking the least significant bits from each node following the rule **"if current bit equals 1 roll up the stack (ra function), but if current bit equals 0, push the number onto the top of the buffer (pb function)"**. When the algorithm checks the least significant bit of every node, it push every node from buffer to stack_a (pa function) and begin checkcking the second least significant bits. It repeats until the last most siginficant bit. For better understandig, you can analyze simplified example written below:

```bash

./push_swap 2 42 -42 4

# Stack structure at the begining

stack_a	
Value 2; Position 1
Value 42; Position 3
Value -42; Position 0
Value 4; Position 2

stack_b
EMPTY

# Look at the position values in binary (base-2) representation

1 --> 01
3 --> 11
0 --> 00
2 --> 10

# Then, look at the least significant bits. For 001 the least significant bit equals 1 so we roll up the stack and the first element becomes the last one

001 --> 1 ==> ra(stack_a);

# Current stack structure
stack_a				
Value 42; Position 3 (11)
Value -42; Position 0 (00)
Value 4; Position 2 (10)
Value 2; Position 1 (01)

stack_b
EMPTY

# Let's move to the next number. For 011 the least significant bit equals 1 so we do the roll up too.

011 --> 1 ==> ra(stack_a);

# Current stack structure
stack_a

Value -42; Position 0 (00)
Value 4; Position 2 (10)
Value 2; Position 1 (01)
Value 42; Position 3 (11)
stack_b
EMPTY

# For 000 the least significant bit equals 0 so we do push the number to the stack_b.

000--> 0 ==> pb(stack_a, stack_b);

# Current stack structure
stack_a

Value 4; Position 2 (10)
Value 2; Position 1 (01)
Value 42; Position 3 (11)

stack_b
Value -42; Position 0 (00)

# for 010 the least significant bit equals 0 so we do push the number to the stack_b too.

010--> 0 ==> pb(stack_a, stack_b);

# Current stack structure
stack_a	
Value 2; Position 1 (01)
Value 42; Position 3 (11)

stack_b
Value 4; Position 2 (10)
Value -42; Position 0 (00)

# Once we have checked each least significant bit,  we push nodes from the buffer and do the same for the most significant bits.

stack_a
Value -42; Position 0 (00)
Value 4; Position 2 (10)
Value 2; Position 1 (01)
Value 42; Position 3 (11)

stack_b
EMPTY

# 00 --> 0 ==> pb(stack_a, stack_b);

stack_a
Value 4; Position 2 (10)
Value 2; Position 1 (01)
Value 42; Position 3 (11)

stack_b
Value -42; Position 0 (00)

# 10 --> 1 ==> ra(stack_a);

stack_a
Value 2; Position 1 (01)
Value 42; Position 3 (11)
Value 4; Position 2 (10)

stack_b
Value -42; Position 0 (00)

# 01 --> 0 ==> pb(stack_a, stack_b)

stack_a
Value 42; Position 3 (11)
Value 4; Position 2 (10)

stack_b
Value 2; Position 1 (01)
Value -42; Position 0 (00)

# 11 --> 1 ==> ra(stack_a)

stack_a
Value 4; Position 2 (10)
Value 42; Position 3 (11)

stack_b
Value 2; Position 1 (01)
Value -42; Position 0 (00)

#Then we push buffer to stack_a again and we get sorted stack

stack_a
Value -42; Position 0 (00)
Value 2; Position 1 (01)
Value 4; Position 2 (10)
Value 42; Position 3 (11)

stack_b
EMPTY

# If you'd like to algorithim sort in descending order, you need to just swap the pb and ra in the condition (if 1 ==> pb and if 0 ==> ra)
```

---
## Instructions
If you want to test the algorithm, compile the project by writtng command ```make``` in the location of *Makefile* firstly.

Program accepts two varieties of input:
Classic input:
```bash
./push_swap 2 42 -42 4
```
or setting an environmental variable:
```bash
ARG="2 42 -42 4"; ./push_swap $ARG
```

---
If you want to check whether the stack is sorted, you can paste the following code into the main function in the push_swap.c file between lines ```61 head = stack_a``` and ```62 if (read)```. (Remember to recompile the program!)
```C
while (stack_a != NULL)
{
	ft_printf(": %i position: %i\n", stack_a->value, stack_a->position);
	stack_a = stack_a->next;
}
```

---
If you have you own checker, you can run it by command:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./YOUR_CHECKER $ARG
```

---
## Resources

Bitwise operators in C
https://www.geeksforgeeks.org/c/bitwise-operators-in-c-cpp/

Radix sort
https://www.geeksforgeeks.org/dsa/radix-sort/
