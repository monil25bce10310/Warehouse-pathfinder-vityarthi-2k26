# Warehouse Robot Pathfinder

A C++ project where a robot finds its way through a warehouse grid using BFS algorithm. The idea is based on how real warehouse robots work in places like Amazon and Flipkart where robots have to pick up items and deliver them while avoiding shelves and obstacles.

---

## Student Details

| Field | Details |
|---|---|
| Name | `Monil Gautam` |
| Registration Number | `25BCE10310` |
| Branch | CS core |
| Subject | Fundamentals of AI/ML (CSA2001) |
| Academic Year | 2026 |

---

## About the Project

So basically the project simulates a 10x10 warehouse grid on the terminal. The robot starts at one corner and has to reach the other end. There are obstacles placed in between which represent shelves. The BFS algorithm finds the shortest path and marks it on the grid with * symbols.

The whole thing is built in C++ using OOP concepts like classes, inheritance and references.

*This is part of my orginal project made on my offical account https://github.com/Aw1613/Warehouse-pathfinder which contains all my version history of making this project*

---

## How it works

The grid has 4 types of cells:

- `S` — where the robot starts
- `E` — where the robot has to reach
- `X` — obstacle, robot cannot go here
- `.` — free cell, robot can walk through
- `*` — the path BFS found

BFS explores the grid level by level from the start. It keeps track of which cell it came from using two parent arrays. Once it reaches E it stops and traces back the path using those arrays.

---

## Concepts Used

**OOP in C++**
- Grid, Robot and BFS are separate classes each handling their own part
- BFS inherits from Grid to access the warehouse array
- Robot holds a reference to Grid so it can read cell values

**Data Structures**
- 2D character array for the grid
- Queue with pairs for BFS traversal
- Two 2D integer arrays for path traceback (parentRow and parentCol)
- Boolean 2D array to track visited cells

---

## How to Run

```bash
g++ main.cpp -o warehouse
./warehouse
```

---

## What I learned

This project gave a good understanding of how BFS works practically and how parent arrays are used to retrace a path. It also helped a lot with understanding OOP design in C++ specifically how to properly use references and when to use inheritance vs composition.

---

## Future scope

- Add A* algorithm for smarter pathfinding
- Map randomizer that generates a new solvable map every run
- Step by step animation of robot movement
- Load maps from external text files
