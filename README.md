# lem_in
You must move your ant colony from one point to another in the least amount of time.
Through this project, you will explore graph traversal algorithms: your program will have to choose the paths
and moves to be taken by the ants.

How to complile: gcc *.c libft/*.c -lmlx -lXext -lX11 -L ./libmlx/ -I ./libmlx/ -lm

usage: ./a.out < maps/name_of_file.txt

##visual instruction makes a visualizer of the program (it should be set in the file)

* Your program will receive the data describing the ant farm from the standard output
in the following format:

![input](https://user-images.githubusercontent.com/28359156/30077205-c82b82a8-9283-11e7-9797-8e818b78d4a4.png)

* The ant farm is defined by the following links:

![ant_farm_ex](https://user-images.githubusercontent.com/28359156/30077207-c9da1da8-9283-11e7-98f2-3620fa6cfeb5.png)

The rooms, which are defined by: name coord_x coord_y
* The links, which are defined by: name1-name2
* All of it is broken by comments, which start with '#'

* Lines that start with ## are commands modifying the properties of the line that
comes right after.
* For example, ##start signals the ant farm’s entrance and ##end its exit.
* Any non compliant or empty lines will automatically stop the ant farm’s reading
as well as the orderly processing of the acquired data.
Elementary algorithmic project lem-in
* If there isn’t enough data to process normally you must display ERROR

The goal of this project is to find the quickest way to get n ants across the farm.
* Obviously, there are some basic constraints. To be the first to arrive, ants will need
to take the shortest path (and that isn’t necessarily the simplest). They will also
need to avoid traffic jams as well as walking all over their fellow ants.
* At the beginning of the game, all the ants are in the room ##start. The goal is
to bring them to the room ##end with as few turns as possible. Each room can
only contain one ant at a time. (except at ##start and ##end which can contain
as many ants as necessary.)
* We consider that all the ants are in the room ##start at the beginning of the game.
* At each turn you will only display the ants that moved.
* At each turn you can move each ant only once and through a tube (the room at
the receiving end must be empty).
* You must to display your results on the standard output in the following format:

![ex_out](https://user-images.githubusercontent.com/28359156/30077212-cbfdb630-9283-11e7-863c-110eff6c4b35.png)

Example of program execution:

![ex_2](https://user-images.githubusercontent.com/28359156/30077358-436b656e-9284-11e7-9913-6036218cc3fe.png)

![ex_1](https://user-images.githubusercontent.com/28359156/30077357-42ef57e4-9284-11e7-884d-b3b57f38d860.png)

The visualizer of the graph:

![visual_example](https://user-images.githubusercontent.com/28359156/30077354-42af43ca-9284-11e7-8b17-449759ddb371.png)
