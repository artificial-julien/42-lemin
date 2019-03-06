# 42-project-name
Project description
## The project
## Usage
```console
make
./lem_in < maps/3-groups.map
```
## Project organisation
We are using pseudo classes of objects
## The algorithm
- Parse the input and builds a graph.
- Delete dead-ends and isolated rooms for performance.
- Builds as many combinations (groups) of paths as possible.
	Repeat :
	- Set the group limits to MIN(ANTS_COUNT, START_ROOM_CONNECTIONS, END_ROOM_CONNECTIONS).
	- Runs a breadth-first traverse and get thus the shortest traverse.
	- Updates the graph creating paths with the result traverse.
	- Create a group of paths and computes the required time.
- Select the best group (=shortest time). This may vary depending on the numbers of ants.
- Generates a solution (ant moves every turn).
- Prints the solution.

Exemples de groupes

4 routes max
Groupe 1:
	- 3
	- 3
	- 3
	- 3
Groupe 2:
	- 2
	- 4
	- 3
	- 3
