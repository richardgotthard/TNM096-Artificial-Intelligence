% Describe the actions in STRIPS notation
act(go(X, Y),
    [on(floor), at(shakey, X), connected(X, Y)],
    [at(shakey, X)],
    [at(shakey, Y)]).

act(push(B, X, Y),
    [on(floor), box(B), at(B, X), at(shakey, X), connected(X, Y), light_on(X)],
    [at(B, X), at(shakey, X)],
    [at(B, Y), at(shakey, Y)]).

act(climb_up(B),
    [box(B), at(shakey, X), at(B, X), on(floor)],
    [on(floor)],
    [on(B)]).

act(climb_down(B),
    [box(B), on(B)],
    [on(B)],
    [on(floor)]).

act(turn_on(S),
    [on(B), box(B), at(B, S), connected(S, R), room(R), switch(S), light_off(R)],
    [light_off(R)],
    [light_on(R)]).

act(turn_off(S),
   [on(B), box(B), at(B, S), connected(S, R), room(R), switch(S), light_on(R)],
   [light_on(R)],
   [light_off(R)]).

% Goal state for Shakey
goal_state([
    % at(shakey, r1)
    light_off(r1)
   % at(b1, r2)
]).

% Initial state for Shakey
initial_state([
    at(shakey, r3),
    on(floor),

    light_on(r1),
    light_on(switch_1),
    light_off(r2),
    light_off(switch_2),
    light_off(r3),
    light_off(switch_3),
    light_on(r4),
    light_on(switch_4),
    light_on(corridor),

    at(b1, r1),
    at(b2, r1),
    at(b3, r1),
    at(b4, r1),

    box(b1),
    box(b2),
    box(b3),
    box(b4),

    room(r1),
    room(r2),
    room(r3),
    room(r4),

    switch(switch_1),
    switch(switch_2),
    switch(switch_3),
    switch(switch_4),

    connected(r1, switch_1),
    connected(switch_1, r1),
    connected(r2, switch_2),
    connected(switch_2, r2),
    connected(r3, switch_3),
    connected(switch_3, r3),
    connected(r4, switch_4),
    connected(switch_4, r4),

    connected(r1, corridor),
    connected(r2, corridor),
    connected(r3, corridor),
    connected(r4, corridor),
    
    connected(corridor, r1),
    connected(corridor, r2),
    connected(corridor, r3),
    connected(corridor, r4)
]).