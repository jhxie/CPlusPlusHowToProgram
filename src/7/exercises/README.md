# Knight's Tour Exercise (*7-22*)
This exercise consists of four parts; only the latter three parts are shown.

## Part B
*Tour A* starts at *D8*, *F8*, or *H8*.

![KnightsTourDirectionsA](./KnightsTourDirectionsA.jpg)

*Tour B* starts at *D8*, *E8*, or *H8*.

![KnightsTourDirectionsB](./KnightsTourDirectionsB.jpg)

The following are the two sample tours in *ASCII* output:

* [KnightsTourDirectionsA](./KnightsTourDirectionsA.txt)
* [KnightsTourDirectionsB](./KnightsTourDirectionsB.txt)

To show usage information on [7-22-B](./7-22-B.cpp):
```
7-22-B -h
```

## Part C
To see usage information on [7-22-C](./7-22-C/7-22-C.cpp):
```
7-22-C -h
```

To launch the heuristics based probing algorithm:
```
7-22-C -o heuristics.txt -t 5
```
The *heuristics.txt* that comes after the *-o* flag stands for the file name
used to record the steps taken during the knight's tour driven by
accessibility score based heuristics; the *5* that comes after the *-t* flag
stands for the number of seconds halted to show the current chessboard
and heuristics board (if **CMAKE_BUILD_TYPE=Debug** cache entry is defined).

Similarly, to play back the previously recorded steps, issue the following
command:
```
7-22-C -i heuristics.txt -t 5
```

To see whether the heuristics based probing algorithm finishes for each chessboard
position:
```
7-22-C -o tour.txt -b
```
The *tour.txt* that comes after the *-o* flag stands for the file name used to record
the completion status for each chessboard position; the *-b* flag denotes the
program currently runs in *batch* heuristics mode.

## Credits
The two sample tours are given by *Denver* on this [site][KNT].

[KNT]: https://www.chess.com/chessopedia/view/knights-tour
