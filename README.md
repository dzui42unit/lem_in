# lem_in
You must move your ant colony from one point to another in the least amount of time.
Through this project, you will explore graph traversal algorithms: your program will have to choose 
the paths and moves to be taken by the ants.

How to compile: gcc *.c libft/*.c -lmlx -lXext -lX11 -L ./libmlx/ -I ./libmlx/ -lm

Usage: ./a.out < file_to_test

##visual will start a visualization (set it in a file)

Input file example:

![input](https://user-images.githubusercontent.com/28359156/30075981-2ee1c18c-9280-11e7-88ca-d52d3715895f.png)

The ant farm example:

![ant_farm_ex](https://user-images.githubusercontent.com/28359156/30075985-2fbff42a-9280-11e7-820e-5e6ae367d5be.png)

The rooms, which are defined by: name coord_x coord_y
* The links, which are defined by: name1-name2
* All of it is broken by comments, which start with '#'
* Lines that start with '##' are commands modifying the properties of the line that
comes right after
* For example, ##start signals the ant farm’s entrance and ##end its exit.
* Any non compliant or empty lines will automatically stop the ant farm’s reading
as well as the orderly processing of the acquired data.
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

![input](https://user-images.githubusercontent.com/28359156/30076223-e489093c-9280-11e7-88d5-804e7cb503eb.png)

![ant_farm_ex](https://user-images.githubusercontent.com/28359156/30076224-e5b8056a-9280-11e7-8609-b75744338b20.png)

![ex_out](https://user-images.githubusercontent.com/28359156/30076232-e68f1424-9280-11e7-8278-6a6844f78b4d.png)

The example of program execution:

![ex_2](https://user-images.githubusercontent.com/28359156/30076297-126a9226-9281-11e7-8e0e-fccb1e985daf.png)

![ex_1](https://user-images.githubusercontent.com/28359156/30076298-126ec954-9281-11e7-9ec3-1f41e0d5178d.png)

Visual:

![visual_example](https://user-images.githubusercontent.com/28359156/30076781-b810b2b8-9282-11e7-9aa3-6bc24b2fca68.png)


