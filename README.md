``` mermaid
flowchart TD
A[How many times will...] --> B['n' times];
A --> C[0 times];

C --> D[randomly generates 'n'];

D --> E[plays game 'n' times];
B --> E
E --> F

F[am i hungry?] --> G[kinda];
F --> yes[yes];
F --> no[no <3];

G --> J[are you feeling sweet or salty?];
J --> sweet[sweet];
J --> salty[salty];

sweet --> hq[healthy or nah?];
hq --> healthy;
hq --> nah;

healthy --> sure[are you sure about that?];
sure --> yessadly[yes sadly];
sure --> nahuright[nah u right];

yessadly --> fruit[fruit cup :<];
nahuright --> icecream[ice cream :>];

nah --> icecream;

salty --> preztels;

yes --> budget[what's your budget?];
budget --> cheap[$4];
budget --> mid[$4 - $25];
budget --> expensive[more than $25];

mid --> wendy's;

expensive --> texas[texas road house];

cheap --> water[have a nice glass of water];

no --> water
```


