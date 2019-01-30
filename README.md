# 42-project-name
Project description
## The project
## Usage
```console
make
```
## The algorithm
- Calculer TOUTES les routes.
- Eliminer les routes d'office non pertinentes :
	Non-unique
	Traverse tout les points
- Grouper les routes non conflictuelles.
	Nombres max de routes par groupe en fonction des connections des noeuds start, end et nb ants.
- Eliminer les groupes non pertinents.


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
