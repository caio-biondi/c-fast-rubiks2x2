# c-fast-rubiks2x2
## Basic Overview
I was motivated to work on this project as a result of a MATH397C assingment at UMass. In class we implemented the same algorithm used here which basically runs Breadth First Search oh the states of the 2x2 Rubik's Cube in Python. This guarantees the shortest solution of the cube. However we saw that our Python implementation was fairly slow. For instance some states took about a minute to be solved. Therefore, I decided to implement the algorithm in C using [uthash](https://troydhanson.github.io/uthash/) and ended up with a much faster solution. The worst case here is when we have to generate all states which should take about 20 seconds instead of one minute as it was with Python. 

## How It Works
1. The orientation of the cube will always be as decribed in the picture below, no matter which state we are dealing with. We will place green/white/red in the back.
<p align="center">
  <img src="https://github.com/caio-biondi/c-fast-rubiks2x2/blob/master/cube-orientation.jpg" alt="Cube orientation" width="500">
</p>
2. The following image, describes all the basic moves that we can apply to the cube. In all of those the lower left mini-cube in the back stays fixed and for this reason there will be only 21 permuting faces. We'll denote "UP", "RP", "FP" to be the inverses of each of their respective moves. For example, applying "U" three times is equivalent to applying "UP" one time.
<p align="center">
  <img src="https://github.com/caio-biondi/c-fast-rubiks2x2/blob/master/cube-moves.jpg" alt="Cube moves" width="500">
</p>
4. Let's number each face of the cube so that we have a way to "encode" each state. This is a particular choice that we made for the project.
<p align="center">
  <img src="https://github.com/caio-biondi/c-fast-rubiks2x2/blob/master/cube-numbers.jpg" alt="Cube numbers" width="500">
</p>

