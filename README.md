# push_swap

Push_swap is a basic approach at a sorting algorithm with various constraints.
You can only operate on two stacks. The goal is to have the first stack sorted, while the second stack must be empty by the end of the algorithm, while using the least amount of operations possible.
To do so, you have access to a number of operations :
- You can rotate a stack, moving the top element to the bottom, or putting the bottom element at the top of the stack
- You can swap the 2 elements at the top of a stack
- You can push the top element of a stack to the other stack

I solved the problem by simulating a quicksort on the two stacks. As I was limited to two seperate lists of numbers, the algorithm followed a depth-first logic rather than a breadth-first one.
While the latter is instinctively more fitting for a quicksort, it would need an ever increasing amount of lists for every split. As we are limited to two lists (represented by the two stacks), the depth-first approach allowed me to focus on a single split at every moment, in which case the two stacks sufficed.
