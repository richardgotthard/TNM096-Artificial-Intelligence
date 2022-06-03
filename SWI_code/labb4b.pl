:- use_module(library(clpfd)).

%constraints
table(0).
block(X) :- X in 2 \/ 3 \/ 4 \/ 6.
pyramid(X) :- X in 1 \/ 5.
orange(X) :- X in 1 \/ 4.
green(X) :- X in 2 \/ 5.
blue(X) :- X in 3 \/ 6.

%actions
act( move(X,From,To),
     [on(X,From), clear(X), clear(To)],
     [on(X,From), clear(To)],
     [on(X,To), clear(From)]
):-
block(To),
Y #\= To.

act( move_to_table(X,From),
     [on(X,From), clear(X)],
     [on(X,From)],
     [on(X,0), clear(From)]
):-
Y #\= 0.

%goal state
goal_state([on(X,Y),on(Y,Z),on(Z,0)]):-
green(Y),
blue(Z).

initial_state([
               %A
               on(1,0),
               %B
               on(2,0),
               %C
               on(3,4),
               %D
               on(4,0),
               %E
               on(5,6),
               %F
               on(6,0),

               clear(1),
               clear(2),
               clear(3),
               clear(5)
]).