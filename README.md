# c-fast-rubiks2x2
## Basic Overview
I was motivated to work on this project as a result of a MATH397C assingment at UMass. In class we implemented the same algorithm used here which basically runs Breadth First Search oh the states of the 2x2 Rubik's Cube in Python. This guarantees the shortest solution of the cube. However we saw that our Python implementation was fairly slow. For instance some states took about a minute to be solved. Therefore, I decided to implement the algorithm in C using [uthash](https://troydhanson.github.io/uthash/) and ended up with a much faster solution. The worst case here is when we have to generate all states which should take about 20 seconds instead of one minute as it was with Python. 

## How It Works
1. The orientation of the cube will always be as decribed in the picture below, no matter which state we are dealing with.
